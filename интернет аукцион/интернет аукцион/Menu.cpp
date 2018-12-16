#pragma once
#include "Menu.h"
using namespace DataAccessObject;

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
		cout << "1.������� ������������.\n2.���������� ����.\n3.�������������� ����.\n4.�������� ����.\n5.�������� �����.\nESC.�����.\n";
		cout << "��� �����: ";
		menu1 = _getche();
		switch (menu1) {
		case '1': {
			system("cls");
			cout << "������� ������������." << endl;
			User user = AuthService::getAuthInstance()->getCurrentUser();
			user.toString();
			cout << endl<<"��������� ����:" << endl;
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			cout << setw(12) << " ����� ���� " << "|" << setw(12) << "������" << "|" << setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|"
				<< setw(14) << "����� ������ " << "|" << setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
			for (Lot lot : allLotsForUser) {
				if (lot.getStatus() == "�������") {
					lot.printLot();
					Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
					if (stavka != NULL) {
						cout << setw(16) << fixed << setprecision(2)<< stavka->toString() << endl << endl;
					}
				}
			}
			system("pause");
			break;
		}
		case '2': {

			system("cls");
			Lot lot = Lot::createLot();
			lot.setSellerId(AuthService::getAuthInstance()->getCurrentUser().getID());
			DAO::getInstance()->saveLot(lot);
			cout << endl << "��� ������� ��������!";
			system("pause");
			break;
		}
			
		case '3': {
			system("cls");
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			cout << setw(12) << " ����� ���� " << "|" << setw(12) << "������" << "|" << setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|"
				<< setw(14) << "����� ������ " << "|" << setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
			for (Lot lot : allLotsForUser) {
				if (lot.getStatus() != "�������") {
					lot.printLot();
					Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
					if (stavka != NULL) {
						cout << setw(16) << fixed<<setprecision(2)<< stavka->toString() << endl << endl;
					}
				}
			}
			int choose;
			bool success = false;
			while (!success) {
				cout << "\n�������� ����� ���� ��� ��������������: ";
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
			cout << setw(12) << " ����� ���� " << "|" << setw(12) << "������" << "|" << setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|"
				<< setw(14) << "����� ������ " << "|" << setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
			for (Lot lot : allLotsForUser) {
				if (lot.getStatus() != "�������") {
					lot.printLot();
					Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
					if (stavka != NULL) {
						cout << setw(16) << fixed<<setprecision(2)<< stavka->toString() << endl << endl;
					}
				}
			}
			int choose;
			bool success = false;
			while (!success) {
				cout <<endl<< "�������� ����� ���� ��� ��������: ";
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
					cout <<  setw(12) << " ����� ���� " << "|"<<setw(12) << "������" << "|" <<setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|" 
						<< setw(14) << "����� ������ " <<"|" <<setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
					for (Lot lot : allLotsForUser) {
						lot.printLot();
						Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
						if (stavka != NULL) {
							cout << setw(16) << fixed << setprecision(2) << stavka->toString() << endl << endl;
						}
					}
					cout << endl;
					system("pause");
					break;
				  }
					  
		case 27:
			cout << " ����� �������!" << endl;
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
    
	cout << "�� ����� ��� ����������." << endl;
	while (menu1 != 27) {
		system("cls");
		cout << "1.������ �������.\n2.�������� �����.\n3.���������� �����.\n4.����� �����.\n5.���������� �����.\nESC.�����.\n";
		cout << "��� �����: ";
		menu1 = _getche();
		switch (menu1) {
		case '1':{
			system("cls");
			cout << "������� ������������." << endl;
			User user = AuthService::getAuthInstance()->getCurrentUser();
			user.toString();
			cout << endl << "���� ��������:" << endl;
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			cout << setw(12) << " ����� ���� " << "|" << setw(12) << "������" << "|" << setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|"
				<< setw(14) << "����� ������ " << "|" << setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
			for (Lot lot : allLotsForUser) {
				if (lot.getStatus() == "�������") {
					Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
					int id = stavka->getIDPart();
					if (id = AuthService::getAuthInstance()->getCurrentUser().getID()) {
						lot.printLot();
						//Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
						if (stavka != NULL) {
							cout << setw(16) << fixed << setprecision(2) << stavka->toString() << endl << endl;
						}
					}
				}
			}
			system("pause");
			break;}
		case '2': {
			system("cls");
			Vector<Lot> allLots = DAO::getInstance()->getAllLots();
			cout <<endl << setw(12) << " ����� ���� " << "|" << setw(12) << "������" << "|" << setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|"
				<< setw(14) << "����� ������ " << "|" << setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
			for (Lot lot : allLots) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << setw(16)<<fixed<< setprecision(2)<<stavka->toString();
				}
			}
			int vib, num;
			cout <<endl<< "1.�������.\n0.�����. "<< endl <<"��� �����: ";
			cin >> vib;
			if (vib == 1) {
				cout << endl << "����� ����: ";
				cin >> num;
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
		case '3': {
			system("cls");
			cout << "1.���������� �� ��������.\n2.���������� �� ��������� ����.\n" << "��� �����: ";
			int vib;
			Vector<Lot> lots = DAO::getInstance()->getAllLots();
			cin >> vib;
			if (vib == 1) {
				Lot::sortLotsByTitle(lots);
			}
			else if (vib == 2) {
				Lot::sortLotsByStPrice(lots);
			}
			cout << setw(12) << " ����� ���� " << "|" << setw(12) << "������" << "|" << setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|"
				<< setw(14) << "����� ������ " << "|" << setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
			for (Lot lot : lots) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << setw(16) << fixed<<setprecision(2)<< stavka->toString();
				}
			}
			cout << endl;
				system("pause");
			break; }
		case '4': {
			system("cls");
			string title;
			cout << "������� �������� ����: ";
			cin >> title;
			Lot* lot = DAO::getInstance()->findByTitle(title);
			if (lot != NULL) {
				cout << endl << setw(12) << " ����� ���� " << "|" << setw(12) << "������" << "|" << setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|"
					<< setw(14) << "����� ������ " << "|" << setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
				lot->printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot->getLastStavkaId());
				if (stavka != NULL) {
					cout << setw(16) << fixed << setprecision(2)<< stavka->toString();
				}
			}
			else cout << "\n����� � ����� ��������� ���!";
			cout << endl;
			system("pause");
			break;
		}
		case '5': {
			system("cls");
			float otSt, doSt;
			cout << "������� �������� ��������: \n  �� �=";
			cin >> otSt;
			cout << "  �� �=";
			cin >> doSt;
			Vector<Lot> Lots = DAO::getInstance()->getAllLots();
			Vector<Lot> filtr = Lot::filtrLotsByStPrise(Lots, otSt, doSt);
			cout << endl <<setw(12) << " ����� ���� " << "|" << setw(12) << "������" << "|" << setw(20) << " �������� " << "|" << setw(20) << " �������� " << "|"
				<< setw(14) << "����� ������ " << "|" << setw(16) << " ��������� ���� " << "|" << " ������� ������ ";
			for (Lot lot : filtr) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << setw(16) <<fixed << setprecision(2)<< stavka->toString();
				}
			}
			cout << endl;
			system("pause");
			break; }
		case 27:
			cout << " ������ �������!" << endl;
			break;
		default: cout << "�������� ����� ���� ���������" << endl;
			system("pause");
			break;
		}
	}
	return 0;

}
Role Menu::autorization() {

	AuthService::getAuthInstance()->auth();
	return AuthService::getAuthInstance()->getCurrentUser().getRole();
}
