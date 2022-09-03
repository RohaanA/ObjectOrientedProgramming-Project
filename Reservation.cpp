/*
 * Reservation.cpp
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#include "Reservation.h"

Reservation::Reservation() {
	status = "NULL";
	seatType = "NULL";
	reservedFlightID = "NULL";
}

Reservation::Reservation(string status, string seatType, string ID) {

	this->status = status;
	this->seatType = seatType;
	reservedFlightID = ID;
}

Reservation::~Reservation() {
	// TODO Auto-generated destructor stub
}


void Reservation::blockReservation() {
	status = "BLOCKED";

}
void Reservation::removeReservation() {

}
string Reservation::getReservationStatus() {
	return status;
}
//Flight Reservation::getReservedFlight() {
//	return reservedFlight;
//}
string Reservation::getSeatType(){
	return seatType;
}
void Reservation::setReservationStatus(string st) {
	status = st;
}
//void Reservation::setReservedFlight(Flight F) {
//	reservedFlight = F;
//}
void Reservation::setSeatType(string type) {
	seatType = type;
}
void Reservation::setReservedFlightID(string ID) {
reservedFlightID = ID;
}
string Reservation::getReservedFlightID() {
return reservedFlightID;
}
void Reservation::operator=(Reservation R) {
	this->status = R.getReservationStatus();
	this->seatType = R.getSeatType();
	this->reservedFlightID = R.getReservedFlightID();
}
