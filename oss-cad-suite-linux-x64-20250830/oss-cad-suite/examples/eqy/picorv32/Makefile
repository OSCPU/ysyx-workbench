help:
	@echo ""
	@echo "make prove_vivado"
	@echo "make prove_modified"
	@echo "  run the formal equivalence proofs"
	@echo ""
	@echo "make vcdmatch"
	@echo "  re-generate vcdmatch.out"
	@echo ""
	@echo "make vivado"
	@echo "  re-run vivado synthesis"
	@echo ""
	@echo "make clean"
	@echo "  remove temporary output files"
	@echo ""

prove_vivado: picorv32_vivado.eqy picorv32_vivado.v picorv32_modified.v
	eqy -fj6 picorv32_vivado.eqy

prove_modified: picorv32_modified.eqy picorv32_modified.v picorv32.v
	eqy -fj6 picorv32_modified.eqy

test_gold.vcd: test_gold firmware.hex
	vvp -N test_gold

test_gate.vcd: test_gate firmware.hex
	vvp -N test_gate

netlists.d/partition.log: picorv32_modified.v picorv32_vivado.v picorv32_vivado.eqy
	eqy -fmj6 -d netlists.d picorv32_vivado.eqy

test_gold_uut.v: netlists.d/partition.log
	yosys -qo test_gold_uut.v netlists.d/gold.il

test_gate_uut.v: netlists.d/partition.log
	yosys -qo test_gate_uut.v netlists.d/gate.il

test_gold: testbench.v test_gold_uut.v
	iverilog -o test_gold -D GOLD testbench.v test_gold_uut.v

test_gate: testbench.v test_gate_uut.v
	iverilog -o test_gate testbench.v test_gate_uut.v

vcdmatch: test_gold.vcd test_gate.vcd
	python3 vcdmatch.py | tee vcdmatch.out

vivado:
	rm -f picorv32_vivado.log
	bash -c ". /opt/Xilinx/Vivado/2021.2/settings64.sh; vivado -mode batch -nojournal -log picorv32_vivado.log -source picorv32_vivado.tcl"

check_module: netlists.d/partition.log
	cp -r netlists.d/. $@.d
	sed '/Fragment-Partition-Matrix:/,/^$$/!d;' $@.d/partition.log
	cd $@.d/modules && sby -f picorv32.sby

check_%: netlists.d/partition.log
	cp -r netlists.d/. $@.d
	sed '/Fragment-Partition-Matrix:/,/^$$/!d;' $@.d/partition.log
	cd $@.d/partitions && sby -f picorv32.$(subst check_,,$@).sby

prove_%: netlists.d/partition.log
	cp -r netlists.d/. $@.d
	sed '/Fragment-Partition-Matrix:/,/^$$/!d;' $@.d/partition.log
	cd $@.d/strategies/picorv32.$(subst prove_,,$@)/pdr* && sby -f picorv32.$(subst prove_,,$@).sby

watch:
	@while \
		files=`sh -c 'fuser */strategies/*/*/*/logfile.txt' 2>&1 | cut -f1 -d: | sed "s,^$$PWD/,,"`; \
		test -n "$$files"; \
	do \
		clear; \
		! timeout 30 tail -vfn4 `ls -rt $$files`; \
	done


show_partition_list:
	sed 's/ : / :\n/' picorv32_vivado/partition.list | fold -s | sed '/ :/ ! s/^/  /'

show_partition_matrix:
	sed '/^Partition.Summary:/,/^$$/!d;' picorv32_vivado/partition.log

show_partition_sizes:
	jq -c '{(input_filename): {gold_cells: .gold_module.cellcount, gate_cells: .gate_module.cellcount}}' picorv32_vivado/modules/picorv32.json picorv32_vivado/partitions/*.json

show_partition_runtimes:
	grep -h Elapsed.clock picorv32_vivado/strategies/*/*/*/logfile.txt | gawk '{print$$10,$$3;}' | sort
	grep -h Elapsed.proc picorv32_vivado/strategies/*/*/*/logfile.txt | gawk '{print$$10,$$3;}' | sort

clean:
	rm -f test_gold.vcd test_gate.vcd test_gold test_gate
	rm -f init_gold.vcd init_gate.vcd vcdmatch.out
	rm -rf picorv32_vivado picorv32_modified
