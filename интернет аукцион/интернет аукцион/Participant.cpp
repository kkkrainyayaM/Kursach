#include "Participant.h"

void Participant::myBuy() {
	cout << "�� ����� � ������ �������." << endl;
	//dopisat
}
ostream& operator<< (ostream& s, Participant& p) {
	s << p.getID() << " " << p.getLogin() << " " << p.getPassword() << " " <<
		p.getName() << " " << endl;
	return s;
}

void Participant::toString() {
	cout << setw(8) << "���: " << setw(10) << getName() << endl
		<< setw(8) << "�����: " << setw(10) << getLogin() << endl
		<< setw(8) << "������: " << setw(10) << getPassword() << endl;
}