#include <iostream>
#pragma once
using namespace std;
class Item {
	public:
		string addedDate;
		string expDate;
		int id;
		Item(string addedDate, string expDate, int id);
		string getAddedDate();
		string getExpDate();
		int getId();
		void setAddedDate(string newAddedDate);
		void setExpDate(string newExpDate);
		void setId(int newId);
};