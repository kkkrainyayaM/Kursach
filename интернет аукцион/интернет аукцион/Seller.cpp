#include "Seller.h"
//
//void Seller::printInf(User *user) {
//	user->toString();
//    cout << "�� ����� � ������ �������." << endl;
//	char w = NULL;
//	cout.fill('*');
//	//cout << "��� �������: " << setw(user->getRaiting()) << " (" << user->getRaiting() << ")" << endl;
//
//	//DAO::getIDLotByIDSel(ID);
//	//cout << "���� ������:" << endl;
//
//	//Lot::cout << "��������: " << title << endl << "��������: " << d[r] << endl
//	//	<< "��������� ����: " << s[r] << endl << "������������ ������: " << m[r] << endl
//	//	<< "����-����: " << b[r] << endl;
//
//	//cout << "�������� ���!" << endl << "�������� ���?(1 - ��/ 2 - ���)";
//	//int v;
//	//cin >> v;
//	////if (v == 1) Seller::createLot();
//	//		cout << "��� ������ ������� Esc.";
//	//		cin >> w;
//	//		if (w == 27)break;
//	//	}
//}
//void Seller::createLot(int idSel) {
//	Lot l;
//	int q = 1, i = 0;
//	while (q == 1) {
//		Mapper m1;
//		l.setID();
//		int idLot = l.getID();
//		l.setLot();
//		m1.setSelLot(idSel, idLot);
//		cout << "��� ������� ��������!" << endl << "���������� - 1. ����� - 0";
//		cin >> q;
//		if (q == 1) Seller::createLot(idSel);
//		else break;
//	}
//}

//istream& Seller::operator>> (istream& s,const Seller& seller) {
//	s << seller.getID() << ' ';
//	s << seller.getLogin() << ' '
//	return s;
//}

int Seller::getRaiting() {
	return this->raiting;
}

void Seller::toString() {
	cout << "���: " << getName() << endl
		<< "�����: " << getLogin() << endl
		<< "������: " << getPassword() << endl;
}

ostream& operator<< (ostream& s, Seller& seller) {
	s << seller.getID() << " " << seller.getLogin() << " " << seller.getPassword() << " " <<
		seller.getName() << " " << seller.getRaiting() << endl;
	return s;
}

