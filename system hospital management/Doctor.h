#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Person.h"
class appointment;
class Doctor :
    public Person
{
private:
    string specialty;
public:

    string getSpecialty() const { return specialty; }
    Doctor();
    void fillMap() override;
    void saveMap() const override;
    void addPerson();
    void getDetails();
    void printDetails();
    friend class appointment;

};

