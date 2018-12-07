#pragma once
#include "User.h"
class Participant : public User {
public:
	Participant() {
	}
	Participant(int id, string n, string l, string p) : User(id, n, l, p, Role::PARTICIPANT) {
	}
	~Participant() {
		User::~User();
	}
	void myBuy();


	friend ostream& operator<< (ostream& s, Participant& p);
};