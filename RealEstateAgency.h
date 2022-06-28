#pragma once

#include <vector>
#include <fstream>

#include "Client.h"
#include "Dwelling.h"

using namespace std;

class RealEstateAgency {
private:
	vector<Client*>clients;
	vector<Dwelling>dwellings;
public:
	Dwelling addDwelling(double price, bool isProfitable);
	void updateClient(string name, double newIncome);
	vector<Client*> getInterestedClients(Dwelling d);
	void writeToFile(string filename);

	vector<Client*> getClients() { return this->clients; }
	vector<Dwelling> getDwellings() { return this->dwellings; }

	void addClient(Client* c) { this->clients.push_back(c); }
};