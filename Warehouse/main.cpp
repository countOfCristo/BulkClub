/*
 * The project... nuff said
 */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Member.h"
#include "Regular.h"
#include "Executive.h"
#include "Trip.h"
#include "Item.h"

//this is happening, cry about it
#define MAX_ITEMS 256

using namespace std;

//variable declaration
const int num_members = 12; //change if needed
const int num_days = 5;
const int purchases_a_day[] = {13, 12, 10, 12, 13};
ifstream infile("res/warehouse_shoppers.txt");
ifstream **days;
Item **items;
int num_items;
Member **members; //sexy right?
Trip **trips; //it's ra1ning 2-dimensional arrays!
Item *temp_i;
Member *temp_m;
string line, name;
int id, option;
bool running;

Item* search_for_item(string name, Item **is, int num) { //we should probably consider making this more efficient
	int iterator = 0;
	while (iterator < num && is[iterator]->item_name != name) { iterator++; }
	return (iterator >= num) ? NULL : items[iterator];
}

Member* search_for_member(int ID) { //also consider making this more efficient as well
	int iterator = 0;
	while (iterator < num_members && members[iterator]->number != ID) { iterator++; }
	return (iterator >= num_members) ? NULL : members[iterator];
}

int main() {
	int iterator; //this variable was being bad declared outside for some reason

	//variable initialization
	members = new Member*[num_members];
	trips = new Trip*[num_days];
	days = new ifstream*[num_days];
	items = new Item*[MAX_ITEMS];
	for (char i = 49; i < num_days + 49; i++) days[i - 49] = new ifstream(string("res/day" + string(1, i) + ".txt").c_str());
	for (int i = 0; i < num_days; i++) trips[i] = new Trip[purchases_a_day[i]];
	iterator = 0;
	num_items = 0;
	running = true;

	//getting data from res/warehouse_shoppers.txt and populating array members
	while (getline(infile, line)) {
		//name
		name = line;
		//ID
		getline(infile, line);
		id = atoi(static_cast<const char*>(line.c_str()));
		//Type
		getline(infile, line);
		if (line[0] == 'E') members[iterator] = new Executive();
		else members[iterator] = new Regular();
		members[iterator]->name = name;
		members[iterator]->number = id;
		members[iterator]->items_purchased = new Item[MAX_ITEMS];
		members[iterator]->number_items_purchased = 0;
		//date
		getline(infile, line);
		members[iterator]->expiration_date.month =
				atoi(static_cast<const char*>(line.substr(0, 2).c_str()));
		members[iterator]->expiration_date.day =
				atoi(static_cast<const char*>(line.substr(3, 2).c_str()));
		members[iterator]->expiration_date.year =
				atoi(static_cast<const char*>(line.substr(6, 4).c_str()));

		iterator++;
	}

	//getting data from day1-5.txt and populating arrays items and trips
	for (int i = 0; i < num_days; i++) {
		for (int k = 0; k < purchases_a_day[i]; k++) {
			getline(*days[i], line);
			//date
			//these are not real two dimensional arrays, don't be fooled
			trips[i][k].purchase_date.month =
					atoi(static_cast<const char*>(line.substr(0, 2).c_str()));
			trips[i][k].purchase_date.day =
					atoi(static_cast<const char*>(line.substr(3, 2).c_str()));
			trips[i][k].purchase_date.year =
					atoi(static_cast<const char*>(line.substr(6, 4).c_str()));
			//ID
			getline(*days[i], line);
			trips[i][k].id = atoi(static_cast<const char*>(line.c_str()));
			//name
			getline(*days[i], line);
			temp_i = search_for_item(line, items, num_items);
			if (temp_i != NULL) {
				trips[i][k].item = temp_i;
				//quantity
				getline(*days[i], line);
				trips[i][k].quantity = atoi(static_cast<const char*>(line.substr(line.find('.')+ 3).c_str()));
				temp_i->quantity_sold += trips[i][k].quantity;
			} else {
				items[num_items] = new Item();
				items[num_items]->quantity_sold = 0;
				items[num_items]->item_name = line;
				getline(*days[i], line);
				//price
				items[num_items]->price.dollars = atoi(static_cast<const char*>(line.substr(0, line.find('.')).c_str()));
				items[num_items]->price.cents = atoi(static_cast<const char*>(line.substr(line.find('.') + 1, 2).c_str()));
				trips[i][k].item = items[num_items];
				//quantity
				trips[i][k].quantity = atoi(static_cast<const char*>(line.substr(line.find('.')+ 3).c_str()));
				items[num_items]->quantity_sold += trips[i][k].quantity;
				num_items++;
			}
		}
	}

	//processing days 1-5
	for (int i = 0; i < num_days; i++) {
		for (int k = 0; k < purchases_a_day[i]; k++) {
			temp_m = search_for_member(trips[i][k].id);
			if (temp_m != NULL) {
				temp_m->items_purchased[temp_m->number_items_purchased].item_name = trips[i][k].item->item_name;
				temp_m->items_purchased[temp_m->number_items_purchased].price = trips[i][k].item->price;
				temp_m->items_purchased[temp_m->number_items_purchased].quantity_sold = trips[i][k].item->quantity_sold;
				temp_m->number_items_purchased++;

				//temp_m->total_spent.dollars = temp_m->items_purchased[temp_m->number_items_purchased].price.dollars *


				//temp_m->total_spent.dollars
				//temp_m->total_spent.dollars
				if (temp_m->member_type == EXECUTIVE) {

				}
			}
		}
	}

	cout << "Welcome to the program!" << endl;
	while (running) {
		cout << "Please select an option:" << endl;
		cout << "1. Sales report for a day" << endl;
		cout << "2. Quit" << endl;
		cin >> option;
		switch (option) {
		case 1:
			cout << "Implement this guy!" << endl << endl; //christian
			break;
		case 2:
			running = false;
			break;
		default:
			cout << "Could not understand option, please try again" << endl << endl;;
		}
	}
	cout << "Thanks for playing!" << endl;
	return 0;
}
