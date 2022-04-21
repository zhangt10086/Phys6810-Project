// file: MapParticle.cpp
//
// Provides implementation for the FieldVector class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/04/2022  Original version
//
//     04/10/2022  Fixed minor misspelling of "const"
//
//     04/19/2022  Implemented + operator and setField()
//
//
//
//---------------------------------------------------------
// Header files
#include "FieldVector.h"

using namespace std;

FieldVector::FieldVector() {
  CarVector defaultCar;
  PolVector defaultPol;

  location = defaultCar;
  fieldVec = defaultPol;

}

FieldVector::FieldVector(CarVector aLocation, PolVector aFieldVec) {
  location = aLocation;
  fieldVec = aFieldVec;
}

CarVector FieldVector::getLocation() const {
  return location;
}

PolVector FieldVector::getField() const {
  return fieldVec;
}

void FieldVector::setField(PolVector aVector) {
  fieldVec = aVector;
}

FieldVector operator+(const FieldVector& aVec, const FieldVector& bVec) {
  PolVector newField = aVec.getField() + bVec.getField();

  FieldVector sum = FieldVector(aVec.getLocation(), newField);

  return sum;
}
