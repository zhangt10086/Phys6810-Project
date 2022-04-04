// File: PolVector.h
//
// Header file for the PolVector class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     03/27/2022:  Original version
//
//     04/02/2022:  Added constructor for vector using cartesian coord.
//                  Added overloaded + operator
//                  Set accessor functions as const
//
//     04/04/2022:  Added - and = operators
//
//
// Notes:
//    - The PolVector class represents a vector in polar coordinates
//    - Theta is in radians
//
//
//
// TO DO:
//    - Add to std namespace (Either here or cpp??)
//    - Add constructor that uses CarVector object
//    - Add setVector function that uses CarVector object
//-----------------------------------------

#ifndef POLVECTOR_H
#define POLVECTOR_H

#include "CarVector.h"

class CarVector; //Forward declaration of CarVector class

class PolVector
{
 public:
  PolVector(); //Default constructor
  PolVector(double rCoord, double thetaCoord); //Constructor w/ parameters
  PolVector(CarVector); //Constructor w/ CarVector

  //Accessor functions
  double getR() const; //Returns r coordinate
  double getTheta() const; //Returns theta coordinate in radians.

  //Mutator functions
  void setR(double rCoord); //Sets r value to rCoord
  void setTheta(double thetaCoord); //Sets theta value to thetaCoord

  //Overloaded operators
  friend PolVector operator+(const PolVector& aVec, const PolVector& bVec);
  friend PolVector operator-(const PolVector& aVec, const PolVector& bVec);
  friend void operator=(const PolVector& aVec);

 private:
  double r; //R coordinate
  double theta; //Theta coordinate

};

#endif
