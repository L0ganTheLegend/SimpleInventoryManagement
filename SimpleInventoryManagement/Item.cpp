#include "Item.h"
#include <iostream>
using namespace std;
Item::Item(string addedDate, string expDate, int id) {
	this->addedDate = addedDate;
	this->expDate = expDate;
	this->id = id;
}

string Item::getAddedDate() {
	return addedDate;
}

string Item::getExpDate() {
	return expDate;
}

int Item::getId() {
	return id;
}

void Item::setAddedDate(string newAddedDate) {
	addedDate = newAddedDate;
}

void Item::setExpDate(string newExpDate) {
	expDate = newExpDate;
}

void Item::setId(int newId) {
	id = newId;
}