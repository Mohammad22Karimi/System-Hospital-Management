#include "appointment.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "hospital.h"
#include <ctime>
using namespace std;

appointment::appointment()
{
    id = -1;
    patient.id = -1;
    doctor.id = -1;
}

appointment::~appointment()
{
    id = -1;
    patient.id = -1;
    doctor.id = -1;
    return;
}

void appointment::fillMap()
{
    ifstream inFile("appointments.csv");
    if (!inFile) {
        cerr << "Error opening file for reading. loadappointments\n";
        return;
    }
    string line;
    while (getline(inFile, line)) {

        appointment a;
        stringstream ss(line);
        string item;
        int id, patientId, doctorId;
        string date, time;

        getline(ss, item, ','); id = stoi(item);
        getline(ss, item, ','); patientId = stoi(item);
        getline(ss, item, ','); doctorId = stoi(item);
        getline(ss, date, ',');
        getline(ss, time, ',');

        a.id = id;
        a.patient = hospital::patientList[patientId];
        a.doctor = hospital::doctorList[doctorId];
        a.date = date;
        a.time = time;
        hospital::appointmentList[a.id] = a;

    }
    inFile.close();
    return;

}

void appointment::saveMap()
{
    ofstream outFile("tmp.csv", ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& i : hospital::appointmentList) {
        outFile << i.second.id << "," << i.second.patient.id << ","
            << i.second.doctor.id << "," << i.second.date << "," <<
            i.second.time << endl;
    }
    outFile.close();
    remove("appointments.csv");
    rename("tmp.csv", "appointments.csv");
    return;
}

void appointment::book()
{
    if (hospital::appointmentList.size() >= 8 * hospital::doctorList.size()) {
        cout << "\n\nSorry, no doctor is available for appointment today!\n\n";
        return;
    }
    cout << "\n\nIs the patient already registered (Y : Yes || N : No)?\n";
    char ans;
    cin >> ans;
    if (ans == 'Y' || ans == 'N');
    else {
        while (ans != 'Y' && ans != 'N') {
            cout << "Y or N?\n";
            cin >> ans;
        }
    }
    if (ans == 'N') {
        patient.addPerson();
    }
    else {
        cout << "Search for the required patient: \n\n";
        patient.getDetails();
    }

    cout << "\n\nNow, search for the required doctor:\n";
    ans = 'Y';
    while (ans == 'Y') {
        doctor.getDetails();
        if (doctor.id != -1) {
            ans = 'N';
            break;
        }
    }

    if (hospital::appointmentList.rbegin() != hospital::appointmentList.rend()) {
        id = ((hospital::appointmentList.rbegin())->first) + 1;
    }
    else id = 1;

    // گرفتن تاریخ و زمان فعلی
    std::time_t t = std::time(nullptr);
    std::tm now;
    localtime_s(&now, &t); // Use localtime_s for safety

    // Format the year
    char yearBuffer[5]; // Year is 4 digits + null terminator
    std::strftime(yearBuffer, sizeof(yearBuffer), "%Y", &now);
    std::string currentYear = yearBuffer;

    // Format the month
    char monthBuffer[3]; // Month is 2 digits + null terminator
    std::strftime(monthBuffer, sizeof(monthBuffer), "%m", &now);
    std::string currentMonth = monthBuffer;

    // Format the day
    char dayBuffer[3]; // Day is 2 digits + null terminator
    std::strftime(dayBuffer, sizeof(dayBuffer), "%d", &now);
    std::string currentDay = dayBuffer;

    // Format the time
    char timeBuffer[9]; // Time is HH:MM:SS + null terminator
    std::strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", &now);
    std::string currentTime = timeBuffer;

    date = currentYear + "-" + currentMonth + "-" + currentDay;
    time = currentTime;

    hospital::appointmentList[id] = *this;
    cout << "\n Appointment of patient " + patient.firstName + " " + patient.lastName + " with doctor "
        << doctor.firstName << " " << doctor.lastName << " booked successfully!\n";
    printDetails();
    return;
}

void appointment::printDetails()
{
    if (id == -1)
        return;
    cout << "\n\n\nAppointment Details:\nID                 : " << id << "\n"
        << "Patient's Name     : " + patient.firstName + " " + patient.lastName + " (ID = " << patient.id << ")\n"
        << "Doctor's Name      : " + doctor.firstName + " " + doctor.lastName + " (ID = " << doctor.id << ")\n"
        << "Date               : " + date + "\n"
        << "Time               : " << time << "\n\n";
    return;
}

void appointment::getDetails()
{
    cout << "Enter the Id: ";
    int currentId;
    cin >> currentId;
    if (hospital::appointmentList.find(currentId) == hospital::appointmentList.end()) {
        cout << "\nInvalid appointment Id\n";
        currentId = -1;
        return;
    }
    *this = hospital::appointmentList[currentId];
    return;
}
