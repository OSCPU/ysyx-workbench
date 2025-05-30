EQY := eqy

test: spm/PASS

spm/PASS: spm.eqy spm.v spm.nl.v
	-$(EQY) -f spm.eqy

clean:
	rm -rf spm/

.PHONY: test clean
