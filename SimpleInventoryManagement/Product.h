#include <iostream>
#include "Item.h"
#include <vector>
#pragma once
using namespace std;
class Product {
	private:
		vector<Item> items;
	public:
		string productName;
		int size;
		Product(string name);
		void addItem(string addedDate, string expDate);
		bool itemExists(int id);
		Item* getItem(int id);
		bool removeItem(int id);
		vector<Item> getItems();
		string getName();
		void printItemInfo(int id);
		void printAllItems();

};