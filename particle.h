// File: particle.h
//
// Header file for the Particle class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     03/27/2022:  Original version
//
//     04/10/2022:  Included Coulomb's constant
//
//
// Notes:
//    - Default constructor should create a particle with a mass & charge of an electron.
//
//
//
//-----------------------------------------

#include <math.h>


#ifndef PARTICLE_H
#define PARTICLE_H

const double COULOMB = 8.988 * pow(10,9);

class Particle
{
 public:
  Particle(); //Default constructor
  Particle(double aMass, double aCharge); //Constructor for mass and charge


  //Accessor functions
  double getMass(); //Gets mass of particle
  double getCharge(); //Gets charge of particle

  //Mutator functions
  void setMass(double aMass); //Sets mass of particle to aMass
  void setCharge(double aCharge); //Sets charge of particle to aCharge

 private:

  double mass; //Mass of the particle
  double charge; //Charge of the particle
};

#endif
