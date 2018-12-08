#pragma once
#include "User.h"
using namespace std;
class Seller : public User {

public:
	Seller() : User() {
	};
	Seller(int id, string n, string l, string p) : User(id, n, l, p, Role::SELLER) {
	};

	Seller(const Seller& seller) : User(seller) {
	}

	~Seller() {
		User::~User();
	}
	void toString();

	void printInfo() {
		cout << "Èìÿ: " << getName() << endl;
	}

	friend ostream& operator<< (ostream& s, Seller& seller);
};