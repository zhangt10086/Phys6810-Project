// File: MapParticle.h
//
// Header file for the MapParticle class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/04/2022:  Original version
//
//
// Notes:
//    
//
//
//
//-----------------------------------------

//Required header files
#include "particle.h"
#include "CarVector.h"
#include "FieldVector.h"

//-----------------------------------------

#ifndef MAPPARTICLE_H
#define MAPPARTICLE_H

class MapParticle
{
 public:
  MapParticle(); //Default constructor
  MapParticle(Particle aParticle, CarVector aLocation); //Constructor w/ params
  MapParticle(CarVector aLocation); //Constructor creating a default particle at a specific location

  //Accessor functions
  Particle getParticle() const;
  CarVector getLocation() const;

  //Mutator functions
  void setParticle(Particle aParticle); //Changes the particle
  void setVector(CarVector aLocation); //Changes the vector


  double calcPotential(CarVector aLocation); //Calculates the potential at a given location given the location's cartesian
                                           //coordinates relative to the *origin* not the particle.

  FieldVector calcElecField(CarVector aLocation); //Calculates the electric field at a given location given the location's
                                                //cartesian coordinates relative to the *origin* not the particle.


 private:

  Particle particle;
  CarVector location;
};

#endif
