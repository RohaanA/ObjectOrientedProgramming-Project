/*
 * Admin.cpp
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#include "Admin.h"
#include <fstream>
#include <string>

Admin::Admin() {
	loggedIn = false;
	// TODO Auto-generated constructor stub

}

Admin::~Admin() {
	// TODO Auto-generated destructor stub
}


bool Admin::validate(string username, string password) {
	fstream adminFile("src/Admin.txt");
	string line;
	if (adminFile) {
		bool found = false;
		int userNameLength = username.length();
		std::cout << "Validating User Data....\n";
		// First find the relevant username in the file.
		while(getline(adminFile, line)) {
			if (line.substr(0, userNameLength) == username) {
				string actualPassword = line.substr(userNameLength+1); // Skipping the ":"
				if (password == actualPassword) {
					cout << "Password Validated.\n";
					return true;
				} else {
					cout << "Incorrect Password.\n";
					return false;
				}
			}
		}
		return found;
} else {
	cout << "Error on Admin::validate() line 26. Cannot open Admin.txt \n";
}
	return 1;
}
