
#include "Vour.h"
#include "verilated.h"
#include <stdio.h>

int main(int argc, char **argv, char **env) {

    Verilated::commandArgs(argc, argv);
    Vour *top = new Vour;
    while (!Verilated::gotFinish())
    {

        top->a = 1;
        top->b = 0;
        top->eval();

        std::cout<<top->c<<std::endl;
    }
    delete top;
    exit(0);

}
