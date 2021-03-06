#set pm3d;
set hidden3d front;
#set surface;
#set nosurface; #Gets rid of the 3-D grid overlay
#set view map; #Sets birds eye view
#set contour;  #Plot contour lines
set key outside;
#set hidden3d;
#set cntrparam cubicspline #Smooth out the lines
#set cntrparam levels discrete 1.0,1.5,2.0,3.0 # Plot the selected contours

#set table $contour
#splot 'contourTest.dat'
#unset table

#set table 'contourLines.dat'
#    splot 'contourTest.dat' using 1:2:3
#unset pm3d
#unset table

#plot 'contourLines.dat', \
#     'vectorfieldTest.dat' using 1:2:3:4 w vec;

splot 'contourTest.dat' using 1:2:3, \
#     'vectorfieldTest.dat' using 1:2:3:4 w vec

#set surface
#replot 'vectorfieldTest.dat' using 1:2:3:4:5:6 w vec lc -1

#Suggestion: Save contour lines as a .dat file