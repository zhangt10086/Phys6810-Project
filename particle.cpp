// file: particle.cpp
//
// Provides implementation for the Particle class.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     03/27/2022  Original version
//
//     04/10/2022  Flipped the sign of ELECTRON_CHARGE and corrected magnitude
//
//
//
//---------------------------------------------------------
// Header files
#include <cmath>
#include "particle.h"

//---------------------------------------------------------

double ELECTRON_MASS = 9.11 * pow(10, -31); //In kg
double ELECTRON_CHARGE = -1.6 * pow(10, -19); //In Coulombs

Particle::Particle() {
  mass = ELECTRON_MASS;
  charge = ELECTRON_CHARGE;
}

Particle::Particle(double aMass, double aCharge) {
  mass = aMass;
  charge = aCharge;
}

double Particle::getMass() {
  return mass;
}

double Particle::getCharge() {
  return charge;
}

void Particle::setMass(double aMass) {
  mass = aMass;
}

void Particle::setCharge(double aCharge) {
  charge = aCharge;
}
