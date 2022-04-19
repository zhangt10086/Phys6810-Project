#set pm3d;
set hidden3d front;
#set surface;
set nosurface; #Gets rid of the 3-D grid overlay
set view map; #Sets birds eye view
set contour;  #Plot contour lines
set key outside;
#set hidden3d;
set cntrparam cubicspline #Smooth out the lines
set cntrparam levels discrete -1.0e-10,-1.25e-10, -1.5e-10, -1.75e-10, -2.0e-10, -2.25e-10, -2.5e-10, -2.75e-10, \
    -3.0e-10 -3.25e-10, -3.50e-10, -3.75e-10, \
    -4.0e-10, -4.25e-10, -4.5e-10 # Plot the selected contours


set dgrid3d
set table 'equipotentialLines.dat'
    splot 'potentialGrid.dat' using 1:2:3
unset pm3d
unset table

plot 'equipotentialLines.dat', \
     'fieldGrid.dat' using 1:2:3:4 w vec;

#set surface
#replot 'vectorfieldTest.dat' using 1:2:3:4:5:6 w vec lc -1

#Suggestion: Save contour lines as a .dat file