#include "Seller.h"

//void Seller::viewInf() {
//	char w = NULL;
//	cout << name << ", �� ����� � ������ �������." << endl;
//	cout << "��� �����: " << login << endl;
//	cout.fill('*');
//	cout << "��� �������: " << setw(raiting) << "(" << raiting << ")" << endl;
//	const int len = 4;
//	const char ch = '\n', pr = ' ';
//	char sel[len];
//	char lot[len];
//	char part[len];
//	int lots[5], q = 0;
//	ifstream file1("ID.txt", ios::in | ios::binary);
//	if (!file1.is_open()) cout << "���� �� ����� ���� ������!\n";
//	while (!(file1.eof())) {
//		for (int r = 0; r < file1.eof(); r++)
//		{
//			file1 >> sel[r];
//			file1 >> lot[r];
//			file1 >> part[r];
//			//file >> ch;
//			if (sel[r] == ID) {
//				lots[q] = lot[r];
//				q++;
//			}
//		}
//	}
//	file1.close();
//	cout << "���� ������:" << endl;
//	ifstream file2("lots.txt", ios::in | ios::binary);
//	if (!file2.is_open()) cout << "���� �� ����� ���� ������!\n";
//	int id[20], p = 0;
//	string t[20], d[20];
//	float s[20], m[20], b[20];
//	while (!(file2.eof())) {
//		for (int r = 0; r < file2.eof(); r++) {
//			file2 >> id[r];
//			file2 >> t[r];
//			file2 >> d[r];
//			file2 >> s[r];
//			file2 >> m[r];
//			file2 >> b[r];
//			for (q = 0; q < 5; q++) {
//				if (id[r] == lots[q]) {
//					cout << "��������: " << t[r] << endl << "��������: " << d[r] << endl
//						<< "��������� ����: " << s[r] << endl << "������������ ������: " << m[r] << endl
//						<< "����-����: " << b[r] << endl;
//					p++;
//				}
//				else {
//					cout << "�������� ���!" << endl << "�������� ���?(1 - ��/ 2 - ���)";
//					int v;
//					cin >> v;
//					if (v == 1) Seller::createLot();
//				}
//			}
//			cout << "��� ������ ������� Esc.";
//			cin >> w;
//			if (w == 27)break;
//		}
//	}
//	file2.close();
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
}
