#set pm3d;
#set hidden3d front;
#set surface;

set key outside;
set hidden3d;
#set cntrparam cubicspline #Smooth out the lines
#set cntrparam levels discrete 1.0,1.5,2.0,3.0 # Plot the selected contours

set zrange[0:-30]

#set dgrid3d
splot 'potentialGrid.dat'