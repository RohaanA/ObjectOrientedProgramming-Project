/*
 * Airline.h
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#ifndef AIRLINE_H_
#define AIRLINE_H_
#include <iostream>
using namespace std;

class Airline {
	string name;
	string address;
	string phoneNo;
	string landLine;
	string email;

public:
	Airline(string, string, string, string, string);
	virtual ~Airline();
	void setName(string newName);
	void setAddress(string newAddress);
	void setPhoneNo(string newPhoneNo);
	void setLandLine(string newLandLine);
	void setEmail(string newEmail);
	string getName();
	string getAddress();
	string getPhoneNo();
	string getLandLine();
	string getEmail();
	void printInquiryDetails();

};

#endif /* AIRLINE_H_ */
