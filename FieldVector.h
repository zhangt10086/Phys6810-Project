// File: FieldVector.h
//
// Header file for the FieldVector class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/04/2022:  Original version
//
//     04/10/2022:  Added terminating #endif
//
//     04/19/2022:  Added + operator and mutator for field data member
//
//
// Notes:
//    - The FieldVector class has two data members, a
//    vector in cartesian coordinates denoating the location of the vector,
//    and a vector in polar coordinates denoting the actual vector.
//
//
//
//-----------------------------------------
//Required header files
#include "PolVector.h"
#include "CarVector.h"

//-----------------------------------------

#ifndef FIELDVECTOR_H
#define FIELDVECTOR_H

// A/N:Honestly, perhaps this would've been better as
//     a stuct rather than a class?

class FieldVector
{
 public:
  FieldVector(); //Default constructor
  FieldVector(CarVector aLocation, PolVector aFieldVec); //Constructor w/ params

  //Accessor functions
  CarVector getLocation() const; //Returns the location of the field vector
  PolVector getField() const; //Returns the field vector

  //Mutator functions
  void setField(PolVector aVector); //Sets the field vector

  //Overloaded operators
  friend FieldVector operator+(const FieldVector& aVec, const FieldVector& bField);

 private:
  CarVector location;
  PolVector fieldVec;
};

#endif
