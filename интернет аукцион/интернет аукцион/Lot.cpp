#include "Lot.h"
//void Lot::setID() {
//	const int LEN = 4;
//	const char CH = '\n', SPACE = ' ';
//	int  q = 0;
//	char sel[LEN];
//	char lot[LEN];
//	char part[LEN];
//	fstream file("ID.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "���� �� ����� ���� ������!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++)
//		{
//			file >> sel[r];
//			file >> lot[r];
//			file >> part[r];
//			//file >> ch;
//			q++;
//		}
//		if (lot[q] == 0) ID = 300;
//		else { ID = lot[q] + 1; };
//	}
//	file << ID << ' ';
//	file.close();
//}
int Lot::getID() {
	return ID;
}
//void Lot::printLots() {
//	int id[20];
//	string t[20], d[20];
//	float s[20], m[20], b[20];
//	fstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "���� �� ����� ���� ������!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++) {
//			file >> id[r];
//			file >> t[r];
//			file >> d[r];
//			file >> s[r];
//			file >> m[r];
//			file >> b[r];
//			cout << "��������: " << t[r] << endl << "��������: " << d[r] << endl
//				<< "��������� ����: " << s[r] << endl << "������������ ������: " << m[r] << endl
//				<< "����-����: " << b[r] << endl;
//		}
//	}
//	file.close();
//	cout << "������� 0 ��� �������� � ����.";
//	int q;
//	cin >> q;
//	if (q == 0) Menu::menuSel();
//}
//void Lot::setLot() {
//	cout << "���������� ������" << endl << "��������: ";
//	cin >> title;
//	cout << "\n��������: ";
//	cin >> descr;
//	cout << "\n��������� ����: ";
//	cin >> startPrice;
//	cout << "\n����-����: ";
//	cin >> blicPrice;
//	cout << "\n������ ������: ";
//	cin >> period;
//}
//void Lot::filtr() {
//	float ot, doo;
//	int id[20], q = 1;
//	string t[20], d[20];
//	float s[20], m[20], b[20];
//	ifstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "���� �� ����� ���� ������!\n";
//	while (q == 1) {
//		cout << "���������� �� ������������ ������� ������." << endl << "������� �������� ��������:" << endl << "�� ";
//		cin >> ot;
//		cout << endl << "�� ";
//		cin >> doo;
//
//		while (!(file.eof())) {
//			for (int r = 0; r < file.eof(); r++) {
//				file >> id[r];
//				file >> t[r];
//				file >> d[r];
//				file >> s[r];
//				file >> m[r];
//				file >> b[r];
//				if (m[r] > ot || m[r] < doo) {
//					cout << "��������: " << t[r] << endl << "��������: " << d[r] << endl
//						<< "��������� ����: " << s[r] << endl << "������������ ������: " << m[r] << endl
//						<< "����-����: " << b[r] << endl;
//				}
//			}
//		}
//		file.close();
//		cout << "������� 0 ��� �������� � ����.";
//		int q;
//		cin >> q;
//		if (q == 0) Menu::menuSel(); break;
//	}
//}
//void Lot::menuSort() {
//	cout << "1.���������� �� ��������.\n2.���������� �� ����. ������(�� �����������).\n3.��������� �� ����. ������(�� ��������).\nEsc.�����.\n";
//	char vib = NULL;
//	switch (vib) {
//	case '1': sortTitle(); break;
//	case '2': sortStVozr(); break;
//	case '3': sortPrice(); break;
//	case 23: break;
//	}
//}
//void Lot::sortTitle() {
//	int id[20], q = 0;
//	string t[20], d[20];
//	float s[20], m[20], b[20];
//	ifstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "���� �� ����� ���� ������!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++) {
//			file >> id[r];
//			file >> t[r];
//			file >> d[r];
//			file >> s[r];
//			file >> m[r];
//			file >> b[r]; q++;
//		}
//	}
//	sort(begin(t), end(t));
//	for (int i = 0; i < q + 1; i++) {
//		cout << "��������: " << t[i] << endl << "��������: " << d[i] << endl
//			<< "��������� ����: " << s[i] << endl << "������������ ������: " << m[i] << endl
//			<< "����-����: " << b[i] << endl;
//	}
//	file.close();
//}
//void Lot::sortStVozr() {
//	int id[20], q = 0;
//	string t[20], d[20], temp;
//	float s[20], m[20], b[20];
//	ifstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "���� �� ����� ���� ������!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++) {
//			file >> id[r];
//			file >> t[r];
//			file >> d[r];
//			file >> s[r];
//			file >> m[r];
//			file >> b[r]; q++;
//		}
//	}
//	sort(begin(m), end(m));
//	for (int i = 0; i < q + 1; i++) {
//		cout << "��������: " << t[i] << endl << "��������: " << d[i] << endl
//			<< "��������� ����: " << s[i] << endl << "������������ ������: " << m[i] << endl
//			<< "����-����: " << b[i] << endl;
//	}
//	file.close();
//}
//void Lot::sortPrice() {
//	int id[20], q = 0;
//	string t[20], d[20], temp;
//	float s[20], m[20], b[20];
//	ifstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "���� �� ����� ���� ������!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++) {
//			file >> id[r];
//			file >> t[r];
//			file >> d[r];
//			file >> s[r];
//			file >> m[r];
//			file >> b[r]; q++;
//		}
//	}
//	sort(begin(s), end(s));
//	for (int i = 0; i < q + 1; i++) {
//		cout << "��������: " << t[i] << endl << "��������: " << d[i] << endl
//			<< "��������� ����: " << s[i] << endl << "������������ ������: " << m[i] << endl
//			<< "����-����: " << b[i] << endl;
//	}
//	file.close();
//}
//void Lot::buyLot(int num1, int idPart) {
//	cout << "1.������.\n0.�����.";
//	int q;
//	cin >> q;
//	if (q == 1) {
//		Mapper m1;
//		m1.setSelLot(num1, idPart);
//		cout << endl << "����� ������. �������  �� �������!";
//	}
//}
ostream& operator<< (ostream& s, Lot& lot) {
	s << lot.getID() << " " << lot.getTitle() << " " << lot.getDescr() << " " <<
		lot.getStartPrice() << " " << lot.getMaxStavka() << " " << lot.getBlicPrice()<< " " << lot.getPeriod() << endl;
	return s;
}

string Lot::getTitle() {
	return this->title;
}
string Lot::getDescr() {
	return this->descr;
}
float Lot::getBlicPrice() {
	return this->blicPrice;
}
float Lot::getMaxStavka() {
	return this->maxStavka;
}
float Lot::getStartPrice() {
	return this->startPrice;
}
int Lot::getPeriod() {
	return this->period;
}
