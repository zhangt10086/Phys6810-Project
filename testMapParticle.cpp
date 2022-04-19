// file: testMapParticle.cpp
//
// File to test the MapParticle and FieldVector classes
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/10/2022  Original version
//
//
//
// TO-DO:
//    
//---------------------------------------------------------
// Header files
#include "MapParticle.h"
#include "FieldVector.h"
#include <iostream>

using namespace std;

void outputFieldVector(const FieldVector &aVector);

int main() {

  MapParticle originParticle; //Electron located at origin
  
  cout << "Please input a location." << endl;

  double x, y;

  cin >> x;
  cin >> y;

  CarVector aLocation(x, y);

  double potential = originParticle.calcPotential(aLocation);

  cout << "Potential: " << potential << endl;
 

  FieldVector field = originParticle.calcElecField(aLocation);

  cout << "Field: " << endl;
  outputFieldVector(field);

  cout << "Now input location of a particle." << endl;

  cin >> x;
  cin >> y;
  aLocation.setX(x);
  aLocation.setY(y);

  MapParticle newParticle(aLocation);

  cout << "Now input new location you want to check." << endl;

  cin >> x;
  cin >> y;
  aLocation.setX(x);
  aLocation.setY(y);

  potential = newParticle.calcPotential(aLocation);

  cout << "Potential: " << potential << endl;
 

  field = newParticle.calcElecField(aLocation);

  cout << "Field: " << endl;
  outputFieldVector(field);

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
