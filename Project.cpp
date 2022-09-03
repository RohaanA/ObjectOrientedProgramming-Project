//============================================================================
// Name        : Project.cpp
// Author      : M. Rohaan Atique
// Version     :
// Copyright   : Your copyright notice
// Description : OOP Project Main File
//============================================================================

#include <iostream>
#include <string>
#include <conio.h>
#include "Passenger.h"
#include "Admin.h"
#include "MyUtils.cpp"
using namespace std;

void loadFlightData(Flight* allFlights, int MAX_FLIGHTS) {
	// Before Displaying, I will need to load all the data.
	// Loading DATA

	for(int i = 0; i<MAX_FLIGHTS; i++) {
		fstream flightData("src/Flights.txt");
		if (flightData) {

			string line;
			string ID, model, deptTime, landTime, departLocation, landLocation,connectLocation;
			int pCount; bool isBlocked;
			while(getline(flightData, line)) {
				string delimiter = ";";
				string token;
				size_t pos = 0;
				int counter = 0;
				while((pos = line.find(delimiter)) != std::string::npos) {

					token = line.substr(0, pos);
					switch(counter) {
					case 0:
						ID = token; break;
					case 1:
						model = token; break;
					case 2:
						pCount = ((token[0]-'0') * 10) + (token[1] - '0') ; break;
					case 3:
						deptTime = token; break;
					case 4:
						landTime = token; break;
					case 5:
						departLocation = token; break;
					case 6:
						landLocation = token; break;
					case 7:
						connectLocation = token; break;
					}
					line.erase(0, pos + delimiter.length());
					counter++;
					if (counter == 8){ // All Loaded.
						isBlocked = line[0] - '0';
						allFlights[i++].load(ID, model, pCount, deptTime, landTime, departLocation, landLocation, connectLocation, isBlocked);

					}
				}
				isBlocked = 0;
				}
			flightData.close();
			break;
			}else {
				cout << "ERROR!! Cannot open 'Flights.txt' on Project.cpp line 24.\n";
			}
	}
}


