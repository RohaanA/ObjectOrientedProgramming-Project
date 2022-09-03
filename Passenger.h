/*
 * Passenger.h
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "UserClass.h"
#include "Reservation.h"
#include <fstream>

class Passenger: public UserClass {
	int ID;
	string CNIC;
	string paymentMethod;
	string visa;
	int lastMonthFlightCount;
	bool hasReservedFlight;
	Reservation* reservedFlights;
	int reservedFlightCount;
	// TODO: Add ReservedFlight:Reservation variable.

public:
	Passenger();
	virtual ~Passenger();
	bool validate(string, string);
	bool signUp();
	int getReservedFlightCount();
	void addReservation(Reservation);
	void deleteReservation(Reservation);
	void deleteReservation(string);
	string getCNIC();
	void setCNIC(string);
	void FetchData(string username); // Used to add data of customer when logged in.
	Reservation* getReservation();
};

#endif /* PASSENGER_H_ */
