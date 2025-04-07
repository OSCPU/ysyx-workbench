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
#include <elf.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <verilated_vcd_c.h>
#include "difftest.h"
//#include <klib.h>
//#include <klib-macros.h>

#define CONFIG_MBASE 0x80000000  // 示例地址
// 假设这些是你项目中定义的配置
constexpr size_t MEMORY_SIZEE = 1024;  // 4GB
#define MEM_SIZE  (128 * 1024 * 1024)  // 比如128MB内存
#define MEMORY_BASE 0x80000000         // guest侧的起始地址

uint8_t npc_memory[MEM_SIZE];

// 模拟的物理内存
#include "VTop___024root.h"
#include <verilated_fst_c.h>  // 添加Verilator FST波形头文件
VerilatedFstC* tfp = NULL;  // 波形文件指针
Memory mem;
vluint64_t main_time = 0;   // 定义 main_time 变量，用于表示仿真时间
#define MEM_BASE 0x80000000  // 代码加载到的起始地址
uint32_t npc_pc = 0;
uint32_t npc_skip = 0;
uint32_t npc_inst = 0;
difftest_memcpy_t difftest_memcpy;
difftest_regcpy_t difftest_regcpy;
difftest_exec_t  difftest_exec;
difftest_raise_intr_t difftest_raise_intr;
void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction);
void (*ref_difftest_regcpy)(void *dut, bool direction);
void (*ref_difftest_exec)(uint64_t n);
void (*ref_difftest_raise_intr)(uint64_t NO);
static inline void difftest_skip_ref() {}  ; 
CPU_state cpu;
CPU_state ref_cpu;

    const char* reg_names[32] = {
        "zero", "ra",  "sp",  "gp",  "tp",  "t0",  "t1",  "t2",  
        "s0",   "s1",  "a0",  "a1",  "a2",  "a3",  "a4",  "a5",  
        "a6",   "a7",  "s2",  "s3",  "s4",  "s5",  "s6",  "s7",  
        "s8",   "s9",  "s10", "s11", "t3",  "t4",  "t5",  "t6"
    };

bool isa_difftest_checkregs(const CPU_state *ref, const CPU_state *dut) {
  if (ref->pc != dut->pc) return false;
  for (int i = 0; i < 32; i++) {
    if (ref->gpr[i] != dut->gpr[i])
      return false;
  }
  return true;
}
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
      uint32_t mem_read(uint32_t raddr) { 
          
				return mem.pmem_read(raddr); 
      } 
   
     void mem_write(uint32_t waddr, uint32_t wdata,int wmask) { 
          mem.pmem_write(waddr, wdata, wmask); 
     } 

  }
extern "C" void set_pc(int pc) {
	   npc_pc = pc;
}
extern "C" void set_skip(int skip) {
	   npc_skip = skip;
}
extern "C" void set_inst(int inst) {
     npc_inst = inst;
}

extern "C" {
// 初始化动态库链接

void dasm(char *asm_str, int size, uint32_t inst, uint32_t pc);
}
/////////////////////////////////////////////////////////////////////////////////加载程序img_file,同时加载difftest的内存//////////////
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
			mem.pmem_write(addr, data, 15);
	//		printf("Copying data to NEMU: addr = 0x%08x, data = 0x%08x, size = %zu\n", addr, data, sizeof(data));
		//	ref_difftest_memcpy(addr , &data,sizeof(data),DIFFTEST_TO_REF);
				//printf("0x%08x: 0x%08x\n", addr, data);  // 打印地址和对应的指令
        addr += 4;
    }
    fclose(fp);
    return size;
}

