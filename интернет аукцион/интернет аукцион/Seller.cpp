#include "Seller.h"
#include "User.h"

//void Seller::viewInf() {
//	char w = NULL;
//	cout << name << ", �� ����� � ������ �������." << endl;
//	cout << "��� �����: " << login << endl;
//	cout.fill('*');
//	cout << "��� �������: " << setw(raiting) << "(" << raiting << ")" << endl;
//
//	DAO::getIDLotByIDSel(ID);//
//	cout << "���� ������:" << endl;
//
//	cout << "��������: " << t[r] << endl << "��������: " << d[r] << endl
//		<< "��������� ����: " << s[r] << endl << "������������ ������: " << m[r] << endl
//		<< "����-����: " << b[r] << endl;
//
//	cout << "�������� ���!" << endl << "�������� ���?(1 - ��/ 2 - ���)";
//	int v;
//	cin >> v;
//	//if (v == 1) Seller::createLot();
//			cout << "��� ������ ������� Esc.";
//			cin >> w;
//			if (w == 27)break;
//		}
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

ostream& operator<< (ostream& s, Seller& seller) {
	s << seller.getID() << " " << seller.getLogin() << " " << seller.getPassword() << " " <<
		seller.getName() << " " << seller.getRaiting() << endl;
	return s;
}

