#pragma once
#include "User.h"
class Participant : public User {
public:
	Participant() {
	}
	Participant(int id, string n, char* l, char* p) : User(n, l, p) {
	}
	~Participant() {
		//������� ���������� �����
	}
	void myBuy();

	friend ostream& operator<< (ostream& s, Participant& p);
};