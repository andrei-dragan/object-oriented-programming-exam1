#pragma once

#include "Client.h"

class Company : public Client {
private:
	double moneyFromInvestments;
public:
	Company(string _name, double _income, double _moneyFromInvestments) : Client{ _name, _income }, moneyFromInvestments{ _moneyFromInvestments } {};
	double totalIncome() override;
	string toString() override;
	bool isInterested(Dwelling d) override;
};