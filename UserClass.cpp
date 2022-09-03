/*
 * UserClass.cpp
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#include "UserClass.h"
#include <fstream>

UserClass::UserClass() {
	// Default Constructor
	username = "";
	password = "";

}

UserClass::~UserClass() {
	// TODO Auto-generated destructor stub
}

string UserClass::getPassword() {
return password;
}
string UserClass::getUserName() {
	return username;
}
void UserClass::setPassword(string p) {
	password = p;
}
void UserClass::setUserName(string n) {
	username = n;
}
