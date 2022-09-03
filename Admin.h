/*
 * Admin.h
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#ifndef ADMIN_H_
#define ADMIN_H_

#include "UserClass.h"
#include "Flight.h"
#include "Airline.h"
#include "City.h"
#include "Country.h"

class Admin: public UserClass {
	bool loggedIn; // Security feature
public:
	Admin();
	virtual ~Admin();
	void resumeFlight(Flight);
	void blockFlight(Flight);
	void addRoute(City, Country);
	void removeRoute(City, Country);
	void setFlightSeatLimit(Flight);
	bool updateAirlineInquiryDetails(Airline);
	bool virtual validate(string, string); // Authenticator

};

#endif /* ADMIN_H_ */
