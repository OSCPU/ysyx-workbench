EQY := eqy

test: aliases/PASS combine/PASS counter/PASS ex_amend/PASS ex_bind/PASS ex_group/PASS ex_join/PASS fsm/PASS hierarchy/PASS submodules/PASS

aliases/PASS: aliases.eqy aliases.sv
	$(EQY) -f aliases.eqy

combine/PASS: combine.eqy combine.sv
	$(EQY) -f combine.eqy

counter/PASS: counter.eqy counter.sv
	$(EQY) -f counter.eqy

ex_amend/PASS: ex_amend.eqy ex_amend.sv
	$(EQY) -f ex_amend.eqy

ex_bind/PASS: ex_bind.eqy ex_bind.sv
	$(EQY) -f ex_bind.eqy

ex_group/PASS: ex_group.eqy ex_group.sv
	$(EQY) -f ex_group.eqy

ex_join/PASS: ex_join.eqy ex_join.sv
	$(EQY) -f ex_join.eqy

fsm/PASS: fsm.eqy fsm.sv
	$(EQY) -f fsm.eqy

hierarchy/PASS: hierarchy.eqy hierarchy.sv
	$(EQY) -f hierarchy.eqy

submodules/PASS: submodules.eqy submodules.sv
	$(EQY) -f submodules.eqy

clean:
	rm -rf aliases/ combine/ counter/ ex_amend/ ex_bind/ ex_group/ ex_join/ fsm/ hierarchy/ submodules/

.PHONY: test clean
