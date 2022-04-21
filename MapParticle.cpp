// file: MapParticle.cpp
//
// Provides implementation for the MapParticle class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/04/2022  Original version
//
//     04/21/2022 Fixed field lines pointing in the wrong direction
//                under certain cases
//
//                Commented out debug output lines
//
//
// TO-DO:
//    - Implement calcPotential and calcElecField
//---------------------------------------------------------
// Header files
#include "MapParticle.h"
#include <cmath>
#include <iostream>

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



  //FOR DEBUGGING, REMOVE LATER
  /*
  std::cout << "Diff info: " << std::endl;
  std::cout << "X: " << diff.getX() << " Y: " << diff.getY() << std::endl;
  std::cout << "Radius: " << polDiff.getR() << " Theta: " << polDiff.getTheta() << std::endl;
  */

  //Electric field strength is kQ/r^2
  //double fieldStrength = COULOMB * particle.getCharge() / ( polDiff.getR() * polDiff.getR() );
  double fieldStrength = COULOMB * particle.getCharge() / (diff.getX() * diff.getX() + diff.getY() * diff.getY());

  double theta = polDiff.getTheta();

  if(fieldStrength < 0) {
    fieldStrength = fabs(fieldStrength);
    theta += M_PI;
  }

  PolVector fieldVector(fieldStrength, theta);
  FieldVector result(aLocation, fieldVector);

  return result;
}
