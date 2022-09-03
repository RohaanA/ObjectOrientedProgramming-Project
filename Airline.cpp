/*
 * Airline.cpp
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#include "Airline.h"

Airline::Airline(string N, string A, string P, string L, string E) {
	name = N;
	address = A;
	phoneNo = P;
	landLine = L;
	email = E;
	// TODO Auto-generated constructor stub

}

Airline::~Airline() {
	// TODO Auto-generated destructor stub
}


void Airline::setName(string newName) {
	name = newName;
}
void Airline::setAddress(string newAddress) {
	address = newAddress;
}
void Airline::setPhoneNo(string newPhoneNo) {
	phoneNo = newPhoneNo;
}
void Airline::setLandLine(string newLandLine) {
	landLine = newLandLine;
}
void Airline::setEmail(string newEmail) {
	email = newEmail;
}
void Airline::printInquiryDetails() {
	cout << "------------------" << name << "-------------------\n";
	cout << "Telephone Number: " << landLine << endl;
	cout << "Mobile No: " << phoneNo << endl;
	cout << "Email: " << email << endl;
	cout << "----------------------------------------------------\n";
}
string Airline::getAddress() {
	return address;
}
string Airline::getPhoneNo() {
	return phoneNo;
}
string Airline::getLandLine() {
	return landLine;
}
string Airline::getName() {
	return name;
}
string Airline::getEmail() {
	return email;
}
