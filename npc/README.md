Chisel Project Template
=======================

Another version of the [Chisel template](https://github.com/ucb-bar/chisel-template) supporting mill.
mill is another Scala/Java build tool without obscure DSL like SBT. It is much faster than SBT.

Contents at a glance:

* `.gitignore` - helps Git ignore junk like generated files, build products, and temporary files.
* `build.sc` - instructs mill to build the Chisel project
* `Makefile` - rules to call mill
* `playground/src/GCD.scala` - GCD source file
* `playground/src/DecoupledGCD.scala` - another GCD source file
* `playground/src/Elaborate.scala` - wrapper file to call chisel command with the GCD module
* `playground/test/src/GCDSpec.scala` - GCD tester

Feel free to rename or delete files under `playground/` or use them as a reference/template.

## Getting Started

First, install mill by referring to the documentation [here](https://com-lihaoyi.github.io/mill).

To run all tests in this design (recommended for test-driven development):
```bash
make test
```

To generate Verilog:
```bash
make verilog
```

## Change FIRRTL Compiler

You can change the FIRRTL compiler between SFC (Scala-based FIRRTL compiler) and
MFC (MLIR-based FIRRTL compiler) by modifying the `useMFC` variable in `playground/src/Elaborate.scala`.
The latter one requires `firtool`, which is included under `utils/`.