////////////////////////////////////////////////////////////////////////初始化difftest，difftest的比较逻辑和打印函数///////////////////////////////////////
/*void init_difftest() {
  void *handle = dlopen("/home/jason/ssh/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to open shared library: " << dlerror() << std::endl;
        assert(handle);  // 确保打开成功，否则终止
    } else {
        std::cout << "Shared library opened successfully!" << std::endl;
    }
// 获取并转换为正确的函数指针类型
     ref_difftest_memcpy = (void (*)(paddr_t, void*, size_t, bool)) dlsym(handle, "difftest_memcpy");
if (!ref_difftest_memcpy) {
        std::cerr << "Failed to find 'difftest_memcpy' function: " << dlerror() << std::endl;
        assert(ref_difftest_memcpy);  // 确保获取成功
    } else {
        std::cout << "'difftest_memcpy' function loaded successfully!" << std::endl;
    }

     ref_difftest_regcpy = (void (*)(void*, bool)) dlsym(handle, "difftest_regcpy");

     ref_difftest_exec = (void (*)(uint64_t)) dlsym(handle, "difftest_exec");
if (!ref_difftest_exec) {
        std::cerr << "Failed to find 'difftest_exec' function: " << dlerror() << std::endl;
        assert(ref_difftest_exec);  // 确保获取成功
    } else {
        std::cout << "'difftest_exec' function loaded successfully!" << std::endl;
    }
    auto ref_difftest_raise_intr = (void (*)(uint64_t)) dlsym(handle, "difftest_raise_intr");
		if (!ref_difftest_raise_intr) {
        std::cerr << "Failed to find 'difftest_raise_intr' function: " << dlerror() << std::endl;
        assert(ref_difftest_raise_intr);  // 确保获取成功
    } else {
        std::cout << "'difftest_raise_intr' function loaded successfully!" << std::endl;
    }
}
// 比较两个CPU状态，不匹配返回1，否则返回0
int compare_cpu_state() {
    int mismatch = 0;
    if (cpu.pc != ref_cpu.pc) {
        printf("Mismatch: PC: DUT = 0x%08x, REF = 0x%08x\n", cpu.pc, ref_cpu.pc);
        mismatch = 1;
    }
    for (int i = 0; i < 32; i++) {
        if (cpu.gpr[i] != ref_cpu.gpr[i]) {
					 printf("Mismatch: PC: DUT = 0x%08x, REF = 0x%08x\n", (cpu.pc-4), (ref_cpu.pc-4));
            printf("Mismatch: Register %-4s: DUT = 0x%08x, REF = 0x%08x\n", reg_names[i], cpu.gpr[i], ref_cpu.gpr[i]);
            mismatch = 1;
        }
    }
    return mismatch;
}
void print_cpu_state() {
    int i;
    printf("---- DUT CPU State ----\n");
    printf("PC: 0x%08x\n", cpu.pc-4);
    for (i = 0; i < 32; i++) {
        printf("%-4s: 0x%08x\n", reg_names[i], cpu.gpr[i]);
    }
    printf("---- REF CPU State ----\n");
    printf("PC: 0x%08x\n", ref_cpu.pc-4);
    for (i = 0; i < 32; i++) {
        printf("%-4s: 0x%08x\n", reg_names[i], ref_cpu.gpr[i]);
    }
}
*/

//////////////////////////////////////////////////////////解析img——file////////////////////////
static int parse_args(int argc, char *argv[]) { 
  // 处理剩余参数
if (optind <  argc) {
      img_file = argv[optind];  // 获取第一个无选项的参数
    }   
  return 0;
}

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
///////////////////////////////////////////////////////////////////sdb 以及 寄存器打印 以及内存打印（dpi-c）机制////////////////
void print_ref_memory(uint8_t* ref_memory, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("ref_memory[%zu]: %08x\n", i, ref_memory[i]);
    }
}
void sdb_print_memory(VTop* top, uint32_t start_addr, int n) {//读取不太需要对齐，写入需要严格按照对齐，一般出现高位或者低位乱码不需要太在意,因为不是按照对齐读的可能会读到其它信息，
    printf("Scanning memory from 0x%08x (%d words):\n", start_addr, n);

    for (int i = 0; i < n; i++) { 
        uint32_t addr = start_addr + i * 4;  // 每个地址间隔 4 字节
				
        uint32_t value = mem.pmem_read(addr);  // 读取内存
        printf("0x%08x: 0x%08x\n", addr, value);
    }
}
void itrace_log() {
char asm_str[128]; // 存储反汇编结果
    dasm(asm_str, sizeof(asm_str), (uint32_t)npc_inst,(uint32_t)npc_pc); // 调用反汇编函数

    printf("PC: 0x%08x | INST: 0x%08x | %s\n", npc_pc, npc_inst, asm_str);
}
/////////////////////////////////////////////////////////////////////////////////////主函数/////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
	//init_difftest(); 
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
    
