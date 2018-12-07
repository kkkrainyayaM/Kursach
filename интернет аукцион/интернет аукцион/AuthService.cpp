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
				cout << "Пользователя с таким login не найдено!" << endl;
				_getch();
			}
		}
		cout << "Password: ";
		cin >> password;
		while (!Encryptor::isEqual(password, user->getPassword())) {
			cout << "Неверный пароль!";
			cout << "Password: ";
			cin >> password;
		}
		currentUser = *user;
	}
