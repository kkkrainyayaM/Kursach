#pragma once
#include "Menu.h"


int Menu::registration() {
	char menu2 = NULL;
	int vozvr = 0;
	while (menu2 != 27) {
		cout << "�����������" << endl << "1.����������� ��� ��������.\n2.����������� ��� ����������.\nEsc.�����.\n��� �����: ";
		cin >> menu2;
		if (menu2 == '1') {
			system("cls");
			cout << "�����������" << endl;
			Seller* seller = new Seller();
			seller->setID(IDGenerator::getInstance()->getUserId());
			seller->readName();
			seller->setLog();
			seller->setPas();
			DAO* daoInstance = DAO::getInstance();
			daoInstance->saveSeller(*seller);
			AuthService::getAuthInstance()->setCurrentUser(*seller);
			User user = AuthService::getAuthInstance()->getCurrentUser();
			cout << "\n����������� ������ �������!" << endl;
			vozvr = 1;
			break;
		}
		else if (menu2 == '2') {
			Participant* participant = new Participant();
			system("cls");
			cout << "�����������" << endl;
			participant->setID(IDGenerator::getInstance()->getUserId());
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
int Menu::menuSel() {
	char menu1 = NULL;
	system("cls");
	cout << "�� ����� ��� ��������." << endl;

	while (menu1 != 27) {
		system("cls");
		cout << "1.������� ������������.\n2.���������� ����.\n3.�������������� ����.\n4.�������� ����.\n5.�������� ���� �����.\nESC.�����.\n";
		cout << "��� �����: ";
		menu1 = _getche();
		switch (menu1) {
		case '1': {
			system("cls");
			cout << "������� ������������." << endl;
			User user = AuthService::getAuthInstance()->getCurrentUser();
			user.toString();
			system("pause");
			break;
		}
		case '2': {
			system("cls");
			Lot lot = Lot::createLot();
			lot.setSellerId(AuthService::getAuthInstance()->getCurrentUser().getID());
			DAO::getInstance()->saveLot(lot);
			system("pause");
			break;
		}
			
		case '3': {
			system("cls");
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			for (Lot lot : allLotsForUser) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << "������� ������: " << stavka->toString() << endl;
				}
			}
			int choose;
			bool success = false;
			while (!success) {
				cout << "�������� ����� ���� ��� ��������������: ";
				cin >> choose;
				for (Lot lot : allLotsForUser) {
					if (lot.getID() == choose) {
						success = true;
						break;
					}
				}
			}
			Lot* lot = DAO::getInstance()->getLotById(choose);
			system("cls");
			Lot newLot = Lot::createLot();
			newLot.setID(lot->getID());
			newLot.setLastStavkaId(lot->getLastStavkaId());
			DAO::getInstance()->deleteLotById(lot->getID());
			DAO::getInstance()->saveLot(newLot);
			system("pause");
			break;
				  }
				  	
		case '4': {
			system("cls");
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			for (Lot lot : allLotsForUser) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << "������� ������: " << stavka->toString() << endl;
				}
			}
			int choose;
			bool success = false;
			while (!success) {
				cout << "�������� ����� ���� ��� ��������: ";
				cin >> choose;
				for (Lot lot : allLotsForUser) {
					if (lot.getID() == choose) {
						success = true;
						break;
					}
				}
			}
			DAO::getInstance()->deleteLotById(choose);
			system("pause");
			break;
				  }
				  	
		case '5': {
			system("cls");
					Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
						AuthService::getAuthInstance()->getCurrentUser().getID());
					for (Lot lot : allLotsForUser) {
						lot.printLot();
						Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
						if (stavka != NULL) {
							cout << "������� ������: " << stavka->toString() << endl;
						}
					}
					system("pause");
					break;
				  }
					  
		case 27:
			cout << "����� �������!" << endl;
			break;
		default: cout << "�������� ����� ���� ���������" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}
int Menu::menuPart()
{
	char menu1 = NULL;
    system("cls");
	cout << "�� ����� ��� ����������." << endl;
	while (menu1 != 27) {
		cout << "1.������ �������.\n2.�������� �����.\n3.���������� �����.\n5.���������� �����.\nESC.�����.\n";
		menu1 = _getche();
		switch (menu1) {
		case '1':{
			system("cls");
			cout << "������� ������������." << endl;
			User user = AuthService::getAuthInstance()->getCurrentUser();
			user.toString();
			system("pause");
			break;}
		case '2': {
			Vector<Lot> allLots = DAO::getInstance()->getAllLots();
			for (Lot lot : allLots) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << "������� ������: " << stavka->toString() << endl;
				}
			}
			int num;
			cout << "1.�������.\n0.�����. ";
			cin >> num;
			if (num == 1) {
				cout << endl << "����� ����: ";
				Lot* lot = DAO::getInstance()->getLotById(num);
				Stavka* oldStavka = DAO::getInstance()->getStavkaById(lot->getLastStavkaId());
				float stavka;
				cout << endl << "����� ������: ";
				cin >> stavka;
				Stavka newStavka = Stavka(IDGenerator::getInstance()->getStavkaId(),
					AuthService::getAuthInstance()->getCurrentUser().getID(),
					lot->getID(), stavka);
				DAO::getInstance()->saveStavka(newStavka);
				if (oldStavka == NULL) {
					lot->setLastStavkaId(newStavka.getIDStavka());
				}
				else {
					if (oldStavka->getStavka() < newStavka.getStavka()) {
						lot->setLastStavkaId(newStavka.getIDStavka());
					}
				}

			}
			system("pause");
			break;
		}
			
		case '3':
			//Lot::menuSort();
			//��������
			system("pause");
			break;
		case '4':
			//Lot::filtr();
			//��������
			system("pause");
			break;
		case 27:
			cout << "����� �������!" << endl;
			break;
		default: cout << "�������� ����� ���� ���������" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}
int Menu::autorization() {

	AuthService::getAuthInstance()->auth();
	return AuthService::getAuthInstance()->getCurrentUser().getRole();
}
