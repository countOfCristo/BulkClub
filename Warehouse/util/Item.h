#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include "Price.h"

using namespace std;

struct Item {
	Price price;
	string item_name;
	int quantity_sold;
};

#endif /* ITEM_H_ */
