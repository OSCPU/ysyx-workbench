#include <verilated.h>
#include "VTop.h"
#include "memory.cpp"
#include "fstream"
#include "iostream"
#include <getopt.h>

Memory mem;
#define MEM_BASE 0x80000000  // 代码加载到的起始地址
extern "C" {
    void ebreak_trigger() {
        std::cout << "EBREAK encountered, ending simulation." << std::endl;
        exit(0);  // 退出仿真
    }
}
static char *img_file = NULL;

static long load_img() {
    FILE *fp = fopen(img_file, "rb");
    if (!fp) {
        std::cerr << "Cannot open '" << img_file << "'" << std::endl;
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint32_t addr = MEM_BASE;
    uint32_t data;
    while (fread(&data, sizeof(uint32_t), 1, fp) == 1) {  
      printf("0x%08x: 0x%08x\n", addr, data);  
			mem.write(addr, data);
				//printf("0x%08x: 0x%08x\n", addr, data);  // 打印地址和对应的指令
        addr += 4;
    }
    fclose(fp);
    return size;
}


static int parse_args(int argc, char *argv[]) { 
  // 处理剩余参数
  if (optind < argc) {
    img_file = argv[optind];  // 获取第一个无选项的参数
  } 

  return 0;
}




int main(int argc, char* argv[]) {
parse_args(argc, argv);
//	printf("cncmmnm");
	if (img_file == NULL) {
        std::cerr << "Usage: " << argv[1] << " <program.bin>" << std::endl;
		//		printf("%s ",img_file);
        return 1;
    }
	//	printf("%s ",img_file);
    VTop* top = new VTop;  // 创建 Verilator 对象
    top->pc=MEM_BASE;
    // 初始化内存，假设内存地址 0x80000000 存储了一条 addi 指令
    //mem.write(0x80000000, 0x00510093);  // 这条指令是 addi 指令
	//	mem.write(0x80000004, 0x00108093);  // 这条指令是 addi 指令
	//	mem.write(0x80000008, 0x00308093);  // 这条指令是 addi 指令
	//	mem.write(0x80000012, 0x00100073);  // 这条指令是 addi 指令
   long size= load_img();

	 //assert(0);
	 //printf("sdasd");
    while (!Verilated::gotFinish())  {
        //top->eval(); // 评估 Verilog 模块
				printf("cnmcnmnsd");
 top->inst=mem.read(top->pc);
assert(0); 
//std::cout << "PC: " << std::hex << top->pc << " Instruction: " << top->inst << std::dec << std::endl;
  top->clk = !top->clk;      
     // printf("0x%08x:0x%08x\n",top->pc,top->inst);
      
				top->eval();
 //       top->pc+=4;
    }
       
    
    
    delete top;  // 清理 Verilator 对象
    return 0;
}

