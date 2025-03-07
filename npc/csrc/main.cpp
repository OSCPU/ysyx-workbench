#include <verilated.h>
#include "VTop.h"
#include "memory.cpp"
#include "fstream"
#include "iostream"
#include <getopt.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <verilated_fst_c.h>  // 添加Verilator FST波形头文件
VerilatedFstC* tfp = NULL;  // 波形文件指针
static bool enable_trace = false;
Memory mem;
vluint64_t main_time = 0;   // 定义 main_time 变量，用于表示仿真时间
#define MEM_BASE 0x80000000  // 代码加载到的起始地址
extern "C" {
    void ebreak_trigger() {
        std::cout << "EBREAK encountered, ending simulation." << std::endl;
				if (tfp) {
            tfp->close();  // 关闭 VCD 文件
            delete tfp;    // 删除 tfp 对象，释放内存
        }
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
if (optind <  argc) {
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
	
        Verilated::traceEverOn(true);
        tfp = new VerilatedFstC;
        top->trace(tfp, 99);
        tfp->open("dump.fst");  // 生成的波形文件
    

    top->pc=0x80000000 ;
 top->rst = 1;  // 激活复位信号

        // 在仿真开始的几个时钟周期内保持复位信号有效
        top->clk = 0;
        top->eval();  // 执行仿真
        top->clk = 1;
        top->eval();
        // 在仿真过程中将复位信号设置为低（解除复位）
        top->rst = 0;
uint64_t max_cycles = 100000;  // 设置最大仿真时钟周期

   long size= load_img();
    while (!Verilated::gotFinish()&& main_time < max_cycles)  { 

		 
		
//	std::cout << "PC:0x" << std::hex << top->pc << " Instruction: " << top->inst << std::dec << std::endl;

    

        // 在仿真过程中将复位信号设置为低（解除复位）
 top->clk = !top->clk;      
       top->inst=mem.read(top->pc);  
				top->eval();
			if (tfp) {
            tfp->dump(main_time);  // 只在不同时间点 dump
            main_time++;  // 递增时间，避免 t=0 的重复 dump
        }
 
    }
       if (tfp) {
        tfp->close();
        delete tfp;
    } 

    
    
    delete top;  // 清理 Verilator 对象
    return 0;
}

