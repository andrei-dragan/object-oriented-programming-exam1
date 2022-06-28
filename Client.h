#pragma once

#include <string>

#include "Dwelling.h"

using namespace std;

class Client {
protected:
	string name;
	double income;
public:
	Client(string _name, double _income) : name{ _name }, income{ _income } {};
	string getName() { return this->name; }
	void updateIncome(double newIncome) { this->income = newIncome; }
	virtual double totalIncome();
	virtual string toString();
	virtual bool isInterested(Dwelling d) = 0;
};