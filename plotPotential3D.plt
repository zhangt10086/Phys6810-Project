set pm3d;
#set hidden3d front;
#set surface;
#set nosurface; #Gets rid of the 3-D grid overlay
#set view map; #Sets birds eye view
set contour;  #Plot contour lines
set key outside;
#set hidden3d;
#set cntrparam cubicspline #Smooth out the lines
#set cntrparam levels discrete 1.0,1.5,2.0,3.0 # Plot the selected contours


set dgrid3d
splot 'potentialGrid.dat'