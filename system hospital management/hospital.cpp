#include "hospital.h"
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include "appointment.h"




//defining already declared static members in the global scope;

map<int, Doctor> hospital::doctorList;
map<int, Patient> hospital::patientList;
map<int, appointment> hospital::appointmentList;


const int hospital::doctorsLimit = 30;
const int hospital::appointmentsLimit = 240; // per day
// appointment limits is kind of patients limit;



void hospital::printDoctors() {
	for (auto i : doctorList) {
		i.second.printDetails();
		cout << endl;
	}
	return;
}

void hospital::printPatients() {
	for (auto i : patientList) {
		i.second.printDetails();
		cout << endl;
	}
	return;
}

void hospital::printAppointments() {
	for (auto i : appointmentList) {
		i.second.printDetails();
	}
	return;
}


