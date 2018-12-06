#include "User.h"
#include "Lot.h"

void User::setName(string name) {
	this->name = name;
}

void User::readName() {
	//std::string name;
	cin.clear();
	cout << "���� ���: ";
	cin >> name;
	//getline(cin, name);
	//setName(name);
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





