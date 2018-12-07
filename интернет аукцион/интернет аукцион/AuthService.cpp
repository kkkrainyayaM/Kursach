#include "AuthService.h"
#include "DAO.cpp"

	AuthService AuthService::getAuthInstance() {
		static AuthService authInstance;
		return authInstance;
	}

	void AuthService::setCurrentUser(User user) {
		currentUser = user;
	}

	User AuthService::getCurrentUser() {
		return currentUser;
	}
    
	void AuthService::auth() {
		string login, password;
		User* user = nullptr;
		while (user == nullptr) {
			system("cls");
			cout << "Login: ";
			cin >> login;
			user = DAO::getInstance()->getUserByLogin(login);
			if (user == nullptr) {
				cout << "������������ � ����� login �� �������!" << endl;
				_getch();
			}
		}
		cout << "Password: ";
		cin >> password;
		while (!Encryptor::isEqual(password, user->getPassword())) {
			cout << "�������� ������!";
			cout << "Password: ";
			cin >> password;
		}
		currentUser = *user;
	}
