// File: testVector.cpp
//
// File to test the CarVector and PolVector classes
//
// Revision history:
//     04/02/2022: Original version
//
//
// Notes:
//
//
// TO DO:
//
//
//
//-----------------------------------------

#include "CarVector.h"
#include "PolVector.h"
#include <iostream>

using namespace std;

int main() {

  //First, test creating a CarVector object and converting CarVector to PolVector

  double x, y;

  //Grab user input for vector
  cout << "Enter x length of vector" << endl;
  cin >> x;
  cout << "Enter y length of vector" << endl;
  cin >> y;

  CarVector firstCarVec(x, y);
  PolVector carToPol(firstCarVec);

  cout << "x length of vector is " << firstCarVec.getX() << endl;
  cout << "y length of vector is " << firstCarVec.getY() << endl;
  cout << "Radius of vector is " << carToPol.getR() << endl;
  cout << "Angle between y and x is " << carToPol.getTheta() << endl;

  //Second, test creating a PolVector object and converting CarVector to PolVector
  double r, theta;

  cout << "Enter radius of new vector" << endl;
  cin >> r;
  cout << "Enter angle of new vector" << endl;
  cin >> theta;

  PolVector aPolVec(r, theta);
  CarVector polToCar(aPolVec);

  cout << "x length of vector is " << polToCar.getX() << endl;
  cout << "y length of vector is " << polToCar.getY() << endl;
  cout << "Radius of vector is " << aPolVec.getR() << endl;
  cout << "Angle between y and x is " << aPolVec.getTheta() << endl;

  return 0;
}
