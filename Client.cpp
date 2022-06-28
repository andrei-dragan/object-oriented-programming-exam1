#include "Client.h"

double Client::totalIncome() {
	return this->income;
}

string Client::toString() {
	string str;
	str += "Client " + this->name + ", having an income of " + to_string(this->income) + " and a total income of: " + to_string(this->totalIncome());
	return str;
}