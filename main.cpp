#include <iostream>

#include "RealEstateAgency.h"
#include "Company.h"
#include "Person.h"

using namespace std;


void printMenu() {
	cout << "Hello! Welcome to our real eastate agency!" << '\n';
	cout << "Input 1 - to update a client's income." << '\n';
	cout << "Input 2 - to display all clients and dwellings." << '\n';
	cout << "Input 3 - to add a dwelling and see all the interested clients." << '\n';
	cout << "Input 4 - to save all clients to a file." << '\n';
	cout << "Input 5 - to exit the application." << '\n';
	cout << "===========================================================================" << '\n';
	cout << "Choose your command: ";
}

int main() {

	RealEstateAgency agency;

	Person* p1 = new Person{ "Jade", 4500.24 };
	Client* c1 = p1;
	agency.addClient(c1);

	Person* p2 = new Person{ "Josh", 1500.24 };
	Client* c2 = p2;
	agency.addClient(c2);

	Company* y1 = new Company{ "MicroFocus", 99100.66, 56700 };
	Client* c3 = y1;
	agency.addClient(c3);

	Company* y2 = new Company{ "Evozon", 4100.66, 1700 };
	Client* c4 = y2;
	agency.addClient(c4);

	agency.addDwelling(7000, true);
	agency.addDwelling(15000, false);

	while (true) {
		string command;
		cout << "===========================================================================" << '\n';
		printMenu();
		cin >> command;

		if (command == "1") {
			string name;
			double newIncome;

			cout << "Enter the name of the client: ";
			cin >> name;

			cout << "Enter the new income of this client: ";
			cin >> newIncome;
			
			agency.updateClient(name, newIncome);
		}
		else if (command == "2") {
			vector<Client*> clients = agency.getClients();
			vector<Dwelling> dwellings = agency.getDwellings();

			cout << "===========================================================================" << '\n';
			cout << "Dwellings: " << '\n';
			for (auto d : dwellings) {
				cout << d.toString() << '\n';
			}

			cout << "===========================================================================" << '\n';
			cout << "Clients: " << '\n';
			for (auto c : clients) {
				cout << c->toString() << '\n';
			}
		}
		else if (command == "3") {
			double price;
			string profitable;
			bool isProfitable; 

			cout << "Input the price of the dwelling: ";
			cin >> price;

			cout << "Input <y> if the dwelling is profitable, or something else if not: ";
			cin >> profitable;
			if (profitable == "y") isProfitable = true;
			else isProfitable = false;

			Dwelling d = agency.addDwelling(price, isProfitable);
			cout << "===========================================================================" << '\n';
			cout << "Interested clients: " << '\n';
			for (auto c : agency.getInterestedClients(d)) {
				cout << c->toString() << '\n';
			}
		}
		else if (command == "4") {
			string filename;
			cout << "Input a file name: ";
			cin >> filename;
			agency.writeToFile(filename);
		}
		else if (command == "5") {
			return 0;
		}
		else {
			cout << "Invalid command! Try again!" << '\n';
		}
	}
}