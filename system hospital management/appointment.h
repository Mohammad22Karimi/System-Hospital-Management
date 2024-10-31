#pragma once
#include "Patient.h"
#include "Doctor.h"
#include <iostream>
#include <string>

using namespace std;

class appointment
{
private:
	int id;
	Doctor doctor;
	Patient patient;
	string date;
	string time;
public:
	//appointment() :id(0) , date(""), time("") {}
	//appointment(int id, Doctor doctor, Patient patient, string date, string time) : id(id), doctor(doctor), patient(patient),
	//	date(date), time(time){}

	appointment();
	~appointment();
	//int getAppointmentId() const { return id; }
	void fillMap();
	void saveMap();
	void book();
	void printDetails();
	void getDetails();


};

