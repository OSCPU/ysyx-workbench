#include <verilated.h>
#include "VTop.h"
#include "memory.cpp"

Memory mem;

extern "C" {
    void ebreak_trigger() {
        std::cout << "EBREAK encountered, ending simulation." << std::endl;
        exit(0);  // 退出仿真
    }
}

int main(int argc, char** argv) {
    VTop* top = new VTop;  // 创建 Verilator 对象
    top->pc=0x80000000;
    // 初始化内存，假设内存地址 0x80000000 存储了一条 addi 指令
    mem.write(0x80000000, 0x00510093);  // 这条指令是 addi 指令
		mem.write(0x80000004, 0x00108093);  // 这条指令是 addi 指令
		mem.write(0x80000008, 0x00308093);  // 这条指令是 addi 指令
		mem.write(0x80000012, 0x00100073);  // 这条指令是 addi 指令
    
    // 模拟开始
    while (!Verilated::gotFinish())  {
        //top->eval(); // 评估 Verilog 模块
 top->inst=mem.read(top->pc);    
//std::cout << "PC: " << std::hex << top->pc << " Instruction: " << top->inst << std::dec << std::endl;
  top->clk = !top->clk;      
    //  printf("0x%08x:0x%08x\n",top->pc,top->inst);
        // 更新时钟
  
				top->eval();
 //       top->pc+=4;
    }
       
    
    
    delete top;  // 清理 Verilator 对象
    return 0;
}

