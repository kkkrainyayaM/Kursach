#include "AuthService.h"
#include "DAO.cpp"

	AuthService* AuthService::getAuthInstance() {
		if (instance == NULL) {
			instance = new AuthService();
		}
		return instance;
	}

	void AuthService::setCurrentUser(User& user) {
		currentUser = user; //странно почему не вызвался конструктор копирования, нужно погуглить
	}

	User& AuthService::getCurrentUser() {
		return this->currentUser;
	}
    
	void AuthService::auth() {
		string login, password;
		User* user = nullptr;
		while (user == nullptr) {
			system("cls");
			cout << "Логин: ";
			cin >> login;
			user = DAO::getInstance()->getUserByLogin(login);
			if (user == nullptr) {
				cout << "Пользователя с таким login не найдено!" << endl;
				_getch();
			}
		}
		cout << "Пароль: ";
		cin >> password;
		while (!Encryptor::isEqual(password, user->getPassword())) {
			cout << "Неверный пароль!";
			cout << "Пароль: ";
			cin >> password;
		}
		currentUser = *user;
	}
	AuthService* AuthService::instance = 0;