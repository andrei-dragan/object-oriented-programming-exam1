#include "Company.h"

double Company::totalIncome() {
	return (this->income + this->moneyFromInvestments);
}

bool Company::isInterested(Dwelling d) {
	return (d.getPrice() / 100 <= this->totalIncome() && d.getIsProfitable());
}

string Company::toString() {
	string str = Client::toString();
	str += " (this is a company that has investments of: " + to_string(this->moneyFromInvestments) + ")";
	return str;
}