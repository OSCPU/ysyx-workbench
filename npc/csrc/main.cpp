
#include "verilated.h"
#include "Vtop.h"
#include <stdio.h>
#include <iostream>
int main(int argc, char **argv, char **env) {

    VerilatedContext* contextp = new VerilatedContext;

    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    // This needs to be called before you create any model
    contextp->commandArgs(argc, argv);

    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    Vtop* top = new Vtop{contextp};

    while (!Verilated::gotFinish())
    {

        top->a = 1;
        top->b = 0;
        top->eval();

        // std::cout<<top->c<<std::endl;
    }
    delete top;
    exit(0);

}
