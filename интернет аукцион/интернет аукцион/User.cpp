#include "User.h"
#include "Lot.h"

void User::setName(string name) {
	this->name = name;
}

void User::readName() {
	std::string name;
	cin.clear();
	cout << "���� ���: ";
	getline(cin, name);
	setName(name);
}

string User::getName() {
	return this->name;
}

int User::getID() {
	return ID;
}
void User::setLogPas() {
	cout << "������� �����: ";
	cin.getline(login, 15);
	int q = 0;
	while (q == 0) {
		cout << "������� ������: "; cin.getline(password, 15);
		if ((strlen(password) > 4) || (strlen(password) < 14)) {
			q = 1;
			break;
		}
		else {
			cout << "��������� ����! ����� ������ �� ������ ���� ������ 5 � ������ 15 ��������!" << endl;
			cin.clear();
		}
	}
	shifrPas();
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
					password[n] = alf[i + 4];//�������� ������ �� 4
				break;//������������� ������� �� �����
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





