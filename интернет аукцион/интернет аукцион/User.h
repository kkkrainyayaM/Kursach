#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "IDGenerator.h"
#include "Encryptor.cpp"
using namespace std;
using std::string;
#if defined(max)
#undef max
#endif


class User {
private:

	int ID;
	string name;
	string login;
	string password;

public:
	User() {
		name = "";
		login = "";
		password = "";
	};
	//User(string n, string l, string p) {
	//	ID = IDGenerator::getInstance()->getUserId();
	//	name = n;
	//	login = l;
	//	password = p;
	//}

	User(int id, string n, string l, string p) {
		ID = id;
		name = n;
		login = l;
		password = p;
	}

	User(const User &user) {
		ID = user.ID;
		name = user.name;
		login = user.login;
		password = user.password;
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
	void setID(int id); 
	string getLogin();
	string getPassword();
};



