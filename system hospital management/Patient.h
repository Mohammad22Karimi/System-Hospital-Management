#pragma once
#include "Person.h"
#include <iostream>
using namespace std;
class appointment;

class Patient :
    public Person
{
private:
    int height; // cm
    int weight; // kg
//    int queueNumber; // نوبت بیمار
    friend class appointment;

public:

    int getHeight() const { return height; }
    int getWeight() const { return weight; }
  //  int getQueueNumber() const { return queueNumber; }


    Patient();
    void fillMap() override;
    void saveMap() const override;
    void addPerson();
    void getDetails(int rec = 0);
    void printDetails();
};

