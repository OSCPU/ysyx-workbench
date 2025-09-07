EQY := eqy

test: risc16f84/FAIL

risc16f84/FAIL: risc16f84.eqy risc16f84-free.v risc16f84-in.v
	-$(EQY) -f risc16f84.eqy

clean:
	rm -rf risc16f84/

.PHONY: test clean
