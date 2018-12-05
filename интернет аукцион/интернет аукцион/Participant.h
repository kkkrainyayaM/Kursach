#pragma once
#include "User.h"
class Participant : public User {
public:
	Participant() {
	}
	Participant(string n, char* l, char* p) : User(n, l, p) {
	}
	Participant(int ID, string n, char* l, char* p) : User(n, l, p) {
	}
	~Participant() {
		User::~User();
	}
	void myBuy();


	friend ostream& operator<< (ostream& s, Participant& p);
};