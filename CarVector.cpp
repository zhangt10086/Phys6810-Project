// file: CarVector.cpp
//
// Provides implementation for the CarVector class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     03/27/2022  Original version
//     04/02/2022  Implemented Constructor that uses PolVector
//                 Implemented + operator
//                 Modified accessor functions to be const
//
//
//
// TO DO:
//    - Add to std namespace (Either here or header??)
//---------------------------------------------------------
// Header files
#include <cmath>
#include "CarVector.h"

//---------------------------------------------------------

CarVector::CarVector() {
  x = 0;
  y = 0;
}

CarVector::CarVector(double xCoord, double yCoord) {
  x = xCoord;
  y = yCoord;
}

CarVector::CarVector(PolVector aVector) {
  x = aVector.getR() * cos(aVector.getTheta()); //x = r * cos(theta)
  y = aVector.getR() * sin(aVector.getTheta()); //x = r * sin(theta)
}

double CarVector::getX() const {
  return x;
}

double CarVector::getY() const {
  return y;
}

void CarVector::setX(double xCoord) {
  x = xCoord;
}

void CarVector::setY(double yCoord) {
  y = yCoord;
}

CarVector operator+(const CarVector& aVec, const CarVector& bVec) {
  double xSum = aVec.getX() + bVec.getX();
  double ySum = aVec.getY() + bVec.getY();

  CarVector sum(xSum, ySum);

  return sum;
}
