#include "AuthService.h"
#include "DAO.cpp"

	AuthService* AuthService::getAuthInstance() {
		if (instance == NULL) {
			instance = new AuthService();
		}
		return instance;
	}

	void AuthService::setCurrentUser(User& user) {
		currentUser = user; //������� ������ �� �������� ����������� �����������, ����� ���������
	}

	User& AuthService::getCurrentUser() {
		return this->currentUser;
	}
    
	void AuthService::auth() {
		string login, password;
		User* user = nullptr;
		while (user == nullptr) {
			system("cls");
			cout << "�����: ";
			cin >> login;
			user = DAO::getInstance()->getUserByLogin(login);
			if (user == nullptr) {
				cout << "������������ � ����� login �� �������!" << endl;
				_getch();
			}
		}
		cout << "������: ";
		cin >> password;
		while (!Encryptor::isEqual(password, user->getPassword())) {
			cout << "�������� ������!";
			cout << "������: ";
			cin >> password;
		}
		currentUser = *user;
	}
	AuthService* AuthService::instance = 0;