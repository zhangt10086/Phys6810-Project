// file: MapParticle.cpp
//
// Provides implementation for the MapParticle class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/04/2022  Original version
//
//
//
// TO-DO:
//    - Implement calcPotential and calcElecField
//---------------------------------------------------------
// Header files
#include "MapParticle.h"

MapParticle::MapParticle() {
  Particle defaultParticle;
  CarVector defaultCarVec;

  particle = defaultParticle;
  location = defaultCarVec;
}

MapParticle::MapParticle(Particle aParticle, CarVector aLocation) {
  particle = aParticle;
  location = aLocation;
}

MapParticle::MapParticle(CarVector aLocation) {
  Particle defaultParticle;

  particle = defaultParticle;
  location = aLocation;
}

Particle MapParticle::getParticle() const {
  return particle;
}

CarVector MapParticle::getLocation() const {
  return location;
}

void MapParticle::setParticle(Particle aParticle) {
  particle = aParticle;
}

void MapParticle::setVector(CarVector aLocation) {
  location = aLocation;
}

double MapParticle::calcPotential(CarVector aLocation) {
  //Still need to test
  
  //First calculate vector from MapParticle to aLocation
  CarVector diff = aLocation - location;
  PolVector polDiff(diff); //Convert to CarVector

  //Potential is kQ/r

  double potential = COULOMB * particle.getCharge() / polDiff.getR();


  return potential;
}

FieldVector MapParticle::calcElecField(CarVector aLocation) {
  //First calculate vector from MapParticle to aLocation
  CarVector diff = aLocation - location;
  PolVector polDiff(diff); //Convert to CarVector

  //Electric field strength is kQ/r^2
  double fieldStrength = COULOMB * particle.getCharge() / ( polDiff.getR() * polDiff.getR() );

  PolVector fieldVector(fieldStrength, polDiff.getTheta());
  FieldVector result(aLocation, fieldVector);

  return result;
}