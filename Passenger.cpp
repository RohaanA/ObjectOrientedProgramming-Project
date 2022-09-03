/*
 * Passenger.cpp
 *
 *  Created on: June 18, 2021
 *      Author: M. Rohaan Atique
 */

#include "Passenger.h"
bool checkPasswordStrength(string);

Passenger::Passenger() {
	reservedFlights = nullptr;
	reservedFlightCount = 0;
	hasReservedFlight = false;
	lastMonthFlightCount = 0;
	ID = 0;
}

bool Passenger::validate(string username, string password) {
	fstream passengerFile("src/Passengers.txt");
	string line;
	if (passengerFile) {
		bool found = false;
		int userNameLength = username.length();
		std::cout << "Validating User Data....\n";
		// First find the relevant username in the file.
		while(getline(passengerFile, line)) {
			if (line.substr(14, userNameLength) == username) {
				string actualPassword = line.substr(14+userNameLength+1); // Skipping the ":"
				if (password == actualPassword) {
					cout << "Password Validated.\n";
					found = true;
					return true;
				} else {
					cout << "Incorrect Password.\n";
					return false;
				}
			}
		}
		if (!found) {
			cout << "Could not verify..please try again\n";
			return false;
		}
	} else {
		std::cout << "ERROR!! Cannot open file 'Passengers.txt'. \n";
		return false;
	}
	return false;
}
bool isCNICUnique(string CNIC) {
	string otherCNICs, line;
	// Make a while loop from 1st line to last line.
	fstream passengerFile("src/Passengers.txt");
	while(getline(passengerFile, line)) {
		otherCNICs = line.substr(0, 13);
		if (otherCNICs == CNIC) {
			return false;
		}
	return true;
	}
}
bool Passenger::signUp() {
	string CNIC, username, password, password_2;

	cout << "=====================================================\n";
	cout << "Welcome to New-Pak Airline Flight System..\n";
	cout << "Please enter your CNIC(without dash): ";
	cin >> CNIC;
	while(CNIC.length() != 13 || !isCNICUnique(CNIC)) {
		if (!isCNICUnique(CNIC))
			cout << "ERROR!! Another user has registered with this CNIC before.\n";
		else
		cout << "ERROR!! CNIC Length must be 13 digits. (without dash)\n";
		cin >> CNIC;
	}
	cout << "Please enter your preferred username: ";
	cin >> username;
	do {
		cout << "NOTE: Your password must be atleast 8 characters long and\n 1. Have an upper case\n 2. A lower case letter. \n 3. A special character. ";
		cout << "\nPlease enter password: ";
		cin >> password;
		cout << "Please re-enter password: ";
		cin >> password_2;
		if (password != password_2) {
			cout << "Passwords do not match. Please re-enter. \n";
		}
		else if (!checkPasswordStrength(password))
			cout << "Your password did not meet the minimum requirements. Please re-enter.\n";
	} while ((!checkPasswordStrength(password) || password != password_2));
	string country;
	do {cout << "Please enter the countries you're issued VISA to. Enter -1 to stop. \n";
	cout << "Country: ";
	cin >> country;
	} while (country == "-1");
	fstream VisaFile("src/VISA.txt", ios::app);
	VisaFile << endl << username << ";";
	while(country != "-1") {
		VisaFile << country << ";";
		cout << "Country: ";
		cin >> country;
	}
	if (country == "-1") {
		cout << "Thank You\n";
		VisaFile.close();
	}
	// Now that we have taken all the inputs, we just need to store them in file.
	fstream passengerFile("src/Passengers.txt", ios::app);
	if (passengerFile) {
		passengerFile << CNIC << ":" << username << ":" << password << endl;
		cout << "Congratulations! You have successfully registered.\n";
	}
	else {
		cout << "ERROR!! Passengers.cpp, line 79. Cannot open 'Passengers.txt' file. ";
		return false;
	}
	return 1;
}
string LowerCase(string str) {
	for(int i = 0; i<str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}
string UpperCase(string str) {

	for(int i = 0; i<str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}
bool specialCharCheck(string pass) {
	for(int i = 0; i<pass.length(); i++) {
		if (!((pass[i] >= 48 && pass[i] <= 57)
		   || (pass[i] >= 65 && pass[i] <= 90)
		   || (pass[i] >= 97 && pass[i] <= 122)))
			return true;
	}
	return false;
}
bool NumberCheck(string pass) {
	for(int i = 0; i<pass.length(); i++){
		if (isdigit(pass[i])) {
			return true;
		}
	}
	return false;
}
bool checkPasswordStrength(string pass) {
	// Validating the five password conditions.
	// 1. Length Check.
	if (pass.length() < 8) {
		cout << "ERROR!! Your password needs to be minimum 8 characters long.\n";
		return false;
	}
	// 2. Upper Case Letter Check.
	else if (pass == LowerCase(pass)) {
		cout << "ERROR!! Your password needs to have atleast one uppercase letter.\n";
		// 'example' turned to lowerCase will remain 'example'
		return false;
	}
	// 3. Lower Case Letter Check.
	else if (pass == UpperCase(pass)) {
		cout << "ERROR!! Your password needs to have atleast one lowercase letter.\n";
		return false;
	}
	// 4. Number Used Check.
	else if (!NumberCheck(pass)) {
		cout << "ERROR!! Your password needs to have atleast one number.\n";
		return false;
	}
	// 5. Special Character Used.
	else if (!specialCharCheck(pass)) {
		cout << "ERROR!! Your password needs to have atleast one special character.\n";
		return false;
	}
	return true;
}
void Passenger::addReservation(Reservation R) {
	if (reservedFlightCount != 0) {
		Reservation* newReserved = new Reservation [reservedFlightCount+1];
		for(int i = 0; i<reservedFlightCount; i++) {
			newReserved[i] = reservedFlights[i];
		}
		newReserved[reservedFlightCount] = R;
		reservedFlights = newReserved;
	} else {
		reservedFlights = new Reservation [1];
		reservedFlights[0] = R;
	}
	reservedFlightCount++;
}
void Passenger::deleteReservation(string ID) {
	Reservation* newRes = new Reservation [reservedFlightCount-1];
	int resCount = 0;
	for(int i = 0; i<reservedFlightCount; i++) {
		if (reservedFlights[i].getReservedFlightID() == ID) {
			continue;
		}
		newRes[i] = reservedFlights[resCount++];
	}
	reservedFlights = newRes;
	reservedFlightCount--;
}
void Passenger::FetchData(string username) {
	string line;
	int userNameLength = username.length();
	fstream passengerFile("src/passengers.txt");
	while(getline(passengerFile, line)) {
		if (line.substr(14, userNameLength) == username) {
			CNIC = line.substr(0, 13); // Loaded CNIC
		}
	}
}
//void Passenger::displayReservation() {
//	if (reservedFlightCount != 0) {
//		for(int i = 0; i<reservedFlightCount; i++) {
//			string flightID = reservedFlights[i].getReservedFlightID();
//			for(int)
//	}
//	}
//	} else {
//		cout << "ERROR!! displayReservation() called with 0 reservations.\n";
//		return;
//	}
Reservation* Passenger::getReservation() {
	return reservedFlights;
}
void Passenger::setCNIC(string c) {
	CNIC = c;
}
string Passenger::getCNIC() {
	return CNIC;
}
int Passenger::getReservedFlightCount() {
	return reservedFlightCount;
}
Passenger::~Passenger() {
	// TODO Auto-generated destructor stub
	delete[] reservedFlights;
}

