#set grid

set title '3D Potential Surface'

set key outside;
set hidden3d;
#set cntrparam cubicspline #Smooth out the lines
#set cntrparam levels discrete 1.0,1.5,2.0,3.0 # Plot the selected contours

set zrange[0:-30]

#Set labels
set xlabel 'X position'
set ylabel 'Y position'
set zlabel 'Potential'

#set dgrid3d
splot 'potentialGrid.dat' title 'Potential Surface'