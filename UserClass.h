/*
 * UserClass.h
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */
#include <string>
#include <iostream>
using namespace std;

#ifndef USERCLASS_H_
#define USERCLASS_H_

class UserClass {
	string username;
	string password;
public:
	UserClass();
	virtual ~UserClass();
	string getUserName();
	string getPassword();
	void setUserName(string);
	void setPassword(string);
	// Pure Virtual Function as class is abstract
	bool virtual validate(string, string) = 0;
};

#endif /* USERCLASS_H_ */
