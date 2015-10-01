/*
 * The project... nuff said
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "member/Member.h"
#include "member/Regular.h"
#include "member/Executive.h"
#include "util/Trip.h"
#include "util/Item.h"
#include "core/Initializer.h"

using namespace std;

//variable declaration
const int num_members = 12; //change if needed
const int num_days = 5;
const int purchases_a_day[] = {13, 12, 10, 12, 13};
Item **items;
int num_items;
Member **members; //sexy right?
Trip **trips; //it's ra1ning 2-dimensional arrays!
Executive *temp_e; //temprary executive member
int option; //temporary dollar, temporary cents, temporary var+2
bool running;

int main() {
	//variable initialization
	members = new Member*[num_members];
	trips = new Trip*[num_days];
	items = new Item*[MAX_ITEMS];
	for (int i = 0; i < num_days; i++) trips[i] = new Trip[purchases_a_day[i]];
	num_items = 0;
	running = true;

	Initialize_Everything(num_days, num_members, num_items, members, trips, items, purchases_a_day);

	for (int i = 0; i < num_members; i++) {
		if (members[i]->member_type == EXECUTIVE) {
			temp_e = dynamic_cast<Executive *>(members[i]);
			if (temp_e != NULL) { //don't really need this check but just in case
				cout << temp_e->rebate_amount.dollars << "." << temp_e->rebate_amount.cents << " " << temp_e->number << endl;
			}
		}
	}

	cout << "Welcome to the program!" << endl;
	while (running) {
		cout << "Please select an option:" << endl;
		cout << "1. Sales report for a day" << endl;
		cout << "2. NULL" << endl;
		cout << "3. Quantity of items" << endl;
		cout << "4. NULL" << endl;
		cout << "5. Memberships expiring" << endl;
		cout << "6. Quit" << endl;
		cin >> option;
		switch (option) {
		case 1:
			cout << "Implement this guy!" << endl << endl; //christian
			break;
		case 3:
			cout << "Implement this guy!" << endl << endl; //jose
			break;
		case 5:
			cout << "Implement this guy!" << endl << endl; //jonathin
			break;
		case 6:
			running = false;
			break;
		default:
			cout << "Could not understand option, please try again" << endl << endl;;
		}
	}
	cout << "Thanks for playing!" << endl;
	return 0;
}
