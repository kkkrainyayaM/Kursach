#include "User.h"
void User::setName(string name) {
	this->name = name;
}

void User::readName() {
	cin.clear();
	cout << "���� ���: ";
	cin >> name;
}

string User::getName() {
	return this->name;
}

int User::getID() {
	return ID;
}
void User::setLog() {
	cin.clear();
	cout << "������� �����: ";
	cin >> login;
}

void User::setID(int id) {
	ID = id;
}

void User::setPas() {
	int q = 0;
	while (q == 0) {
		cout << "������� ������: "; 
		cin >> password;
		if ((password.length() > 4) && (password.length() < 14)) {
			q = 1;
			break;
		}
		else {
			cout << "��������� ����! ����� ������ �� ������ ���� ������ 5 � ������ 15 ��������!" << endl;
			cin.clear();
		}
	}
	Encryptor::codePassword(&password);
}

string User::getLogin() {
	return this->login;
}
string User::getPassword() {
	return this->password;
}

void User::setRole(Role role) {
	this->role = role;
}

void User::toString() {
	Encryptor::decodePassword(&password);
	cout << setw(8) << "���: " << setw(10) << name << endl
		<< setw(8) << "�����: " << setw(10) << login << endl
		<< setw(8) << "������: " << setw(10) << password  << endl;
}

Role User::getRole() {
	return role;
}