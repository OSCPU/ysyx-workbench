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
		 	//printf("writing data into memory....");
      //printf("0x%08x: 0x%08x\n", addr, data);  
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
	if (img_file == NULL) {
        std::cerr << "Usage: " << argv[1] << " <program.bin>" << std::endl;
		//		printf("%s ",img_file);
        return 1;
    }

    VTop* top = new VTop;  // 创建 Verilator 对象
													 //
    top->pc=0x80000000 ;
 top->rst = 1;  // 激活复位信号

        // 在仿真开始的几个时钟周期内保持复位信号有效
        top->clk = 0;
        top->eval();  // 执行仿真
        top->clk = 1;
        top->eval();

        // 在仿真过程中将复位信号设置为低（解除复位）
        top->rst = 0;

   long size= load_img();
    while (!Verilated::gotFinish())  {
 top->inst=mem.read(top->pc);
//	std::cout << "PC:0x" << std::hex << top->pc << " Instruction: " << top->inst << std::dec << std::endl;

    

        // 在仿真过程中将复位信号设置为低（解除复位）
 top->clk = !top->clk;      
      
				top->eval();
		//		assert(0);
    }
       
    
    
    delete top;  // 清理 Verilator 对象
    return 0;
}

