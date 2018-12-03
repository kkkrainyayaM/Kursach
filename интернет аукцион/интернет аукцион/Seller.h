#pragma once
#include "User.h"
using namespace std;
class Seller : public User {
	int raiting;

public:
	Seller() : User() {
		raiting = 0;
	};
	Seller(string n, char* l, char* p, int r) : User(n, l, p) {
		raiting = r;
	};
	~Seller() {
		//вызвать деструктор 
	}
	//void viewInf();
	//static void createLot(int idSel);
	int getRaiting();

	friend ostream& operator<< (ostream& s, Seller& seller);
};