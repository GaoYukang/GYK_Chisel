pwd = $(shell pwd)
TOP_V = $(pwd)/build/SimTop.v

CPP_file = $(pwd)/sim_main.cpp


chisel:
	mill mychisel.runMain Mycounter.SimTop


cmp: $(CPP_file) $(TOP_V)
	verilator --trace --cc -exe --build   $(CPP_file) $(TOP_V)

run:
	./obj_dir/VSimTop
	
clean:
	rm -rf obj_dir simx.vcd build

all: clean chisel cmp run 

# -I$(pwd)/build