#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <verilated.h>
#include <verilated_vcd_c.h>

#define MAX_SIM_TIME 300
#define VERIF_START_TIME 7
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

class dut_in_tx {
public:
	uint32_t in_1;
	uint32_t in_2;
	enum operation {
	}op;
}

class dut_out_tx {
public:
	uint32_t out_1;

}

class dut_scb
{
private:
	//定义了一个输入FIFO，用于以FIFO形式储存输入的变量
	std::deque<dut_in_tx*> in_fifo;

public:
	//将输入的数据写入FIFO和检测写出FIFO
	void write_in(dut_in_tx* tx) {
		in_fifo.push_back(tx);
	}	
	void write_out(dut_in_tx* tx) {
		if (in_fifo.empty()){
			std::cout << "Fatal Error in dut_scb: "
			<<"empty dut_in_tx queue" << std::endl;
			exit(1);
		}

		dut_in_tx* in;
		in = in_fifo.front();
		in_fifo.pop_front();
	
	//检测预期输出和实际输出时候相符	
	//下方函数功能为：将in_monitor和out_monitor的值相比较，看是否符合预期
		switch(in->op) {


		}
		delete in;
		delete dut_in_tx;
	}
};

class dut_in_drv
{
private:
	Vdut *dut;
public:
	dut_in_drv(Vdut* dut){
		this->dut = dut;
	}

	void drive(dut_in_tx* tx){
	//默认为输入为无效输入
		dut->in_valid = 0;
	//当Transacter给出一个Transaction且操作数并不为空时
	//认为当前输入为有效输入，in_valid置1
	//下方函数功能为：将FIFO输入与实例DUT的接口连接
		if (tx != NULL){
			if (tx->op != dut_in_tx::nop){
			
			}
			delete tx;	
		}
	}
};

class dut_in_mon{
private:
	Vdut* dut;
	dut_scb *scb;
public:
	dut_in_mon(Vdut* dut, dut_scb* scb){
		this->dut = dut;
		this->scb = scb;
	}

	void monitor(){
		//当驱动函数认为接收到了有效输入后, 创建一个transaction
		//并将驱动函数的输出存储并传递给scoreboard
		//下方函数功能为：将in_FIFO输入赋值到Monitor中
		if (dut->in_valid == 1)
		{
			dut_in_tx* tx = new	dut_in_tx();

			scb->write_in(tx);
		}
	}
};

class dut_out_mon{
private:
	Vdut* dut;
	dut_scb *scb;
public:
	dut_out_mon(Vdut* dut, dut_scb* scb){
		this->dut = dut;
		this->scb = scb;
	}

	void monitor(){
		//当驱动函数认为接收到了有效输出后, 创建一个transaction
		//并将驱动函数的输出存储并传递给scoreboard
		//下方函数功能为：将out_FIFO输入赋值到Monitor中
		if (dut->out_valid == 1)
		{
			dut_out_tx* tx = new dut_out_tx();

			scb->write_out(tx);
		}
	}
};

int main(int argc, char const *argv[])
{
    srand (time(NULL));
    Verilated::commandArgs(argc, argv);
    Vdut *dut = new Vdut;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    dutInTx   *tx;

    // Here we create the driver, scoreboard, input and output monitor blocks
    dut_in_drv  *drv    = new dut_in_drv(dut);
    dut_scb    *scb    = new dut_scb();
    dut_in_mon  *inMon  = new dut_in_mon(dut, scb);
    dut_out_mon *outMon = new dut_out_mon(dut, scb);

    while (sim_time < MAX_SIM_TIME) {
        dut_reset(dut, sim_time);
        dut->clk ^= 1;
        dut->eval();

        // Do all the driving/monitoring on a positive edge
        if (dut->clk == 1){

            if (sim_time >= VERIF_START_TIME) {
                // Generate a randomised transaction item of type dutInTx
                tx = rnddutInTx();

                // Pass the transaction item to the dut input interface driver,
                // which drives the input interface based on the info in the
                // transaction item
                drv->drive(tx);

                // Monitor the input interface
                inMon->monitor();

                // Monitor the output interface
                outMon->monitor();
            }
        }
        // end of positive edge processing

        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    delete outMon;
    delete inMon;
    delete scb;
    delete drv;
    exit(EXIT_SUCCESS);
}
