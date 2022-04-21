1. The makefile, make_potentialMapper is the makefile used to compile the potentialMapper.cpp file.
2. The potentialMapper.cpp file takes in a set of coordinates for electrons, before outputting a grid of potential values to a .dat file. In a separate .dat file, a set of electric field vectors are also generated along the equipotential lines specified in the program's code.
3. To view the equipotential map, run GNUPlot and load in the "plotPotentialMap.plt" file. This should generate an equipotential map of the electrons along with the electric field lines.
4. In addition, you can also load in the "plotPotential3D.plt" to view the potential grid in 3D. Do note that the electric field lines are not plotted in this case and that rotating the grid is very, *very* slow.


NOTES
-----

1. In the potentialMapper.cpp file, there exists a constant called FIELD_SCALE that scales up the length of all of the electric field vectors so they can be seen on the equipotential map.
2. Also in the potentialMapper.cpp file, there is a constant called POTENTIAL_SCALE that scales up the values of the potential grid. This is so that one doesn't need to write the exponents over and over again in the .plt file.
3. To set the equipotential line values, one needs to modify both the equipotential array in the potentialMapper.cpp file and the list of contour values in the plotPotentialMap.plt file.
4. Lines 101-106 of the potentialMapper.cpp file include variables that set the bounds of the grid.
