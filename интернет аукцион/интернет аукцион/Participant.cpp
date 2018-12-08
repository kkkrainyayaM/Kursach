#include "Participant.h"

void Participant::myBuy() {
	cout << "Вы вошли в личный аккаунт." << endl;
	//dopisat
}
ostream& operator<< (ostream& s, Participant& p) {
	s << p.getID() << " " << p.getLogin() << " " << p.getPassword() << " " <<
		p.getName() << " " << endl;
	return s;
}

void Participant::toString() {
	cout << "Имя: " << getName() << endl
		<< "Логин: " << getLogin() << endl
		<< "Пароль: " << getPassword() << endl;
}