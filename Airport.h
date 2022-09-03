/*
 * Airport.h
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#ifndef AIRPORT_H_
#define AIRPORT_H_
#include <iostream>
#include <string>
#include "Flight.h"


class Airport {
	Flight* flightsLanded; // Keep track of the current flights on airport.
	std::string name; // Not good practise to use std namespace in header files.
	int ID;
	int flightCount;
	public:
	Airport();
	virtual ~Airport();
	void addFlight(Flight);
	void removeFlight(Flight);
	Airport(int, std::string);

};

#endif /* AIRPORT_H_ */
