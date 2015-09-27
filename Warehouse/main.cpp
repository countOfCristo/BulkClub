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

using namespace std;

const int num_members = 12; //change if needed
const int num_days = 5;
const int purchases_a_day[] = {13, 12, 10, 12, 13};

int main() {
	Member **members; //sexy right?
	ifstream infile("res/warehouse_shoppers.txt");
	ifstream **days;
	Trip **trips;
	string line, name;
	int id, iterator;

	members = new Member*[num_members];
	trips = new Trip*[num_days];
	days = new ifstream*[num_days];
	for (char i = 49; i < num_days + 49; i++) days[i - 49] = new ifstream(string("res/day" + string(1, i) + ".txt").c_str());
	for (int i = 0; i < num_days; i++) trips[i] = new Trip[purchases_a_day[i]];
	iterator = 0;


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

	for (int i = 0; i < num_days; i++) {
		for (int k = 0; k < purchases_a_day[i]; k++) {
			getline(*days[i], line);
			//date
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
			trips[i][k].item_name = line;
			//price + quantity
			getline(*days[i], line);
			cout << line.substr(0, line.find('.')) << " " << line.substr(line.find('.') + 1, 2) << endl;
		}
	}

	for (int i = 0; i < num_days; i++) {
			for (int k = 0; k < purchases_a_day[i]; k++) {
				cout << trips[i][k].item_name << endl;
			}
	}
	return 0;
}
