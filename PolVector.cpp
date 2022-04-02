// file: PolVector.cpp
//
// Provides implementation for the PolVector class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     03/27/2022  Original version
//     04/02/2022  Implemented constructor for CarVector
//                 Implemented + operator
//                 Modified accesor functions to be const
//
//
//
// TO DO:
//    - Add to std namespace (Either here or header??)
//    - Auto convert theta so between 0 and 2pi radians??
//---------------------------------------------------------
// Header files
#include <cmath>
#include "PolVector.h"
//---------------------------------------------------------

PolVector::PolVector() {
  r = 0;
  theta = 0;
}

PolVector::PolVector(double rCoord, double thetaCoord) {
  r = rCoord;
  theta = thetaCoord;
}

PolVector::PolVector(CarVector aVector) {

  double xSquared= aVector.getX() * aVector.getX();
  double ySquared = aVector.getY() * aVector.getY();

  r = sqrt(xSquared + ySquared); //r = sqrt(x^2 + y^2)
  theta = atan( (aVector.getY() / aVector.getX()) ); //theta = arctan(y/x)

}

double PolVector::getR() const {
  return r;
}

double PolVector::getTheta() const {
  return theta;
}

void PolVector::setR(double rCoord) {
  r = rCoord;
}

void PolVector::setTheta(double thetaCoord) {
  theta = thetaCoord;
}

PolVector operator+(const PolVector& aVec, const PolVector& bVec) {
  CarVector aCar(aVec);
  CarVector bCar(bVec);
  CarVector carSum(aCar + bCar);

  PolVector polSum(carSum);

  return polSum;
}
