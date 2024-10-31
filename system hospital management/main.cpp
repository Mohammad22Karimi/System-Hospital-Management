#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "Patient.h"
#include "Person.h"
#include "Doctor.h"
#include "appointment.h"
#include "hospital.h"


void appointmentsMenu() {
	bool exit = false;
	while (!exit) {
		int purpose = 0;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nSelect an option:\n\n";

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "./HOME/APPOINTMENTS\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "[01] : Book an appointment\n";
		cout << "[02] : Get appointment details\n";
		cout << "[03] : Show all appointments\n\n";
		cout << "[-1] : Back\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Enter your choice: ";
		cin >> purpose;
		if (purpose == 1) {
			appointment a;
			a.book();
		}
		else if (purpose == 2) {
			appointment a;
			a.getDetails();
			a.printDetails();
		}
		else if (purpose == 3) {
			hospital::printAppointments();
		}
		else if (purpose == -1) {
			exit = true;
			break;
		}
		else
			cout << "invalid choice\n";

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

		cout << endl;
		cout << "\nPress ENTER to continue...\n";
		cout << endl;

		getchar();
	}
	return;
}

void patientMenu() {
	bool exit = false;
	while (!exit) {
		int purpose = 0;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nSelect an option:\n\n";

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "./HOME/PATIENTS\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "[01] : Register a new patient\n";
		cout << "[02] : Get patient details\n";
		cout << "[03] : Show all patients\n";
		cout << "[-1] : Back\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Enter your choice: ";
		cin >> purpose;
		if (purpose == 1) {
			Patient p;
			p.addPerson();
		}
		else if (purpose == 2) {
			Patient p;
			p.getDetails();
			p.printDetails();
		}
		else if (purpose == 3) {
			hospital::printPatients();
		}
		else if (purpose == -1) {
			exit = true;
			break;
		}
		else
			cout << "Invalid choice!\n";


		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

		cout << endl;
		cout << "\nPress ENTER to continue...\n";
		cout << endl;

		getchar();
	}
	return;
}


void doctorMenu() {
	bool exit = false;
	while (!exit) {
		int purpose = 0;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nSelect an option:\n\n";

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "./HOME/DOCTORS\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "[01] : Register a new doctor\n";
		cout << "[02] : Get doctor details\n";
		cout << "[03] : Show all doctors\n";
		cout << "[-1] : Back\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Enter your choice: ";
		cin >> purpose;
		
		if (purpose == 1) {
			Doctor d;
			d.addPerson();
		}
		else if (purpose == 2) {
			Doctor d;
			d.getDetails();
			d.printDetails();
		}
		else if (purpose == 3) {
			hospital::printDoctors();
		}
		else if (purpose == -1) {
			exit = true;
			break;
		}
		else
			cout << "Invalid choice!\n";

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

		cout << endl;
		cout << "\nPress ENTER to continue...\n";
		cout << endl;

		getchar();
	}
	return;
}

int main() {

	{
		//filling maps with data from csv file
		Doctor d;
		Patient p;
		appointment a;
		p.fillMap();
		d.fillMap();
		a.fillMap();
	}


	int option;
	while (true)

	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "select a option: \n";
		cout << "~~~~~~~~~~~~~~~~~~";
		cout << ".Home\n";
		cout << "~~~~~~~~~~~~~~~~~~\n\n";

		cout << "[01]  : appointment \n";
		cout << "[02]  : patients \n";
		cout << "[03]  : doctors \n";
		cout << "[-1] : Exit\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Enter your choice: ";
		cin >> option;
		if (option == -1) {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "\nShutting Down System...\n";
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			break;
		}
		switch (option)
		{
		case(1):
			appointmentsMenu();
			break;

		case(2):
			patientMenu();
			break;

		case(3):
			doctorMenu();
			break;

		default:
			cout << "Invalid choice. Try again\n";
			break;
		}


	}
	{
		// saving data inside maps by overwriting it on the files
		Patient p;
		Doctor d;
		appointment a;

		p.saveMap();
		d.saveMap();
		a.saveMap();
	}

	return 0;
}
