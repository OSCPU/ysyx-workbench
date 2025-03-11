#include <verilated.h>
#include "verilated_dpi.h"
//#include "VTop__Dpi.h" // 必须包含仿真器生成的头文件
#include "VTop.h"
#include "memory.cpp"
#include "fstream"
#include "iostream"
#include <getopt.h>
#include "disasm.h"
#include <verilated.h>
#include <stdio.h>
#include <cstdio>
#include <verilated_vcd_c.h>
//#include "memory.h"
#include "VTop___024root.h"
#include <verilated_fst_c.h>  // 添加Verilator FST波形头文件
VerilatedFstC* tfp = NULL;  // 波形文件指针
static bool enable_trace = false;
Memory mem;
vluint64_t main_time = 0;   // 定义 main_time 变量，用于表示仿真时间
#define MEM_BASE 0x80000000  // 代码加载到的起始地址
uint32_t npc_pc = 0;
uint32_t npc_inst = 0;
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
extern "C" void get_regs(uint32_t *regs);
static char *img_file = NULL;
  
  // DPI-C 兼容的 C 接口 
  extern "C" { 
      uint32_t mem_read(uint32_t addr) { 
          return mem.read(addr); 
      } 
   
     void mem_write(uint32_t addr, uint32_t data) { 
          mem.write(addr, data); 
     } 
  }
extern "C" void set_pc(int pc) {
	   npc_pc = pc;
}

extern "C" void set_inst(int inst) {
     npc_inst = inst;
}
extern "C" {

void dasm(char *asm_str, int size, uint32_t inst, uint32_t pc);
}
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
/*void sdb_print_registers(VTop* top) {
	    // 获取当前写使能信号和写地址

    for (int i = 0; i < 32; i++) {
        // 模拟前递逻辑：如果正在写入该寄存器，则显示即将写入的值
        uint32_t reg_val =top->rootp->Top__DOT__rf__DOT__rf[i];
        
        printf("x%d = 0x%08x\n", 
              i, 
              reg_val);
    }
}*/
void sdb_print_registers(VTop* top) {
    // RISC-V 的 32 个通用寄存器名称
    const char* reg_names[32] = {
        "zero", "ra",  "sp",  "gp",  "tp",  "t0",  "t1",  "t2",  
        "s0",   "s1",  "a0",  "a1",  "a2",  "a3",  "a4",  "a5",  
        "a6",   "a7",  "s2",  "s3",  "s4",  "s5",  "s6",  "s7",  
        "s8",   "s9",  "s10", "s11", "t3",  "t4",  "t5",  "t6"
    };

    for (int i = 0; i < 32; i++) {
        uint32_t reg_val = top->rootp->Top__DOT__rf__DOT__rf[i];
        
        printf("%-4s = 0x%08x\n", 
               reg_names[i],  
               reg_val);
    }
}
void sdb_print_memory(VTop* top, uint32_t start_addr, int n) {
    printf("Scanning memory from 0x%08x (%d words):\n", start_addr, n);

    for (int i = 0; i < n; i++) {
        uint32_t addr = start_addr + i * 4;  // 每个地址间隔 4 字节
        uint32_t value = mem.read(addr);  // 读取内存
        printf("0x%08x: 0x%08x\n", addr, value);
    }
}
void itrace_log() {
char asm_str[128]; // 存储反汇编结果
    dasm(asm_str, sizeof(asm_str), (uint32_t)npc_inst,(uint32_t)npc_pc); // 调用反汇编函数

    printf("PC: 0x%08x | INST: 0x%08x | %s\n", npc_pc, npc_inst, asm_str);
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

				
uint64_t max_cycles = 100000;  // 设置最大仿真时钟周期
 bool interactive = true;  // 是否启用单步调试
   long size= load_img();
   /* while (!Verilated::gotFinish()&& main_time < max_cycles)  {



//	std::cout << "PC:0x" << std::hex << top->pc << " Instruction: " << top->inst << std::dec << std::endl;



        // 在仿真过程中将复位信号设置为低（解除复位）
 top->clk = !top->clk;
 //      top->inst=mem.read(top->pc);
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
*/

std::string cmd;
std::cout << "Enter command (si: step, info_r: print registers, quit: exit)" << std::endl;
while (std::getline(std::cin, cmd)) {
    if (cmd == "quit" || cmd == "q") {
        break;
    } else if (cmd == "si") {
		
//		 std::cout << " PC = 0x" << std::hex << mem.read(top->pc) << std::dec << std::endl;  
		top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
    itrace_log();
    // 更新 PC 后再打印

}


				// 更新PC
//        std::cout << "Single step executed. PC = 0x" 
  //                << std::hex << top->pc << std::dec << std::endl;
     else if (cmd == "info_r") {
        // 打印寄存器状态
        sdb_print_registers(top);
    }else if(cmd.rfind("x ", 0) == 0){
				int n;
    uint32_t addr;
    
    // 解析命令格式: "x <n> <addr>"
    if (sscanf(cmd.c_str(), "x %d 0x%x", &n, &addr) == 2) {
        sdb_print_memory(top, addr, n);
    } else {
        printf("Invalid format! Use: x <count> <hex_addr>\n");
    }
		}	else {
        std::cout << "Unknown command: " << cmd << std::endl;
        std::cout << "Available commands: si, info_r, quit" << std::endl;
    }
    if (main_time >= max_cycles) {
        std::cout << "Reached max cycles." << std::endl;
        break;
    }
		if (tfp) {
            tfp->dump(main_time);
        }
}
       if (tfp) {
        tfp->close();
        delete tfp;
    } 

    
    delete top;  // 清理 Verilator 对象
    return 0;
}

