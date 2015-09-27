#ifndef TRIP_H_
#define TRIP_H_

#include <string>
#include "Date.h"
#include "Price.h"

using namespace std;

struct Trip {
	Date purchase_date;
	int id, quantity;
	Price price;
	string item_name;
};

#endif /* TRIP_H_ */
