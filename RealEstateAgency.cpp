#include "RealEstateAgency.h"

Dwelling RealEstateAgency::addDwelling(double price, bool isProfitable) {
	Dwelling d{ price, isProfitable };
	this->dwellings.push_back(d);
	return d;
}

void RealEstateAgency::updateClient(string name, double newIncome) {
	for (auto client : this->clients) {
		if (client->getName() == name) {
			client->updateIncome(newIncome);
			return;
		}
	}
}

vector<Client*> RealEstateAgency::getInterestedClients(Dwelling d) {
	vector<Client*>interestedClients;
	for (auto client : this->clients) {
		if (client->isInterested(d))
			interestedClients.push_back(client);
	}
	return interestedClients;
}

void RealEstateAgency::writeToFile(string filename) {
	ofstream g(filename);

	for (auto client : this->clients) {
		g << client->toString() << '\n';
	}
}