#include <iostream>
#include "Item.h"
#include "Product.h"
#include <cctype>
#include <algorithm>

using namespace std;

vector<Product> products;

int getValidatedInt() {
	int value;
	while (true) {
		cin >> value;
		cout << endl;
		if (cin.fail()) {
			cin.clear(); // clear the fail state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			cout << "Invalid input. Please enter a number: ";
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
			return value;
		}
	}
}

void addProduct(string name) {
	Product product(name);
	products.push_back(product);
}

bool productExists(string name) {
	for (Product product : products) {
		if (product.getName()._Equal(name)) {
			return true;
		}
	}
	return false;
}

bool removeProduct(string name) {
	if (!productExists(name)) {
		return false;
	}
	vector<Product> newProducts;
	for (Product product : products) {
		if (!product.getName()._Equal(name)) {
			newProducts.push_back(product);
		}
	}
	products = move(newProducts);
	return true;
}

void printProductNames() {
	for (Product product : products) {
		cout << product.getName() << endl;
	}
}

Product* getProduct(string name) {
	if (!productExists(name)) {
		return nullptr;
	}
	for (auto& product : products) {
		if (product.getName()._Equal(name)) {
			return &product;
		}
	}
	return nullptr;
}

string toLowerCase(string s) {
	transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return tolower(c); });
	return s;
}

int main() {
	string productName;
	int id;
	int input;
	string addedDate;
	string expDate;
	string yn;
	vector<Item> items;
	cout << "***SIMPLE INVENTORY MANAGEMENT***" << endl
		<< "   An adaptation of an earlier   " << endl
		<< "    project from Java to C++     " << endl
		<< endl;
	bool exit = false;
	do {
		cout << "VALID COMMANDS: new (1), list (2), remove (3), exit (4)" << endl;
		input = getValidatedInt();
		cout << endl;
		switch (input) {
			case (1):
				cout << "VALID OPTIONS: product (1), item (2)" << endl;
				input = getValidatedInt();
				cout << endl;
				switch (input) {
					case(1):
						cout << "Enter a product name: ";
						cin >> productName;
						cout << endl;
						productName = toLowerCase(productName);
						if (productExists(productName)) {
							cout << endl << "Product already exists!" << endl;
							break;
						}
						addProduct(productName);
						cout << "Product \"" << productName << "\" created successfully." << endl;
						break;
					case(2):
						cout << "VALID PRODUCTS: " << endl;
						printProductNames();
						cout << "Enter the name of the product in which you wish to add an item: ";
						cin >> productName;
						cout << endl;
						productName = toLowerCase(productName);
						if (!productExists(productName)) {
							cout << "Product does not exist!" << endl;
							break;
						}
						cout << "Enter the date (MM/DD/YYYY): ";
						cin >> addedDate;
						cin.clear();
						cout << endl << "Enter the expiration date (MM/DD/YYYY): ";
						cin >> expDate;
						cin.clear();
						getProduct(productName)->addItem(addedDate, expDate);
						items = getProduct(productName)->getItems();
						id = items[items.size() - 1].getId();
						cout << endl << "Added item with id " << id << endl;
						break;
					default:
						cout << "Invalid input!" << endl;
						break;
				}
				break;
			case(2):
				cout << "VALID OPTIONS: products (1), items (2)" << endl;
				input = getValidatedInt();
				cout << endl;
				switch (input) {
					case(1):
						cout << "ALL PRODUCTS:" << endl;
						printProductNames();
						break;
					case(2):
						cout << "VALID PRODUCTS: " << endl;
						printProductNames();
						cout << "Enter the name of the product in which you wish to list all items: ";
						cin >> productName;
						cout << endl;
						productName = toLowerCase(productName);
						if (!productExists(productName)) {
							cout << "Product does not exist!" << endl;
							break;
						}
						cout << "ALL ITEMS IN PRODUCT \"" << productName << "\":" << endl;
						getProduct(productName)->printAllItems();
						break;
					default:
						cout << "Invalid input!" << endl;
						break;
				}
				break;
			case(3):
				cout << "VALID OPTIONS: product (1), item (2)" << endl;
				input = getValidatedInt();
				cout << endl;
				switch (input) {
				case(1):
					cout << "VALID PRODUCTS:" << endl;
					printProductNames();
					cout << "Enter the name of the product that you wish to remove: ";
					cin >> productName;
					cout << endl;
					productName = toLowerCase(productName);
					if (!productExists(productName)) {
						cout << endl << "Product does not exist!" << endl;
						break;
					}
					cout << "WARNING: Deleting this product will also delete all items within the product. This cannot be undone. Would you like to continue? (y/n): ";
					cin >> yn;
					cout << endl;
					if (yn._Equal("y")) {
						removeProduct(productName);
						cout << "Product \"" << productName << "\" removed successfully." << endl;
						break;
					}
					else if (yn._Equal("n")) {
						cout << "Operation cancelled." << endl;
						break;
					}
					else {
						cout << "Invalid input!" << endl;
						cout << "Operation cancelled." << endl;
						break;
					}

				case(2):
					cout << "VALID PRODUCTS: " << endl;
					printProductNames();
					cout << "Enter the name of the product in which you wish to remove an item: ";
					cin >> productName;
					cout << endl;
					productName = toLowerCase(productName);
					if (!productExists(productName)) {
						cout << "Product does not exist!" << endl;
						break;
					}
					cout << "ITEMS IN \"" << productName << "\":" << endl;
					getProduct(productName)->printAllItems();
					cout << "Type the ID of the item you wish to remove: ";
					input = getValidatedInt();
					cout << endl;
					if (getProduct(productName)->itemExists(input)) {
						cout << "Are you sure you would like to delete ID " << input << "? This cannot be undone. (y/n) ";
						cin >> yn;
						cout << endl;
						if (yn._Equal("y")) {
							getProduct(productName)->removeItem(input);
							cout << "Item with ID " << input << " removed successfully." << endl;
							break;
						}
						else if (yn._Equal("n")) {
							cout << "Operation cancelled." << endl;
							break;
						}
						else {
							cout << "Invalid input!" << endl;
							cout << "Operation cancelled." << endl;
							break;
						}
					}
					else {
						cout << "Item with ID " << input << " could not be found!" << endl;
						break;
					}
				default:
					cout << "Invalid input!" << endl;
					break;
				}
				break;
			case(4):
				exit = true;
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Invalid command!" << endl;
				break;
		}
	} while (!exit);
	
	return 0;
}