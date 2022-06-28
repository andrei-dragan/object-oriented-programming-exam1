#include "Dwelling.h"

string Dwelling::toString() {
	string str;
	if (this->isProfitable) str = "Profitable dwelling having a price of " + to_string(this->price);
	else str = "Unprofitable dwelling having a price of " + to_string(this->price);
	return str;
}