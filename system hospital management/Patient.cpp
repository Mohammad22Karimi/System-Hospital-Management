#include "Patient.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "hospital.h"
using namespace std;

Patient::Patient() {
	id = -1;
}



void Patient::fillMap()
{
	ifstream inFile("patients.csv");
	if (!inFile) {
		cerr << "Error opening file for reading!" << endl;
		return;
	}
	string line;
	while (getline(inFile, line)) {
		Patient p;
		stringstream ss(line);
		string item;
		int Id, Age, Height, Weight;
		string firstName, lastName, gender, phone, address;

		getline(ss, item, ','); Id = stoi(item);
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, gender, ',');
		getline(ss, item, ','); Age = stoi(item);
		getline(ss, phone, ',');
		getline(ss, address, ',');
		getline(ss, item, ','); Height = stoi(item);
		getline(ss, item, ','); Weight = stoi(item);

		p.id = Id;
		p.age = Age;
		p.height = Height;
		p.weight = Weight;
		p.firstName = firstName;
		p.lastName = lastName;
		p.gender = gender;
		p.phone = phone;
		p.address = address;
		hospital::patientList[p.id] = p;
	}
	inFile.close();
	return;
}


void Patient::saveMap() const
{
	ofstream outFile("temp.csv", ios::out);
	if (!outFile) {
		cerr << "Error opening file for writing\n";
		return;
	}
	//outFile << "patientId,firstName,lastName,gender,age,mobNumber,address,height,weight\n";
	for (auto i : hospital::patientList) {
		outFile << i.second.id << "," << i.second.firstName << "," << i.second.lastName
			<< "," << i.second.gender << "," << i.second.age << "," << i.second.phone
			<< "," << i.second.address << "," << i.second.height << "," << i.second.weight << endl;
	}
	/*outFile << id << "," << firstName << "," << lastName << ","
		<< gender << "," << age << "," << phone << "," << address
		<< "," << height << "," << weight << endl;*/
	outFile.close();
	remove("patients.csv");
	rename("temp.csv", "patients.csv");
	return;
}

void Patient::addPerson()
{
	Person::addPerson();

	cout << "\nEnter the height of the patient (cm) : ";
	cin >> height;
	cout << "\nEnter the weight of the patient (pounds) : ";
	cin >> weight;

	if (hospital::patientList.rbegin() != hospital::patientList.rend()) {
		id = ((hospital::patientList.rbegin())->first) + 1;
	}
	else id = 1;
	hospital::patientList[id] = *this;
	return;
}

void Patient::getDetails(int rec) {
	cout << "Enter the patient's Id: ";
	int reqId;
	cin >> reqId;
	if (hospital::patientList.find(reqId) != hospital::patientList.end()) {
		*this = hospital::patientList[reqId];
	}
	else
		cout << "\nNo matching record found!\n";
	return;
}

void Patient::printDetails()
{
	if (id == -1)
		return;

	Person::printDetails();
	cout << "Height (cms)    : " << height << "\n";
	cout << "Weight (pounds) : " << weight << "\n";
	return;
}


