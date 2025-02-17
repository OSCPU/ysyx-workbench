#include <verilated.h>
#include "VTop.h"
#include "memory.cpp"

Memory mem;
int main(int argc, char** argv) {
    VTop* top = new VTop;  // 创建 Verilator 对象
    top->pc=0x80000000;
    // 初始化内存，假设内存地址 0x80000000 存储了一条 addi 指令
    mem.write(0x80000000, 0x00110093);  // 这条指令是 addi 指令
    
    // 模拟开始
    for (int i = 0; i < 10; i++) {
        top->eval(); // 评估 Verilog 模块

       
      top->inst=mem.read(top->pc);
      printf("0x%08x:0x%08x\n",top->pc,top->inst);
      
        // 更新时钟
        top->clk = !top->clk;
        top->pc+=4;
    }
       
    
    
    delete top;  // 清理 Verilator 对象
    return 0;
}

