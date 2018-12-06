#include "User.h"
#include "Seller.h"
#include "Participant.h"
#include "Lot.h"
#include "Menu.h"
#include "DAO.cpp"

int Menu::registration() {
	char menu2 = NULL;
	int vozvr = 0;
	while (menu2 != 27) {
		cout << "�����������" << endl << "1.����������� ��� ��������.\n2.����������� ��� ����������.\nEsc.�����.\n��� �����: ";
		cin >> menu2;
		if (menu2 == '1') {
			Seller* seller = new Seller();
			system("cls");
			cout << "�����������" << endl;
			seller->readName();
			seller->setLog();
			seller->setPas();
			DAO* daoInstance = DAO::getInstance();
			daoInstance->saveSeller(*seller);
			cout << "\n����������� ������ �������!" << endl;
			vozvr = 1;
			break;
		}
		else if (menu2 == '2') {
			Participant* participant = new Participant();
			system("cls");
			cout << "�����������" << endl;
			participant->readName();
			participant->setLog();
			participant->setPas();
			DAO* daoInstance = DAO::getInstance();
			daoInstance->saveParticipant(*participant);
			cout << "\n����������� ������ �������!" << endl;
			vozvr = 2;
			break;
		}
		else if (menu2 == 27) {
			cout << "����� �������!";
			break;
		}
		else {
			cout << "�������� ����� ���� ���������";
			break;
		}
	}
	return vozvr;
}
//int Menu::menuSel() {
//	int id1 = 0;
//	char menu1 = NULL;
//	system("cls");
//	cout << "�� ����� ��� ��������." << endl;
//	while (menu1 != 27) {
//		cout << "1.�������� ������ ����������\n2.���������� ����.\n3.�������������� ����.\n4.�������� ����.\n5.�������� ���� �����.\nESC.�����.\n";
//		cin >> menu1;
//		switch (menu1) {
//		//case '1':
//		//	Seller::viewInf();
//		//	system("pause");
//		//	break;
//		//case '2':
//		//	//id1 = s1.retID();
//		//	//Seller::createLot(id1);
//		//	system("pause");
//		//	break;
//		//case '3':
//		//	//Lot::redactLot();
//		//	//��������
//		//	system("pause");
//		//	break;
//		//case '4':
//		//	//Lot ::deleteLot();
//		//	//��������
//		//	system("pause");
//		//	break;
//		//case '5':
//		//	//Lot::printLots();
//		//	//��������
//		//	system("pause");
//		//	break;
//		case 27:
//			cout << "����� �������!" << endl;
//			break;
//		default: cout << "�������� ����� ���� ���������" << endl;
//			system("pause");
//			break;
//		}
//	}
//	return 0;
//}
//int Menu::menuPart()
//{
//	Participant p1;
//	char menu1 = NULL;
//	cout << "�� ����� ��� ����������." << endl;
//	while (menu1 != 27) {
//		cout << "1.��� ������.\n2.�������� �����.\n3.���������� �����.\n5.���������� �����.\nESC.�����.\n";
//		cin >> menu1;
//		switch (menu1) {
//		case '1':
//			p1.myBuy();
//			system("pause");
//			break;
//		case '2':
//			//Lot::printLots();
//			int num;
//			cout << "1.�������.\n0.�����. ";
//			cin >> num;
//			if (num == 1) {
//				cout << endl << "����� ����:";
//				int num1, idPart;
//				//idPart = p1.retID();
//				cin >> num1;
//				//����� num1-�� ��� � ������ � ???
//				//l1.buyLot(num1, idPart);
//			}
//			system("pause");
//			break;
//		case '3':
//			//Lot::menuSort();
//			//��������
//			system("pause");
//			break;
//		case '4':
//			//Lot::filtr();
//			//��������
//			system("pause");
//			break;
//		case 27:
//			cout << "����� �������!" << endl;
//			break;
//		default: cout << "�������� ����� ���� ���������" << endl;
//			system("pause");
//			break;
//		}
//	}
//}
//int Menu::autorization() {
//	char _login[15], _password[15], log[15][20], pas[15][20];
//	int id[20], q = 0;
//	List<User>u1;
//	const char ch = '\n';
//	ifstream file("log_pas.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "���� �� ����� ���� ������!\n";
//	while (q == 0) {
//		cout << "�����: ";
//		cin >> _login;
//		cout << "������: ";
//		cin >> _password;
//		int i = 0, n = 0;
//		char alf[] = "abcedfghijklmnopqrstuvwxyz0123456789#!@$%^&*-+=";
//		for (n = 0; n < strlen(_password) + 1; n++)
//		{
//			for (i = 0; i < 47; i++)
//			{
//				if (_password[n] == alf[i])
//				{
//					if (i >= 47)
//						_password[n] = alf[i - 47];
//					else
//						_password[n] = alf[i + 4];//�������� ������ �� 4
//					break;//������������� ������� �� �����
//				}
//			}
//		}
//		while (!(file.eof())) {
//			for (int r = 0; r < file.eof(); r++)
//			{
//				file >> id[r];
//				file >> log[r];
//				file >> pas[r];
//				//file >> ch;
//				if (strcmp(log[r], _login) == 0 || (pas[r], _password) == 0) {
//					q = 1;
//					cout << "���� ��������!" << endl;
//					break;
//					return id[r];
//				}
//			}
//		}
//		if (q == 0) {
//			cout << "��������� ����!" << endl;
//
//		}
//	}
//
//	file.close();
//}
//
//istream& operator>> (istream& s, User& u) {
//	char tut;
//	s >> u.login >> tut >> u.password >> tut >> u.ID >> tut;
//	return s;
//}
//ostream& operator<< (ostream& s, User& u) {
//	s << u.login << " " << u.password << " " << u.ID << '\n';
//	return s;
//}
//
//ostream& operator<< (ostream& s, Lot& l) {
//	s << l.ID << " " << l.title << " " << l.descr << " " << l.startPrice << " " << l.maxStavka << " " << l.blicPrice << " " << l.period << "\n";
//	return s;
//}
//istream& operator>> (istream& s, Participant& p) {
//	char tut;
//	s >> p.stavka >> tut;
//	return s;
//}
//ostream& operator<< (ostream& s, Participant& p) {
//	s << p.stavka << '\n';
//	return s;
//}
//istream& operator>> (istream& q, Seller& s) {
//	char tut;
//	q >> s.raiting >> tut;
//	return q;
//}
//ostream& operator<< (ostream& q, Seller& s) {
//	q << s.raiting << '\n';
//	return q;
//}
