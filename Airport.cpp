/*
 * Airport.cpp
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#include "Airport.h"
using namespace std;

Airport::Airport(int id, string n) {
	flightCount = 0; // By default no flights landing.
	flightsLanded = new Flight [5]; // max 5 flights can land at airport.
	name = n;
	ID = id;
}

Airport::~Airport() {
	delete[] flightsLanded; // Deleting dynamic array.
	// TODO Auto-generated destructor stub
}

