#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Vtop.h"  // create `top.v`,so use `Vtop.h`
#include "verilated.h"
 
#include "verilated_vcd_c.h" //可选，如果要导出vcd则需要加上
 
// int main(int argc, char** argv, char** env) {
 
//   VerilatedContext* contextp = new VerilatedContext;
//   contextp->commandArgs(argc, argv);
//   Vtop* top = new Vtop{contextp};
  
 
//   VerilatedVcdC* tfp = new VerilatedVcdC; //初始化VCD对象指针
//   contextp->traceEverOn(true); //打开追踪功能
//   top->trace(tfp, 0); //
//   tfp->open("wave.vcd"); //设置输出的文件wave.vcd
 
 
//   while (!contextp->gotFinish()) {
//     int a = rand() & 1;
//     int b = rand() & 1;
//     top->a = a;
//     top->b = b;
//     top->eval();
//     printf("a = %d, b = %d, f = %d\n", a, b, top->c);
 
//     tfp->dump(contextp->time()); //dump wave
//     contextp->timeInc(1); //推动仿真时间
 
//     assert(top->c == a ^ b);
//   }
//   delete top;
//   tfp->close();
//   delete contextp;
//   return 0;
// }

// #include <nvboard.h>
#include <Vtop.h>

// extern void nvboard_bind_all_pins(Vtop* top);

// void single_cycle(Vtop* top ) {
//   top->clk = 0; top->eval();
//   top->clk = 1; top->eval();
// }

// void reset(Vtop* top , int n) {
//   top->rst = 1;
//   while (n -- > 0) single_cycle( top );
//   top->rst = 0;
// }

// void 4select1(Vtop * top){
//   top->a = 0;
//   top->b = 1;
//   top->c = 2;
//   top->d = 3;
//   for(int i= 0; i<30;i++){
//       top->s = i%4;
//       top->eval();
//       if(top->o == i%4){
//           printf(" success !\n");
//       }
//       else{
//         printf("oh no \n ");
//       }
//   }
// }

//decoder
// void 4selct2(Vtop * top){
//     for(int i= 0 ; i <30;i++){

//     top->x = i%4;
//     top->en = i%1;
//     top->eval();

//     if( (i%1 && top->y != 1<<(i%4) )|| (i%1 == 0 && top->y !=0)){
//       printf("error !\n");
//     }
//     else printf("success1 !\n");
//   }

// }


void test( Vtop*p , int a , int b , int sub , int *res , int *zero , int *overflow ){

  p->a = a;
  p->b = b;
  p->sub = sub;
  p->eval();

  *zero = p->Zero;
  *overflow = p->Overflow;
  *res = p->res;
  // carry = p ->
  printf("%d %d %d %d %d %d\n" , a , b , sub , *zero , *overflow , *res);
}
#define INT_MAX 0x7fffffff


#define INT_MIN 0x80000000

int main(){

  VerilatedContext* contextp = new VerilatedContext;
  Vtop* top = new Vtop{contextp};
  // nvboard_bind_all_pins(top);
  // nvboard_init();

  int a , b , sub , zero , overflow , res ;

  test(top , 1 , INT_MIN , 0 , &zero , &overflow , &res);
  
  test(top , INT_MAX , INT_MIN , 0 , &zero , &overflow , &res);
  
  test(top , 0 , INT_MIN , 1 , &zero , &overflow , &res);

  test(top , INT_MAX , 0 , 1 , &zero , &overflow , &res);
 
  test(top , 0 , INT_MAX , 1 , &zero , &overflow , &res);

  test(top , -1 , INT_MAX , 0 , &zero , &overflow , &res);
 
}
