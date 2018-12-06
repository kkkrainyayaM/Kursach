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
		cout << "Введите пароль: "; cin>>password;
		if ((strlen(password) > 4) & (strlen(password) < 14)) {
			q = 1;
			break;
		}
		else {
			cout << "Повторите ввод! Длина пароля не должна быть меньше 5 и больше 15 символов!" << endl;
			cin.clear();
		}
	}
}

void User::shifrPas() {
	int i = 0;
	char alf[] = "abcedfghijklmnopqrstuvwxyz0123456789#!@$%^&*-+=";
	for (unsigned int n = 0; n < strlen(password) + 1; n++)
	{
		for (i = 0; i < 47; i++)
		{
			if (password[n] == alf[i])
			{
				if (i >= 47)
					password[n] = alf[i - 47];
				else
					password[n] = alf[i + 4];//сдвигаем вправо на 4
				break;//принудительно выходим из цикла
			}
		}
	}
}

char* User::getLogin() {
	return this->login;
}
char* User::getPassword() {
	return this->password;
}





