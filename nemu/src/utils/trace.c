#include <common.h>
#include <elf.h>
#include <device/map.h>

#define INST_NUM 16

// iringbuf
typedef struct
{
    word_t pc;
    uint32_t inst;
}InstBuf;

InstBuf iringbuf[INST_NUM];

int cur_inst = 0;
int func_num = 0;

void trace_inst(word_t pc, uint32_t inst)
{
    iringbuf[cur_inst].pc = pc;
    iringbuf[cur_inst].inst = inst;
//		printf("%08x ",inst);
    cur_inst = (cur_inst + 1) % INST_NUM; 
}

void display_inst()
{
    /*** 注意出错的是前一条指令，当前指令可能由于出错已经无法正常译码 ***/
    int end = cur_inst;
    char buf[128];
    char *p;
    int i = cur_inst;

    if(iringbuf[i+1].pc == 0) i = 0;

    do
    {
		//	printf("%d %d %08x\n",i,end,iringbuf[i].pc);
        p = buf;
        //if(i == end) p += sprintf(buf, "-->");
        p += sprintf(buf, "%s" FMT_WORD ":  %08x\t", (i + 1) % INST_NUM == end ? "-->" : "   ", iringbuf[i].pc, iringbuf[i].inst);

        void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
        disassemble(p, buf + sizeof(buf) - p, iringbuf[i].pc, (uint8_t *)&iringbuf[i].inst, 4);

        puts(buf);
        i = (i + 1) % INST_NUM;
    } while (i != end);
     
}

