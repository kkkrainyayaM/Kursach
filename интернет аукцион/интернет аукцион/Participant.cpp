#include "Participant.h"

void Participant::myBuy() {
	cout << "�� ����� � ������ �������." << endl;
	//dopisat
}
ostream& operator<< (ostream& s, Participant& p) {
	s << p.getID() << " " << p.getLogin() << " " << p.getPassword() << " " <<
		p.getName() << " " << endl;
}