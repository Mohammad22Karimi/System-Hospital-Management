#include "Person.h"
#include <iostream>
using namespace std;
Person::Person()
{
	id = -1;
}

void Person::addPerson(int16_t minAge, int16_t maxAge)
{
	//getting basic details of the person from the user side
	cout << "Enter the name: \nFirst Name: ";
	getline(cin >> ws, firstName);
	cout << "\nLast Name: ";
	getline(cin >> ws, lastName);

	cout << "Enter age: ";
	cin >> age;
	while (age <= 0) {
		cout << "It's a invalid age.\n";
		cout << "the age must be between " << minAge << " and " << maxAge << ".\nEnter agein: ", cin >> age;
	}

	
	cout << "Enter gender (M = Male || F = Female) :";
	cin >> gender;
	if (gender == "M" || gender == "F");
	else {
		while (gender != "M" || gender != "F") {
			cout << "F or M? :";
			cin >> gender;
		}
	}

	cout << "Enter phone number: ";
	getline(cin >> ws, phone);
	cout << "Enter address: ";
	getline(cin >> ws, address);
	return;
}

void Person::printDetails()
{
	if (id == -1)
		return;
	cout << "\nDetails:\n";
	cout << "ID              : " << id << "\n";
	cout << "Full Name       : " << firstName << " " << lastName << "\n";
	cout << "Gender          : " << gender << "\n";
	cout << "Age             : " << age << "\n";
	cout << "Mobile          : " << phone << "\n";
	cout << "Address         : " << address << endl;
	return;
}
