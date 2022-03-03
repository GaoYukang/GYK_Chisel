#include "VSimTop.h"
#include "verilated.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv, char** env){
    VerilatedContext* contextp = new VerilatedContext;
    unsigned int sim_time = 100;
    VSimTop* top = new VSimTop{contextp};

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("simx.vcd");
    contextp->commandArgs(argc,argv);
    unsigned int cycle = 0;
    while (contextp->time() < sim_time && !contextp->gotFinish()){
        contextp->timeInc(1);
        top->clock = 1;
        top->eval();//updates the state of the circuit
        tfp->dump(cycle++);
        top->clock = 0;
        top->eval();
        tfp->dump(cycle++);

//        printf("tick= %d \n",top->io_tick);
    }
        tfp->close();
        delete top;
        delete contextp;
        return 0;
}
