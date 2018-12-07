#pragma once
#include "User.h"
using namespace std;
class Seller : public User {
	int raiting;

public:
	Seller() : User() {
		raiting = 0;
	};
	Seller(int id, string n, string l, string p, int r) : User(id, n, l, p, Role::SELLER) {
		raiting = r;
	};

	Seller(const Seller& seller) : User(seller) {
		raiting = seller.raiting;
	}

	~Seller() {
		User::~User();
	}
	int getRaiting();
	void toString();

	void printInfo() {
		cout << "Имя: " << getName() << endl;
		cout << "Рейтинг: " << getRaiting() << endl;
	}

	friend ostream& operator<< (ostream& s, Seller& seller);
};