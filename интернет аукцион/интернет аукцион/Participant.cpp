#include "Participant.h"

void Participant::myBuy() {
	cout << "Вы вошли в личный аккаунт." << endl;
	//dopisat
}
ostream& operator<< (ostream& s, Participant& p) {
	s << p.getID() << " " << p.getLogin() << " " << p.getPassword() << " " <<
		p.getName() << " " << endl;
}