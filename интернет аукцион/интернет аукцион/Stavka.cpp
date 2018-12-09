#include "Stavka.h"

int Stavka::getIDPart() {
	return IDpart;
}

int Stavka::getIDLot() {
	return IDlot;
}

int Stavka::getIDStavka() {
	return IDstavka;
}

void Stavka::menuStavka() {
	cout << "1.Стандартная ставка (10)" << endl
		<< "2.Ваша ставка" << endl;
	int vibor;
	cin >> vibor;
	if (vibor == 1) {
		Stavka::Stavka();
	}
	else if (vibor == 2) {
		cout << "Размер ставки: ";
		cin >> stavka;
		Stavka::Stavka(IDstavka, IDpart, IDlot, stavka);
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

string Stavka::toString() {
	return std::to_string(stavka);
}