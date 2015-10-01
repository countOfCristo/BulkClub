#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>
#include <iostream>
#include "Date.h"
#include "Price.h"
#include "Item.h"

using namespace std;

typedef int Member_t;

const Member_t REGULAR = 0;
const Member_t EXECUTIVE = 1;

//DONT INITILIZE AN INSTANCE OF THIS CLASS
class Member {
public:
	string name; //Keep this this way. See res/Public_Variables_Manifesto
	int number, number_items_purchased;
	Price total_spent;
	Member_t member_type;
	Date expiration_date;
	Item *items_purchased;
	Member() { total_spent.cents = 0; total_spent.dollars = 0; }
	~Member() {}
};

#endif /* MEMBER_H_ */
