// file: MapParticle.cpp
//
// Provides implementation for the FieldVector class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/04/2022  Original version
//
//
//
//---------------------------------------------------------
// Header files
#include "FieldVector.h"

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

PolVector FieldVector::getField() csont {
  return fieldVec;
}
