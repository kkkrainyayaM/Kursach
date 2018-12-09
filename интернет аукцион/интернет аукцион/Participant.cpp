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
	cout << setw(8) << "Имя: " << setw(10) << getName() << endl
		<< setw(8) << "Логин: " << setw(10) << getLogin() << endl
		<< setw(8) << "Пароль: " << setw(10) << getPassword() << endl;
}