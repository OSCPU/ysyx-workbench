EQY := eqy

test: nerv_synth/PASS nerv_change_fail/FAIL nerv_change_pass/PASS

nerv_synth/PASS: nerv_synth.eqy nerv.sv nerv_synth.v
	$(EQY) -f nerv_synth.eqy

nerv_change_fail/FAIL: nerv_change_fail.eqy nerv.sv nerv_change.sv
	-$(EQY) -f nerv_change_fail.eqy

nerv_change_pass/PASS: nerv_change_pass.eqy nerv.sv nerv_change.sv
	$(EQY) -f nerv_change_pass.eqy

clean:
	rm -rf nerv_synth/ nerv_change_fail/ nerv_change_pass/

.PHONY: test clean
