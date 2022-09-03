/*
 * Reservation.h
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#ifndef RESERVATION_H_
#define RESERVATION_H_
#include <string>
//#include "Flight.h"
using namespace std;

class Reservation {
std::string status;
std::string seatType; // BUSINESS or ECONOMY;
std::string reservedFlightID;
//Flight reservedFlight;

public:
	Reservation();
	Reservation(string, string, string);
	virtual ~Reservation();
	string getReservedFlightID();
	void setReservedFlightID(std::string ID);
	void blockReservation();
	void removeReservation();
	string getPaymentMethod();
	string getReservationStatus();
//	Flight getReservedFlight();
	string getSeatType();
	void setPaymentMethod(string p);
	void setReservationStatus(string st);
//	void setReservedFlight(Flight F);
	void setSeatType(string type);
	void operator=(Reservation R);
};

#endif /* RESERVATION_H_ */
