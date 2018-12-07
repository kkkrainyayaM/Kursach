#pragma once
#include "User.h"
using namespace std;
class Seller : public User {
	int raiting;

public:
	Seller() : User() {
		raiting = 0;
	};
	//Seller(string n, string l, string p, int r) : User(n, l, p) {
	//	raiting = r;
	//};
	Seller(int id, string n, string l, string p, int r) : User(id, n, l, p, Role::SELLER) {
		raiting = r;
	};

	Seller(const Seller& seller) : User(seller) {
		raiting = seller.raiting;
	}

	~Seller() {
		User::~User();
	}
	//static void viewInf();
	//static void createLot(int idSel);
	int getRaiting();

	friend ostream& operator<< (ostream& s, Seller& seller);
};