///////////////////////////////////////////////////rst初始化始终同步///////
    top->pc=0x80000000 ;
		top->rst=1;
		top->eval();
		top->rst=0;
		top->eval();
			
		
				
uint64_t max_cycles = 1000000;  // 设置最大仿真时钟周期
 bool interactive = true;  // 是否启用单步调试
   long size= load_img();
	 ////////////////////////////////////////////////////////初始化difftest的ref寄存器//////////////
	/* for(int i=0;i<32;i++)
 	 {
		 cpu.gpr[i]= top->rootp->Top__DOT__rf__DOT__rf[i];
	 }
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);*/
	
	 //   print_ref_memory(ref_memory, size);
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
    }else if(cmd == "c"){
			 while(1){
 top->clk = 1;
        top->eval();  // 执行一时钟周期
       // if (tfp) tfp->dump(main_time++);

        top->clk = 0;
        top->eval();  // 执行另一时钟周期
     //   if (tfp) tfp->dump(main_time++);
//				vga_update_screen();

			 }
		}	
		else if (cmd.substr(0,2) == "si") {
			int n=1;
			if (cmd.length() > 3) { // 判断是否带参数
        n = std::stoi(cmd.substr(3)); // 解析 n
    } 
			  for (int step = 0; step < n; step++) {
		 
		top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
    //itrace_log();
		/*cpu.pc=top->pc;
		for(int i=0;i<32;i++)
		{ 
      cpu.gpr[i]= top->rootp->Top__DOT__rf__DOT__rf[i];
    }
 for (int i = 0; i < 32; i++) {
     printf("%-4s: 0x%08x ", reg_names[i], cpu.gpr[i]);
     if (i % 4 == 3) {
       printf("\n");  // 每 4 个寄存器换行
      }
 }
 if(npc_skip==1){

	 printf("entering the fucking devices");
	 ref_difftest_regcpy(&cpu,DIFFTEST_TO_REF);
 npc_skip=0; 
 printf("%8x",cpu.pc);
printf("%8x",ref_cpu.pc);

 }else{
//	 printf("%8x",cpu.pc);
// printf("%8x",ref_cpu.pc);

ref_difftest_exec(1);
//printf("%8x",cpu.pc);
// printf("%8x",ref_cpu.pc); 
	ref_difftest_regcpy(&ref_cpu,DIFFTEST_TO_DUT);
//	printf("%8x",cpu.pc);
//  printf("%8x",ref_cpu.pc); 
	 printf("REF Register state (after regcpy):\n");
  for (int i = 0; i < 32; i++) {
    printf("%-4s: 0x%08x ", reg_names[i], ref_cpu.gpr[i]);
    if (i % 4 == 3) {
      printf("\n");  // 每 4 个寄存器换行
     }
  }
if (compare_cpu_state()) {
                printf("DiffTest mismatch detected!\n");
                print_cpu_state();
                exit(1);
            } else {
                printf("DiffTest check passed.\n");
            }
 }	*/
	   
			 }
				
}
     else if (cmd == "info_r") {
        // 打印寄存器状态
        sdb_print_registers(top);
    }else if(cmd.rfind("x ", 0) == 0){
				int n;
    uint32_t addr;
   // int  rmask;  // 增加一个 rmask 变量
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

