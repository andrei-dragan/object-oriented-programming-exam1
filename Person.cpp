#include "Person.h"

bool Person::isInterested(Dwelling d) {
	return (d.getPrice() / 1000 <= this->income);
}