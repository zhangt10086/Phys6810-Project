set title 'Equipotential Map'
set hidden3d front;

set nosurface; #Gets rid of the 3-D grid overlay
set view map; #Sets birds eye view
set contour;  #Plot contour lines
set key outside;
#set hidden3d;
set cntrparam cubicspline #Smooth out the lines
set cntrparam levels discrete -1.0, -2.0, -3.0, -4.0 # Plot the selected contours

#Set labels
set xlabel 'X position'
set ylabel 'Y position'


#set dgrid3d
set table 'equipotentialLines.dat'
    splot 'potentialGrid.dat' using 1:2:3
unset pm3d
unset table

plot for [i=0: 3] 'equipotentialLines.dat' index i title columnhead(4) w l lw 3, \
     'fieldGrid.dat' using 1:2:3:4 w vec title 'Electric Field';
#plot 'equipotentialLines.dat' title columnheads (4), \
     #'fieldGrid.dat' using 1:2:3:4 w vec title 'Electric Field';

#set out "electronAtOrigin.ps";
#set terminal postscript color;
#replot;