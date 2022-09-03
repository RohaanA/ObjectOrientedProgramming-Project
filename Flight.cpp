/*
 * Flight.cpp
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#include "Flight.h"
void Flight::load(string ID, std::string flightModel, int pCount, string deptTime, string landTime, string departLocation, string landLocation, string connectLocation, bool isBlocked) {
flightID = ID;

model = flightModel;
passengerCount = pCount;
departureTime = deptTime;
landingTime = landTime;
departureLocation = departLocation;
landingLocation = landLocation;
connectingLocation = connectLocation;
//passengers = nullptr;
isConnectingFlight = 0;
flightBlocked = isBlocked; // By default no flight is disabled.
}

Flight::Flight() {
flightID = "-1";
model = "NULL";
passengerCount = -1;
landingTime = "";
departureLocation = "";
landingLocation = "";
connectingLocation = "";
//passengers = nullptr;
isConnectingFlight = "";
flightBlocked = false; // By default no flight is disabled.
}

Flight::~Flight() {
	// TODO Auto-generated destructor stub
}


const string& Flight::getConnectingLocation() const {
	return connectingLocation;
}

void Flight::setConnectingLocation(const string &connectingLocation) {
	this->connectingLocation = connectingLocation;
}

const string& Flight::getDepartureLocation() const {
	return departureLocation;
}

void Flight::setDepartureLocation(const string &departureLocation) {
	this->departureLocation = departureLocation;
}

const string& Flight::getDepartureTime() const {
	return departureTime;
}

void Flight::setDepartureTime(const string &departureTime) {
	this->departureTime = departureTime;
}

bool Flight::isFlightBlocked() const {
	return flightBlocked;
}

void Flight::setFlightBlocked(bool flightBlocked) {
	this->flightBlocked = flightBlocked;
}

string Flight::getFlightId() const {
	return flightID;
}

void Flight::setFlightId(string flightId) {
	flightID = flightId;
}

bool Flight::isIsConnectingFlight() const {
	return isConnectingFlight;
}

void Flight::setIsConnectingFlight(bool isConnectingFlight) {
	this->isConnectingFlight = isConnectingFlight;
}

const string& Flight::getLandingLocation() const {
	return landingLocation;
}

void Flight::setLandingLocation(const string &landingLocation) {
	this->landingLocation = landingLocation;
}

const string& Flight::getLandingTime() const {
	return landingTime;
}

void Flight::setLandingTime(const string &landingTime) {
	this->landingTime = landingTime;
}

const std::string& Flight::getModel() const {
	return model;
}

void Flight::setModel(const std::string &model) {
	this->model = model;
}

int Flight::getPassengerCount() const {
	return passengerCount;
}

void Flight::setPassengerCount(int passengerCount) {
	this->passengerCount = passengerCount;
}

//Passenger*& Flight:: getPassengers() {
//	return passengers;
//}
//
//void Flight::setPassengers( Passenger *&passengers) {
//	this->passengers = passengers;
//}
void Flight::display() {
	if (model.length() < 11)
		model += " ";

	cout << flightID << "  ";
	cout << model << "  ";
	if (MAX_PASSENGERS-passengerCount < 10)
	cout << "0";
	cout << MAX_PASSENGERS-passengerCount << "         ";
	if (departureTime.length() < 5)
		cout << "0";
	cout << departureTime << "      ";
	if (landingTime.length() < 5)
		cout << "0";
	cout << landingTime << "       ";
	cout << departureLocation << "      ";
	if (departureLocation.length() < 19)
		for(int i = 0; i<19-departureLocation.length(); i++)
		cout << " ";
	cout << landingLocation << "      ";
	if (landingLocation.length() < 19)
		for(int i = 0; i<19-landingLocation.length(); i++)
		cout << " ";
	cout << connectingLocation << "         ";
	string isFlightBlocked = flightBlocked ? "Yes" : "No";
	cout << isFlightBlocked << endl;
}

int Flight::getMaxPassengers() {
	return MAX_PASSENGERS;
}
void Flight::setMaxPassengers(int max) {
	MAX_PASSENGERS = max;
}
