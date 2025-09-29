#include "Product.h"
#include "Item.h"
#include <iostream>
#include <vector>
using namespace std;

Product::Product(string name) {
	this->productName = name;
	this->size = 0;
	vector<Item> items;
}

void Product::addItem(string addedDate, string expDate) {
	int id = 0;
	if (!items.empty()) {
		id = items.back().getId() + 1;
	}
	Item item(addedDate, expDate, id);
	items.push_back(item);
}

bool Product::itemExists(int id) {
	for (Item item : items) {
		if (item.getId() == id) {
			return true;
		}
	}
	return false;
}

Item* Product::getItem(int id) {
	if(!itemExists(id)) {
		return nullptr;
	}
	for(auto& item : items) {
		if (item.getId() == id) {
			return &item;
		}
	}
}

bool Product::removeItem(int id) {
	if (!itemExists(id)) {
		return false;
	}

	vector<Item> newItems;
	for (Item item : items) {
		if (item.getId() != id) {
			newItems.push_back(item);
		}
	}
	items = move(newItems);
	return true;
}

vector<Item> Product::getItems() {
	return items;
}

string Product::getName() {
	return productName;
}

void Product::printItemInfo(int id) {
	if (!itemExists(id)) {
		cout << "Item with ID " << id << " not found!" << endl;
	}
	Item* item = Product::getItem(id);
	cout << "Added Date: " 
		 << item->getAddedDate() 
		 << " | Expiration Date: " 
		 << item->getExpDate() 
		 << " | ID: " 
		 << id  
		 << endl;
}

void Product::printAllItems() {
	for (Item item : items) {
		printItemInfo(item.getId());
	}
}