#include "User.h"
#include "Lot.h"

void User::setName(string name) {
	this->name = name;
}

void User::readName() {
	//std::string name;
	cin.clear();
	cout << "Ваше Имя: ";
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
	cout << "Введите логин: ";
	cin >> login;
}

void User::setPas() {
	int q = 0;
	while (q == 0) {
		cout << "Введите пароль: "; 
		cin >> password;
		if ((password.length() > 4) && (password.length() < 14)) {
			q = 1;
			break;
		}
		else {
			cout << "Повторите ввод! Длина пароля не должна быть меньше 5 и больше 15 символов!" << endl;
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





