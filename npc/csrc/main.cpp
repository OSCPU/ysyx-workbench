#include "VTop.h"  // 包含Top模块的头文件，由Verilator自动生成
#include "verilated.h"  // Verilator的库
#include "verilated_vcd_c.h"  // VCD波形输出
#include <iostream>  // 添加标准输入输出库

#define SIM_TIME 1000  // 默认仿真时间

int main(int argc, char** argv, char** env) {
    // 初始化Verilator模拟器
    Verilated::commandArgs(argc, argv);

    // 创建Top模块实例
    VTop* top = new VTop;

    // 创建VCD输出对象，用于查看波形
    VerilatedVcdC* tfp = NULL;

    // 启用波形跟踪并打开VCD文件
    Verilated::traceEverOn(true);  // 启用波形跟踪
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  // 设置波形追踪深度为99
    tfp->open("waveform.vcd");  // 打开VCD文件

    // 初始化时钟和复位信号
    bool clk = 0;  // 时钟初始为0
    bool rst = 1;  // 复位初始为1
    top->rst = rst;

    // 仿真循环
    for (int i = 0; i < SIM_TIME; i++) {
        // 模拟时钟信号，时钟在每个时钟周期改变
        clk = !clk;
        top->clk = clk;

        // 仿真时间达到一定时刻，解除复位
        if (i > 5) {
            top->rst = 0;  // 在仿真开始后几周期解除复位
        }

        // 评估Verilog模块
        top->eval();

        // 如果启用了波形输出，保存当前时刻的波形数据
        if (tfp) {
            tfp->dump(i);  // 保存波形数据
        }
    }

    // 关闭波形文件
    if (tfp) {
        tfp->close();
        std::cout << "Waveform file closed." << std::endl;
    }

    // 清理
    delete top;
    return 0;
}
