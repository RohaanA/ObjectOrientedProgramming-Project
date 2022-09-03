#include <iostream>
#include "Flight.h"
using namespace std;

/*
 * This function is responsible for taking proper Integer input.
 * @param item - used for displaying relevant error message.
 * @return proper int input.
 */
int inline TakeIntInput(string item) {
	int var = 0;
	for(;;) { // Infinite Loop until right input.
		if (cin >> var)
			break;

		else {
			cout << "ERROR!! Wrong Input for " << item << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	return var;
}
/*
 * This function is responsible for taking proper Integer input (with inclusive range check).
 * @param item - used for displaying relevant error message.
 * @param startRange - Define min value.
 * @param endRange - Define max value.
 * @return proper int input.
 */
int inline TakeIntInput(string item, int startRange, int endRange) {
	int var = 0;
	for(;;) { // Infinite Loop until right input.
		if (cin >> var && var >= startRange && var <= endRange)
			break;

		else {
			cout << "ERROR!! Invalid Input for " << item << endl;
			cout << "Please Enter Again." << endl;
			cout << "Input: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	return var;
}
string inline TakeStringInput(string item, int minLength) {
	string strInput;
	do {
	cout << "Input: ";
	cin >> strInput;
	if (strInput.length() < minLength) {
		cout << "ERROR!! Your input was too short for " << item << endl;
	}
	} while (strInput.length() < minLength);

	return strInput;
}

int inline getHourlyCost(Flight F) {
	// Firstly converting string hours to integers.
	int initialHours = 0;
	int landingHours = 0;
	if (F.getDepartureTime().length() < 5) // 2:00
		initialHours = F.getDepartureTime()[0] - '0';
	else initialHours = ((F.getDepartureTime()[0] - '0') * 10) + (F.getDepartureTime()[1] - '0');

	if (F.getLandingTime().length() < 5) // 2:00
		landingHours = F.getLandingTime()[0] - '0';
	else landingHours = ((F.getLandingTime()[0] - '0') * 10) + (F.getLandingTime()[1] - '0');

	if (landingHours < initialHours) {
		return ((landingHours+24)-(initialHours));
	}
	else {
		return (landingHours - initialHours);
	}


}

bool inline isVisaIssued(string username, string country) {
	bool isVisaIssued = false;
	fstream VisaFile("src/VISA.txt");
	string line;
	int usernameLength = username.length();
	if (VisaFile) {
		while(getline(VisaFile, line)) {
			if (line.substr(0, usernameLength) != username)
				continue;

			size_t pos = 0;
			string token;
			while((pos = line.find(";")) != string::npos) {
				token = line.substr(0, pos);
				if (country == token) {
					isVisaIssued = true;
					break;
				}
				line.erase(0, pos+1);
			}
			if (isVisaIssued)
				break;
		}
		VisaFile.close();
	} else cout << "ERROR!! Opening file VISA.txt";

	return isVisaIssued;
}
