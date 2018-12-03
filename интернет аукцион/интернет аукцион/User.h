#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;
using std::string;
#if defined(max)
#undef max
#endif


class User {
private:

	int ID;
	string name;
	char login[15];
	char password[15];

public:
	//static int status;
	User() {
		name = " ";
		ID = 0;
		strcpy_s(login, 15, " ");
		strcpy_s(password, 15, " ");
	};
	User(int id) {
		ID = id;
	}
	User(int id, string n, char* l, char* p) {
		ID = id;
		name = n;
		strcpy_s(login, 15, l);
		strcpy_s(password, 15, p);
	}
	virtual ~User() {
		delete &name;
	}
	virtual void setName() = 0;
	virtual void getName(int id) = 0;
	void setLogPas();
	virtual void setID() = 0;
	virtual int getID(int id) = 0;
	void shifrPas();

	friend istream& operator>> (istream& s, User& u);
	friend ostream& operator<< (ostream& s, User& u);
};

class Seller : public User {
	int raiting;

public:
	Seller() {
		raiting = 0;
	};
	Seller(int id, string n, char* l, char* p, int r) : User(id, n, l, p) {
		raiting = r;
	};
	~Seller() {
		delete &name;
	}
	void setName();
	void getName(int id);
	void setID();
	int retID();
	int getID(int id);
	void viewInf();
	static void createLot(int idSel);

	friend istream& operator>> (istream& q, Seller& s);
	friend ostream& operator<< (ostream& q, Seller& s);
};

class Participant : public User {
	float stavka;
public:
	Participant() {
		stavka = 0;
	}
	Participant(int id, string n, char* l, char* p, float st) : User(id, n, l, p) {
		stavka = st;
	}
	~Participant() {
		delete &name;
	}
	void setName();
	void getName(int id);
	void setID();
	int retID();
	int getID(int id);
	void myBuy();


	friend istream& operator>> (istream& s, Participant& p);
	friend ostream& operator<< (ostream& s, Participant& p);
};