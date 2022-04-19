// file: testMapParticle.cpp
//
// File to test generating a txt file for making a .dat file to generate
// a contour plot for GNUPlot.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/13/2022  Original version
//
//     04/15/2022  Added code to generate test contour plot.
//
//
//
// TO-DO:
//    
//---------------------------------------------------------
// Header files
#include "FieldVector.h"
#include "MapParticle.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double function(double x, double y); //Test function as a function of x and y

int main() {
  //Array of radii we'll draw
  //double radii[] = {1.0, 3.0, 4.0};

  ofstream fout, fout2;
  fout.open("contourTest.dat");
  fout2.open("vectorfieldTest.dat");


  /*
  //Loop through each radius
  //for(double radius : radii) {

    //Write header
    fout << "#Contour for radius: " << radius << endl;

    for(double theta = 0; theta <= 6.28; theta += 0.1) {
      PolVector polCoord(radius, theta); //Get vector in polar coord.

      CarVector carCoord(polCoord); //Transform to Cartesian.

      fout << carCoord.getX() << " " << carCoord.getY() << " " << radius << endl;
    }

    fout << endl;

  }
  */

  //Loop

  double xMin = -3.0;
  double xMax = 3.0;
  double yMin = -3.0;
  double yMax = 3.0;

  for(double x = xMin; x <= xMax; x += 0.1) {
    
    for(double y = yMin; y <= yMax; y += 0.1) {
      fout << x << " " << y << " " << function(x,y) << endl;

      fout2 << x << " " << y << " " << fabs(x) << " " << fabs(y) << endl;
    }

    fout << endl;
    fout2 << endl;
  }

  fout.close();
  fout2.close();
}

double function(double x, double y) {
  /*
  if( y != 0) {
    return (x*x / y);
  } else {
    return x*x;
  }
  */

  return x*x + y;
  
  
}
