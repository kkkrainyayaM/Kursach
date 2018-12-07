#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "IDGenerator.h"
#include "Encryptor.cpp"
#include "Role.h"
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
	Role role;

public:
	User() {
		name = "";
		login = "";
		password = "";
	};

	User(int id, string n, string l, string p, Role role) {
		ID = id;
		name = n;
		login = l;
		password = p;
		this->role = role;
	}

	User(const User &user) {
		ID = user.ID;
		name = user.name;
		login = user.login;
		password = user.password;
		role = user.role;
	}
	virtual ~User() {
		//delete &name;
	}
	void setName(string name);
	void readName();
	string getName();
	void toString();
	void setLog();
	void setPas();
	void setRole(Role role);
	int getID();
	void setID(int id); 
	string getLogin();
	string getPassword();
	Role getRole();

};



