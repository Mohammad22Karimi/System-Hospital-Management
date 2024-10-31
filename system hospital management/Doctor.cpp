#include "Doctor.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
#include "hospital.h"
#include "Person.h"


Doctor::Doctor()
{
	id = -1;
	specialty = "";
}

void Doctor::fillMap() {
	ifstream inFile("doctors.csv");
	if (!inFile) {
		cerr << "Error opening file for reading. loaddoctors\n";
		return;
	}
	string line;
	while (getline(inFile, line)) {
		Doctor d;
		
		stringstream ss(line);
		string item;
		int id, age;
		string firstName, lastName, gender, phone, address, specialty;

		getline(ss, item, ','); id = stoi(item);
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, gender, ',');
		getline(ss, item, ','); age = stoi(item);
		getline(ss, phone, ',');
		getline(ss, address, ',');
		getline(ss, specialty, ',');
		d.id = id;
		d.firstName = firstName;
		d.lastName = lastName;
		d.gender = gender[0];
		d.age = age;
		d.phone = phone;
		d.address = address;
		d.specialty = specialty;
		hospital::doctorList[d.id] = d;

	}
	inFile.close();
	return;
}

void Doctor::saveMap() const {
	ofstream outFile("temp.csv", ios::out);
	if (!outFile) {
		cerr << "Error opening file for writing\n";
		return;
	}
	//outFile << "doctorId,firstName,lastName,gender,age,mobNumber,address,type\n";
	for (auto i : hospital::doctorList) {
		outFile << i.second.id << "," << i.second.firstName << "," << i.second.lastName
			<< "," << i.second.gender << "," << i.second.age << "," << i.second.phone
			<< "," << i.second.address << "," << i.second.specialty << endl;
	}
	/*outFile << id << "," << firstName << "," << lastName << ","
		<< gender << "," << age << "," << phone << "," << address
		<< "," << specialty << endl;*/
	outFile.close();
	remove("doctors.csv");
	rename("temp.csv", "doctors.csv");
	return;
}

void Doctor::addPerson() {
	
	if (hospital::doctorList.size() == hospital::doctorsLimit) {
		cerr << "\nDoctor limit reached. can't add more\n";
		return;
	}

	Person::addPerson(18, 65);
	if ((age < 18) || (age > 65))
		return;
	cout << "Enter the type of the doctor: ";
	getline(cin >> ws, specialty);
	if (hospital::doctorList.rbegin() != hospital::doctorList.rend()) {
		id = ((hospital::doctorList.rbegin())->first) + 1;
	}
	else id = 1;
	hospital::doctorList[id] = *this;

	ofstream outFile("doctors.csv", ios::app);
	if (!outFile) {
		cerr << "Error opening file for writing.\n";
		return;
	}

	outFile << id << "," << firstName << "," << lastName << "," << gender << "," << age << ","
		<< phone << "," << address << "," << specialty << endl;

	outFile.close();
	cout << "\n"
		<< firstName << " " << lastName << "added successfully\n";
	cout << "ID is : " << id << endl;
	return;
}

void Doctor::getDetails()
{
	cout << "Enter the doctor's Id: ";
	int reqId;
	cin >> reqId;
	if (hospital::doctorList.find(reqId) != hospital::doctorList.end()) {
		*this = hospital::doctorList[reqId];
	}
	else
		cout << "\nNo matching record found!\n";
	return;
}

void Doctor::printDetails()
{
	if (id == -1) return;

	Person::printDetails();
	cout << "specialty       : " << specialty << "\n";
	return;
}
