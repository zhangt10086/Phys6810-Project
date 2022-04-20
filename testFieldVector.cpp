// file: testFieldVector.cpp
//
// File to test the + operator for the FieldVector class
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/20/2022  Original version
//
//
//
// TO-DO:
//    
//---------------------------------------------------------
// Header files
#include "FieldVector.h"
#include <iostream>

using namespace std;

void outputFieldVector(const FieldVector &aVector);

int main() {

  FieldVector vector1;
  
  cout << "Please input a location." << endl;

  double x, y;

  cin >> x;
  cin >> y;

  CarVector aLocation(x, y);

  //Second, test creating a PolVector object and converting CarVector to PolVector
  double r, theta;

  cout << "Enter radius of new vector" << endl;
  cin >> r;
  cout << "Enter angle of new vector" << endl;
  cin >> theta;

  PolVector firstRadius(r, theta);

  cout << "Enter radius of new vector" << endl;
  cin >> r;
  cout << "Enter angle of new vector" << endl;
  cin >> theta;

  PolVector secondRadius(r, theta);

  FieldVector firstField = FieldVector(aLocation, firstRadius);
  FieldVector secondField = FieldVector(aLocation, secondRadius);

  FieldVector sum = firstField + secondField;

  outputFieldVector(sum);


  return 0;
}

void outputFieldVector(const FieldVector &aVector) {
  CarVector location = aVector.getLocation();
  PolVector field = aVector.getField();

  cout << "Location:" << endl;
  cout << "X: " << location.getX() << endl;
  cout << "Y: " << location.getY() << endl;

  cout << "Field info:" << endl;
  cout << "Magnitude: " << field.getR() << endl;
  cout << "Angle: " << field.getTheta() << endl;
}
