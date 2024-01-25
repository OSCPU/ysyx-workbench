#include <cpu/cpu.h>

void cpu_init()
{
	top->rst=1;
	top->clk =0; top->eval();
	tfp->dump(main_time);
	main_time++;
	top->eval();
	top->clk =1; top->eval();
	top->rst=0;
	tfp->dump(main_time);
	main_time++;
	top->eval();

	
}
void cpu_exec_once(VerilatedVcdC* tfp)
{

		top->clk =0; top->eval();
		top->inst =pc_read(top->pc);
		tfp->dump(main_time);
		main_time++;
		top->eval();
		top->clk =1; top->eval();
		tfp->dump(main_time);
		main_time++;
		top->eval();


}

static void execute(uint64_t n)
{
	for(;n>0;n--)
	{
		cpu_exec_once(tfp);
		if(nemu_state.state !=NEMU_RUNNING) break;
	}
}

void cpu_exec(uint64_t n)
{
   switch (nemu_state.state) {
     case NEMU_END: case NEMU_ABORT:
       printf("Program execution has ended. To restart the program, exit npc and run again.\n");
       return;
     default: nemu_state.state = NEMU_RUNNING;
}                                                                           
	execute(n);
   switch(nemu_state.state){
     case NEMU_RUNNING: nemu_state.state =NEMU_STOP;break;

     case NEMU_END: case NEMU_ABORT:
     printf("npc: %s at pc = 0x%x\n",
     (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :        ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED)))  ,top->pc);  
     }

}


