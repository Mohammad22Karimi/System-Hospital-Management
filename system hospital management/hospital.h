#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "map"
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include "appointment.h"

class hospital
{

private:
	// map<id, object>
	static map<int, Doctor> doctorList;
	static map <int, Patient> patientList;
	static map <int, appointment> appointmentList;

	static const int doctorsLimit;
	static const int patientsLimit;
	static const int appointmentsLimit;
	
	friend class Doctor;
	friend class Patient;
	friend class appointment;

public:
	static void printDoctors();
	static void printPatients();
	static void printAppointments();
};

