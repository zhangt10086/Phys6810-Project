// file: potentialMapper.cpp
//
// File to generate .txt data for plotting equipotential lines and
// electric field lines.
//
// Programmer: Tom Zhang zhang.10086@buckeyemail.osu.edu
//
// Revision history:
//     04/19/2022  Original version
//
//     04/20/2022  Included code to skip x = 0 for grid compatibility
//                 Included additional lines for debugging
//
//     04/21/2022  Commented out debug info lines
//
//
// TO-DO:
//    
//---------------------------------------------------------
// Header files
#include "FieldVector.h"
#include "MapParticle.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

const double TOLERENCE = 1e-13; //Tolerence for us to consider to doubles to be equal.

const double FIELD_SCALE = 1.0e11; //Scale to make field vectors visible
const double POTENTIAL_SCALE = 1e10; //Scale for potential graph

inline bool isEqual(double a, double b); //Boolean function to compare whether or not a and b are equal

//Function to calculate potential at a given location given a set of particles.
double calculatePotential(vector<MapParticle> particles, CarVector location);

//Function to calculate electric field at a given location given a set of particles
FieldVector calculateField(vector<MapParticle> particles, CarVector location);

int main() {

  vector<MapParticle> particleVector;
  
  const double equipotential[] = {-1.0e-10,-2.0e-10, -3.0e-10, -4.0e-10}; //Array of our equipotential lines
  const int arrSize = 4; //Size of equipotential array

  bool doneWithInput = false;


  //Get user input on particles and their positions
  while(!doneWithInput) {

    //Query user to see if they want to add another particle
    char userSelection;
 
    cout << "Input a particle? Y/N" << endl;

    cin >> userSelection;

    doneWithInput = (userSelection == 'N' || userSelection == 'n');

    if(userSelection == 'Y' || userSelection == 'y') {
      double x, y;

      cout << "Input particle's x position." << endl;
      cin >> x;
      cout << "Input particle's y position." << endl;
      cin >> y;

      //Create new MapParticle object and push it into the vector
      CarVector particleCoord(x, y);
      MapParticle newEntry(particleCoord);
      
      particleVector.push_back(newEntry);

    }

  }


  //Create ofstream objects
  ofstream foutPotential, foutField;
  foutPotential.open("potentialGrid.dat");
  foutField.open("fieldGrid.dat");

  //Initialize headers for both files
  //foutPotential << "#x     y      V" << endl;
  //foutField << "#x    y    fieldX  fieldY" << endl;

  //Set precision on files
  foutPotential << setprecision(3);
  foutField << setprecision(3);

  //Calculate bounds of the region where we'll be plotting
  //IMPLEMENT LATER IF TIME ALLOWS, FOR NOW, ASSUME THE FOLLOWING BOUNDS

  double xMin = -20.0;
  double xMax = 20.0;
  double yMin = -20.0;
  double yMax = 20.0;

  const double STEP = 0.05;


  //Using the "grid" method, calculate potential at each point of the grid.


  for(double x = xMin; x <= xMax; x += STEP) {

    //Break for x = 0 
    //We do this because C++ outputs a number not exactly 0 for x
    //into the potentialGrid.dat file, but this breaks the grid format
    //that gnuplot requires
    //if(isEqual(x, 0.0)) {
    //continue;
    //}
    
    for(double y = yMin; y <= yMax; y += STEP) {
      
      //Need to make sure that our point isn't on top of a particle
      bool validPoint = true;
      unsigned int index = 0;
      while(validPoint && index < particleVector.size()) {
	double particleX = particleVector.at(index).getLocation().getX();
	double particleY = particleVector.at(index).getLocation().getY();

	bool sameX = isEqual(x, particleX);
	bool sameY = isEqual(y, particleY);

	validPoint = !(sameX && sameY);
	index++;
      }

      //If our point is valid, then calculate the potential at that point
      if(validPoint) {
	CarVector location(x, y);
	double potential = calculatePotential(particleVector, location);

	foutPotential << left << setw(15) << x
		      << left << setw(15) << y
		      << left << setw(15) << potential * POTENTIAL_SCALE << endl;

	//After calculating potential, loop through equipotential array to determine if we should calculate the
	//electric field also

	bool needField = false;
	int arrIndex = 0;

	while(!needField && arrIndex < arrSize) {
	 
	  needField = isEqual(potential, equipotential[arrIndex]);

	  //DEBUG INFO
	  /*
	  if(needField) {
	    cout << "Equipotential is: " << equipotential[arrIndex] << "  Potential is: " << potential << endl;
	    cout << "Difference was: " << fabs(potential - equipotential[arrIndex]) << endl;
	    cout << "X: " << x << " Y: " << y << endl;
	  }
	  */

	  arrIndex++;

	}

	if(needField) {
	  
	  FieldVector aField = calculateField(particleVector, location);
	  PolVector fieldLength = aField.getField();
	  CarVector polToCar(fieldLength);

	  //DEBUG INFO
	  /*
	  cout << "Radius: " << fieldLength.getR() << endl;
	  cout << "Angle: " << fieldLength.getTheta() << endl;
	  */

	  foutField << left << setw(15) << x
		    << left << setw(15) << y
		    << left << setw(15) << polToCar.getX() * FIELD_SCALE
		    << left << setw(15) << polToCar.getY() * FIELD_SCALE << endl;

	}
      }
    }
    
    //Make a new line
    foutPotential << endl;
  }
}


bool isEqual(double a, double b) {
  return (fabs(a-b) <= TOLERENCE);
}

double calculatePotential(vector<MapParticle> particles, CarVector location) {
  double result = 0;

  //Iterate through each particle in vector and add to result

  for(unsigned int index = 0; index < particles.size(); index++) {
    MapParticle aParticle = particles.at(index);
    double aPotential = aParticle.calcPotential(location);

    result += aPotential;
  }

  return result;
}

FieldVector calculateField(vector<MapParticle> particles, CarVector location) {
  PolVector noField(0, 0); //Initialize fieldVector with a vector of magnitude 0
  FieldVector result(location, noField);

  for(unsigned int index = 0; index < particles.size(); index++) {
    MapParticle aParticle = particles.at(index);
    FieldVector aField = aParticle.calcElecField(location);

    result = result + aField;
  }

  return result;
}
