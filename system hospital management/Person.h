#pragma once
#include <string>
using namespace std;
class Person
{
protected:
	int id;
	string firstName,lastName;
	int age;
	string gender;
	string phone;
	string address;

public:

	Person();
	//virtual void displayInfo() const = 0;
	virtual void fillMap() = 0;
	virtual void saveMap() const = 0;
	virtual void addPerson(int16_t minAge = 0, int16_t maxAge = 1000);
	virtual void printDetails();
};

