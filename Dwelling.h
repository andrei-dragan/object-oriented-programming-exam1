#pragma once

#include <string>

using namespace std;

class Dwelling {
private:
	double price;
	bool isProfitable;
public:
	Dwelling(double _price, bool _isProfitable) : price{ _price }, isProfitable{ _isProfitable } {};
	double getPrice() { return this->price; }
	bool getIsProfitable() { return this->isProfitable; }
	string toString();
};