int main() {
	int MAX_FLIGHTS = 125; // 125 by default, more can be added.
	Airline newPak("New-Pak Airline", "Street 4 Section I/8", "0333-6111234", "061-6352455", "contact@newpak.com");
	Flight* allFlights = new Flight[MAX_FLIGHTS];
	loadFlightData(allFlights, MAX_FLIGHTS);
	int choice; string username, password;
	programStart:
	cout << "========================================================\n";
	cout << "Welcome to New-Pak Airline Flight System (NPAFS). \n";
	cout << "1. Login as Passenger. \n";
	cout << "2. Login as Administrator. \n";
	cout << "3. Sign up as Passenger. \n";
	cout << "4. View Flight Schedule. \n";
	cout << "========================================================\n";
	cout << "Choice: ";
	choice = TakeIntInput("choice", 1, 4);


	if (choice == 1) {
		cout << "=====================================================\n";
		cout << "UserName: ";
		cin >> username;
		cout << "Password: ";
		cin.sync(); // To remove the initial \n
		string password;
		getline(cin, password);
		Passenger* passengerPtr = new Passenger();
		if (passengerPtr -> validate(username, password)) {
			// Load Passenger Data into Passenger obj.
			Passenger traveller;
			traveller.FetchData(username);
			userStart:
			// Show user new menu if password is validated.
			cout << "Welcome back user, " << username << endl;
			cout << "=====================================================\n";
			cout << "1. View Flight Schedule.\n";
			cout << "2. Make a reservation.\n";
			cout << "3. View Reservations.\n";
			cout << "4. Cancel Reservation.\n";
			cout << "5. Update Personal Details.\n";
			cout << "6. View Inquiry Details.\n";
			cout << "7. Sign Out.\n";
			cout << "=====================================================\n";
			cout << "Choice: ";
			choice = TakeIntInput("choice", 1, 7);

			if (choice == 1) {
				for(int i = 0; i<MAX_FLIGHTS; i++) {
					allFlights[i].display();
				}
				cout << "Enter any key to continue.\n";
				cin.sync();
				cin.get();
				goto userStart;
			}
			else if (choice == 2) {
				string t_ID;
				string country, city;
				bool local = false;

				countryInput:
				cout << "Please input the country\nFor Local Flights, enter 'Pakistan'\nCountry:";
				cin>>country;
				if (country == "Pakistan") {
					local = true; // Used for tax calculation later-on.
					for(int i = 0; i<MAX_FLIGHTS; i++) {
						string fileCity = allFlights[i].getLandingLocation();
							size_t pos = fileCity.find('-');
							if (pos != string::npos) {
								if (fileCity.substr(0, pos) == "Islamabad" ||
									fileCity.substr(0, pos) == "Lahore" ||
									fileCity.substr(0, pos) == "Quetta" ||
									fileCity.substr(0, pos) == "Peshawar" ||
									fileCity.substr(0, pos) == "Karachi") {
									allFlights[i].display();

								}

							}
					}
				}
				else {
					cout << "For International Flights, you need to have VISA from that country issued to your name.\n";
					if (!isVisaIssued(username, country)) {
						cout << "ERROR!! You do not have VISA issued to your name for that country. Please input again. \n";
						goto countryInput;
					}

				bool countryFound = false;
				for(int i = 0; i<MAX_FLIGHTS; i++) {
					string fileCountry = allFlights[i].getLandingLocation();
						size_t pos = fileCountry.find('-');
						if (pos != string::npos) {
							if (country == fileCountry.substr(0, pos)) {
								countryFound = true;
								break;
							}

						}
				}
				if (countryFound) {
				cout << "Country found, flights going to this country are, \n";
				cout << "Flight\tModel\t    Seats Avail\tDeparture  Landing\tDepart. Location\tLanding Location\tConnecting  Suspended" << endl;

				for(int i = 0; i<MAX_FLIGHTS; i++) {
					string fileCountry = allFlights[i].getLandingLocation();
						size_t pos = fileCountry.find('-');
						if (pos != string::npos) {
							if (country == fileCountry.substr(0, pos)) {
								allFlights[i].display();
							}

						}
				}
				}
				}
				do {
				cout << "Please enter the ID of flight you want to book. \nFlight ID: ";
				cin >> t_ID;
				if (t_ID.length() != 6)
					cout << "Invalid ID Format. Please enter again.\n";
				} while (t_ID.length() != 6);
				bool flightFound = false;
				int i; // Declaring outside so I know at what index the flight was found.
				for(i = 0; i<MAX_FLIGHTS; i++) {
					if (allFlights[i].getFlightId() == t_ID) {
						flightFound = true;
						break;
					}
				}

				if (flightFound) {
					int seatChoice;
					cout << allFlights[i].getMaxPassengers() - allFlights[i].getPassengerCount() << " seats avalable. \n";
					double eco_tax = 0.1 * 10000 * getHourlyCost(allFlights[i]);
					double biz_tax = 0.1 * 20000 * getHourlyCost(allFlights[i]);
					double local_eco_tax = 0.05 * 10000 * getHourlyCost(allFlights[i]);
					double local_biz_tax = 0.05 * 20000 * getHourlyCost(allFlights[i]);

					cout << "Would you like to book economy or business seat?\n";

					if (local) {

						cout << "[0]: Economy, 10,000 per hour, Tax(5%):" << local_eco_tax << " Total Cost: " << 10000 * getHourlyCost(allFlights[i]) + local_eco_tax << " PKR" << endl;
						cout << "[1]: Business, 20,000 per hour, Tax(5%):" << local_biz_tax << " Total Cost: " << 20000 * getHourlyCost(allFlights[i]) + local_biz_tax << " PKR" << endl;
						cout << "Choice: ";
						seatChoice = TakeIntInput("seat type", 0, 1);
					}
					else {
					cout << "[0]: Economy, 20,000 per hour, Tax(10%):" << eco_tax << " Total Cost: " << (20000 * getHourlyCost(allFlights[i])) + eco_tax << " PKR" << endl;
					cout << "[1]: Business, 30,000 per hour, Tax(10%):" << biz_tax << " Total Cost: " << (30000 * getHourlyCost(allFlights[i])) + biz_tax << " PKR" << endl;
					cout << "Choice: ";
					seatChoice = TakeIntInput("seat type", 0, 1);
					}



					if (seatChoice == 0) {
						cout << "You have booked an Economy seat at Flight " << t_ID << endl;
						cout << "Please make sure that you board on time.\n";
						cout << "The flight is due to take off at " << allFlights[i].getDepartureTime();
						cout << ", from " << allFlights[i].getDepartureLocation() << endl;
						Reservation newRes("COMPLETE", "ECONOMY", allFlights[i].getFlightId());
						traveller.addReservation(newRes);
						goto userStart;
					}
					else {
						cout << "You have booked a Business Class seat at Flight " << t_ID << endl;
						cout << "Please make sure that you board on time.\n";
						cout << "The flight is due to take off at " << allFlights[i].getDepartureTime();
						cout << ", from " << allFlights[i].getDepartureLocation() << endl;
						Reservation newRes("COMPLETE", "BUSINESS", allFlights[i].getFlightId());
						traveller.addReservation(newRes);
						goto userStart;
					}

				}
			}
			else if (choice == 3) { // View Reservations
				if (traveller.getReservedFlightCount() == 0) {
						cout << "ERROR!! No reservations found for " << username << endl;
						goto userStart;
				}
				else {
					string line;
					Reservation* passengerReservs = traveller.getReservation();
					for(int i = 0; i<traveller.getReservedFlightCount(); i++) {
					string res_flightID = passengerReservs[i].getReservedFlightID();
					for(int i = 0; i<MAX_FLIGHTS; i++) {
						if (res_flightID == allFlights[i].getFlightId())
							allFlights[i].display();
					}
					}
					cout << "Press any key to go back.\n";
					cin.get();
					goto userStart;
				}
			}
			else if (choice == 4) {

				if (traveller.getReservedFlightCount() == 0) {
						cout << "ERROR!! No reservations found for " << username << endl;
						goto userStart;
				}
				else {

					string line;
					Reservation* passengerReservs = traveller.getReservation();
					int counter = 0;
					for(int i = 0; i<traveller.getReservedFlightCount(); i++) {
					string res_flightID = passengerReservs[i].getReservedFlightID();
					for(int i = 0; i<MAX_FLIGHTS; i++) {
						if (res_flightID == allFlights[i].getFlightId()) {
							cout << "[" << counter++ << "]: ";
							allFlights[i].display();
						}
					}
					}
					int flightIDs[counter];
					int count = 0;

					for(int i = 0; i<traveller.getReservedFlightCount(); i++) {
					string res_flightID = passengerReservs[i].getReservedFlightID();
					for(int i = 0; i<MAX_FLIGHTS; i++) {
						if (res_flightID == allFlights[i].getFlightId()) {
							flightIDs[count++] = i;
						}
					}
					}

					cout << "Choose:";
					int choice = TakeIntInput("reservation ID", 0, counter);
					traveller.deleteReservation(allFlights[flightIDs[choice]].getFlightId());
					cout << "You successfully deleted reservation of flight " << allFlights[flightIDs[choice]].getFlightId() << endl;
					cout << "Press any key to continue";
					cin.get();
					goto userStart;
					}
				}
			else if (choice == 5) {
				string newCNIC;
				cout << "[0]: Update CNIC \n";
				cout << "[1]: Go Back \n";
				cout << "Choice: ";
				int choice = TakeIntInput("cnic", 0, 1);
				if (choice == 0) {
					do {
					cout << "New CNIC: ";
					cin >> newCNIC;
						if (newCNIC.length() != 13)
							cout << "ERROR!! Length of CNIC must be 13. \n";
					} while (newCNIC.length() != 13);
					traveller.setCNIC(newCNIC);
				}
				if (choice == 1) {
					goto userStart;
				}
			}
			else if (choice == 6) {
				newPak.printInquiryDetails();
				cout << "Enter any key to continue.\n";
				cin.sync();
				cin.get();
				goto userStart;
			}
			else if (choice == 7) {
				goto programStart;
			}
			} else {
				cout << "Failed to validate.\n";
				goto programStart;
			}
		}

	else if (choice == 2) {

		cout << "=====================================================\n";
		cout << "UserName: ";
		cin >> username;
		cout << "Password: ";
		cin.sync(); // To remove the initial \n
		getline(cin, password);
		Admin* adminPtr = new Admin();
		if (adminPtr -> validate(username, password)) {
			adminStart:
			// Show user new menu if password is validated.
			cout << "Welcome back Admin, " << username << endl;
			cout << "=====================================================\n";
			cout << "1. Add Route.\n";
			cout << "2. Set Passenger Limit.\n";
			cout << "3. Update Airline Inquiry Details.\n";
			cout << "4. block Flight.\n";
			cout << "5. Unblock Flight.\n";
			cout << "6. Sign Out.\n";
			cout << "=====================================================\n";
			cout << "Choice: ";
			choice = TakeIntInput("choice", 1, 6);

			if (choice == 1) {
				bool isUnique;
				string flightID, flightModel, departureTime, landingTime, departureLocation, landingLocation, isConnecting;
				cout << "Adding new route to system.\n";
				do {
				cout << "Input Flight ID: ";
				cin >> flightID;
				isUnique = true;
				// Check that the flight doesn't already exist.
				for(int i = 0; i<MAX_FLIGHTS; i++) {
					if (allFlights[i].getFlightId() == flightID)
						isUnique = false;
				}
				if (!isUnique)
					cout << "ERROR!! Another flight with that ID already exists. \n";
				} while (!isUnique);

				cout << "Input Flight Model(E.g. Airbus-A380): ";
				cin >> flightModel;
				cout << "Input DepartureTime: ";
				cin >> departureTime;
				cout << "Input LandingTime: ";
				cin >> landingTime;
				cout << "Input Departure Location: ";
				cin >> departureLocation;
				cout << "Input Landing Location: ";
				cin >> landingLocation;
				cout << "Flight suspended?(Input 0 or 1): ";
				isConnecting = TakeIntInput("connecting flight", 0, 1);
				// All Info Taken, now opening file and adding.
				fstream flightFile("src/Flights.txt", ios::app);
				if (flightFile) {
					flightFile << flightID << ";" << flightModel << ";" << departureTime << ";" << landingTime << ";" << departureLocation << ";" << landingLocation << isConnecting << endl;
					flightFile.close();
					cout << "Changed saved successfully.\n";
					MAX_FLIGHTS++;
					goto adminStart;
				} else {
					cout << "ERROR!! Project.cpp line 252. Cannot open Flights.txt file.\n";
				}

			}
			else if (choice == 2) {
				bool flightFound = false;
				string flightID;
				int newCapacity;
				inputFlight:
				// Editting flight max seats.
				cout << "Input Flight ID: ";
				cin >> flightID;
				int i;
				for(i = 0; i<=MAX_FLIGHTS; i++) {
					if (allFlights[i].getFlightId() == flightID) {
						flightFound = true;
						break;
					}
				}
				if (flightFound) {

						cout << "Enter new seat capacity of flight. \nInput:";
						newCapacity = TakeIntInput("seat capacity", 1, 60);
						if (newCapacity < allFlights[i].getPassengerCount()) {
							cout << "ERROR!! More than " << newCapacity << " passengers have booked the flight already.\n";
							goto inputFlight;

						}
						else {
							allFlights[i].setMaxPassengers(newCapacity);
							cout << "Editted Seat capacity of flight successfully.\n";
							cout << "New capacity of flight " << flightID << " is, " << allFlights[i].getMaxPassengers() << endl;
							goto adminStart;
						}
					}
				else {
					cout << "ERROR!! Flight with that ID not found. Please input again.";
					goto inputFlight;
				}
			}
			else if (choice == 3) {
				cout << "Please select what to update.\n";
				cout << "[0]: Name: " << newPak.getName() << "\n";
				cout << "[1]: Address: " << newPak.getAddress() << "\n";
				cout << "[2]: Landline: " << newPak.getLandLine() << "\n";
				cout << "[3]: Phone:  " << newPak.getPhoneNo() << "\n";
				cout << "[4]: Email:  " <<  newPak.getEmail() << "\n";
				int updateChoice = TakeIntInput("update choice", 0, 4);
				string input;
				switch (updateChoice) {
				case 0:
					cout << "New Name: ";
					cin >> input;
					newPak.setName(input);
					break;
				case 1:
					cout << "New Address: ";
					cin >> input;
					newPak.setAddress(input);
					break;
				case 2:
					cout << "New Landline: ";
					cin >> input;
					newPak.setLandLine(input);
					break;
				case 3:
					cout << "New Phone: ";
					cin >> input;
					newPak.setPhoneNo(input);
					break;
				case 4:
					cout << "New Email: ";
					cin >> input;
					newPak.setEmail(input);
					break;
				}
				cout << "Airline Inquiry detail updated successfully.\n";
				goto adminStart;
			}
			else if (choice == 4) { // Block Flight

				bool flightFound = false;
				string flightID;
				int newCapacity;
				do {
				// Editting flight max seats.
				cout << "Input Flight ID: ";
				cin >> flightID;
				if (flightID.length() < 6) {
					cout << "Invalid ID. Length must be atleast 6 digits.\n";
					continue;
				}
				int i;
				for(i = 0; i<=MAX_FLIGHTS; i++) {
					if (allFlights[i].getFlightId() == flightID) {
						flightFound = true;
						break;
					}
				}
				if (flightFound) {
					allFlights[i].setFlightBlocked(true);
					cout << "You successfully blocked flight " << flightID << endl;
					break;
					}
				else {
					cout << "ERROR!! Flight with that ID not found. Please input again.";
					continue;
				}
				} while (1);
				goto adminStart;
			}
			else if (choice == 5) {

				bool flightFound = false;
				string flightID;
				int newCapacity;
				do {
				// Editting flight max seats.
				cout << "Input Flight ID: ";
				cin >> flightID;
				if (flightID.length() < 6) {
					cout << "Invalid ID. Length must be atleast 6 digits.\n";
					continue;
				}
				int i;
				for(i = 0; i<=MAX_FLIGHTS; i++) {
					if (allFlights[i].getFlightId() == flightID) {
						flightFound = true;
						break;
					}
				}
				if (flightFound) {
					allFlights[i].setFlightBlocked(false);
					cout << "You successfully unblocked flight " << flightID << endl;
					break;
					}
				else {
					cout << "ERROR!! Flight with that ID not found. Please input again.";
					continue;
				}
				} while (1);
				goto adminStart;
			}
			else if (choice == 6) {
				goto programStart;
			}

		}
		else {
			cout << "Failed to validate.\n";
			goto programStart;
		}
	}
	else if (choice == 3) {
		Passenger* passengerPtr = new Passenger();
		passengerPtr -> signUp();
		cout << "Now that you have registered. We will need your payment details.\n";
			// Bank Acc
			cout << "Please enter 5 digit Bank Account No.";
			cout << "Bank Account: ";
			string bankAcc = "TEST";
			cout << "We recorded your bank account, " << bankAcc;
			goto programStart;
		}
	else if (choice == 4) {
		string pause;
		cout << "Flight\tModel\t    Seats Avail\tDeparture  Landing\tDepart. Location\tLanding Location\tConnecting  Flight Blocked" << endl;
		for(int i = 0; i<MAX_FLIGHTS; i++) {
			allFlights[i].display();
		}
		cout << "Press any key to go back.\n";
		cin.sync();
		cin.get();
		goto programStart;
	}
	return 0;
}
