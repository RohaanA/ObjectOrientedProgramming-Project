/*
 * Flight.h
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include "Passenger.h"

class Flight {
	int MAX_PASSENGERS = 60;
	string flightID;
	std::string model;
	int passengerCount;
	Passenger* allPassengers;
	string departureTime;
	string landingTime;
	string departureLocation;
	string landingLocation;
	string connectingLocation;
	bool isConnectingFlight;
	bool flightBlocked; // If Admin decides to block flight.

public:
	Flight();
	void setMaxPassengers(int max);
	int getMaxPassengers();
	void load(string ID, std::string flightModel, int pCount, string deptTime, string landTime, string departLocation, string landLocation, string connectLocation, bool isConnecting);
	virtual ~Flight();
	void addPassenger(Passenger);
	void removePassenger(Passenger);
	const string& getConnectingLocation() const;
	void setConnectingLocation(const string &connectingLocation);
	const string& getDepartureLocation() const;
	void setDepartureLocation(const string &departureLocation);
	const string& getDepartureTime() const;
	void setDepartureTime(const string &departureTime);
	bool isFlightBlocked() const;
	void setFlightBlocked(bool flightBlocked);
	string getFlightId() const;
	void setFlightId(string flightId);
	bool isIsConnectingFlight() const;
	void setIsConnectingFlight(bool isConnectingFlight);
	const string& getLandingLocation() const;
	void setLandingLocation(const string &landingLocation);
	const string& getLandingTime() const;
	void setLandingTime(const string &landingTime);
	const std::string& getModel() const;
	void setModel(const std::string &model);
	int getPassengerCount() const;
	void setPassengerCount(int passengerCount);
	Passenger*&  getPassengers();
	void setPassengers(Passenger *&passengers);
	void display();



};

#endif /* FLIGHT_H_ */
