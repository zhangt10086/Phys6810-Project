// File: CarVector.h
//
// Header file for the CarVector class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     03/27/2022:  Original version
//     04/02/2022: Added constructor for vector that uses polar coord.
//                 Added overloaded plus operator
//                 Set accessor functions as const
//
//
// Notes:
//    - The CarVector class represents a vector in cartesian coordinates
//
//
//
//
// TO DO:
//    - Add to std namespace (Either here or cpp??)
//    - Add constructor that uses PolVector object
//    - Add setVector function that uses PolVector object
//-----------------------------------------

#ifndef CARVECTOR_H
#define CARVECTOR_H

#include "PolVector.h"

class PolVector; //Forward declaration of PolVector class

class CarVector
{
 public:
  CarVector(); //Default constructor
  CarVector(double xCoord, double yCoord); //Constructor w/ parameters
  CarVector(PolVector aVector); //Constructor using vector w/ polar coord.

  //Accessor functions
  double getX() const; //Returns x coordinate
  double getY() const; //Returns y coordinate

  //Mutator functions
  void setX(double xCoord); //Sets x value to xCoord
  void setY(double yCoord); //Sets y value to yCoord

  //Overloaded operators
  friend CarVector operator+(const CarVector& aVec, const CarVector& bVec);

 private:
  double x; //X coordinate
  double y; //Y coordinate

};

#endif
