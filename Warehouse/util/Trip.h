#ifndef TRIP_H_
#define TRIP_H_

#include "Date.h"
#include "Item.h"

struct Trip {
	Date purchase_date;
	int id, quantity;
	Item *item;
};

#endif /* TRIP_H_ */
