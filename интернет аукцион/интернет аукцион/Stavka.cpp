#include "Stavka.h"

int Stavka::getIDPart() {
	return IDpart;
}

int Stavka::getIDLot() {
	return IDlot;
}

void Stavka::menuStavka() {
	cout << "1.����������� ������ (10)" << endl
		<< "2.���� ������" << endl;
	int vibor;
	cin >> vibor;
	if (vibor == 1) {
		Stavka::Stavka();
	}
	else if (vibor == 2) {
		cout << "������ ������: ";
		cin >> stavka;
		Stavka::Stavka(IDpart, IDlot, stavka);
	}
	system("pause");
}

ostream& operator<< (ostream& s, Stavka& stavka) {
	s << stavka.getIDPart() << " " << stavka.getIDLot() << " " << stavka.getStavka() << endl;
	return s;
}

float Stavka::getStavka() {
	return stavka;
}