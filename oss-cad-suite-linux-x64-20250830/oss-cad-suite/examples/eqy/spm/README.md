# Pre- and Post-Synthesis Equivalence Checking of an OpenLANE SkyWater130 Netlist with EQY

In this example, the RTL of a very small design is compared to the post-synthesis netlist output by the SkyWater130 OpenLANE flow.

- ``spm.v``: the original RTL
- ``spm.nl.v``: the final post-synthesis netlist found in ``results/final/verilog``
- ``primitives.v`` and ``sky130_fd_sc_hd.v``: the cell library simulation models from the SkyWater130 PDK
- ``formal_pdk_proc.py``: a small preprocessing script that makes the simulation models parsable for yosys
