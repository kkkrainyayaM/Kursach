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
#include "IDGenerator.h"
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
	User() {
		name = " ";
		ID = IDGenerator::getInstance()->getUserId();
		strcpy_s(login, 15, " ");
		strcpy_s(password, 15, " ");
	};
	User(string n, char* l, char* p) {
		ID = IDGenerator::getInstance()->getUserId();
		name = n;
		strcpy_s(login, 15, l);
		strcpy_s(password, 15, p);
	}

	User(int id, string n, char* l, char* p) {
		ID = id;
		name = n;
		strcpy_s(login, 15, l);
		strcpy_s(password, 15, p);
	}
	virtual ~User() {
		//delete &name;
	}
	void setName(string name);
	void readName();
	string getName();
	void setLog();
	void setPas();
	int getID();
	void shifrPas();
	char* getLogin();
	char* getPassword();

	//friend istream& operator>> (istream& s, User& u);
	//friend ostream& operator<< (ostream& s, User& u);
};



