#pragma once
#include "Client.h"

class Person : public Client {
public:
	Person(string _name, double _income) : Client{ _name, _income } {};
	bool isInterested(Dwelling d) override;
};