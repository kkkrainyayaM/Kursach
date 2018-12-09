#pragma once
#include "Menu.h"


int Menu::registration() {
	char menu2 = NULL;
	int vozvr = 0;
	while (menu2 != 27) {
		cout << "РЕГИСТРАЦИЯ" << endl << "1.Регистрация как продавец.\n2.Регистрация как покупатель.\nEsc.Выход.\nВаш выбор: ";
		cin >> menu2;
		if (menu2 == '1') {
			system("cls");
			cout << "РЕГИСТРАЦИЯ" << endl;
			Seller* seller = new Seller();
			seller->setID(IDGenerator::getInstance()->getUserId());
			seller->readName();
			seller->setLog();
			seller->setPas();
			DAO* daoInstance = DAO::getInstance();
			daoInstance->saveSeller(*seller);
			AuthService::getAuthInstance()->setCurrentUser(*seller);
			User user = AuthService::getAuthInstance()->getCurrentUser();
			cout << "\nРегистрация прошла успешно!" << endl;
			vozvr = 1;
			break;
		}
		else if (menu2 == '2') {
			Participant* participant = new Participant();
			system("cls");
			cout << "РЕГИСТРАЦИЯ" << endl;
			participant->setID(IDGenerator::getInstance()->getUserId());
			participant->readName();
			participant->setLog();
			participant->setPas();
			DAO* daoInstance = DAO::getInstance();
			daoInstance->saveParticipant(*participant);
			cout << "\nРегистрация прошла успешно!" << endl;
			vozvr = 2;
			break;
		}
		else if (menu2 == 27) {
			cout << "Всего Доброго!";
			break;
		}
		else {
			cout << "Выберите пункт меню корректно";
			break;
		}
	}
	return vozvr;
}
int Menu::menuSel() {
	char menu1 = NULL;
	system("cls");
	cout << "Вы вошли как продавец." << endl;

	while (menu1 != 27) {
		system("cls");
		cout << "1.Кабинет пользователя.\n2.Добавление лота.\n3.Редактирование лота.\n4.Удаление лота.\n5.Просмотр всех лотов.\nESC.Выход.\n";
		cout << "Ваш выбор: ";
		menu1 = _getche();
		switch (menu1) {
		case '1': {
			system("cls");
			cout << "Кабинет пользователя." << endl;
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
			
				  //case '3':
				  //	//Lot::redactLot();
				  //	//дописать
				  //	system("pause");
				  //	break;
		case '4': {
			system("cls");
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			for (Lot lot : allLotsForUser) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << "Текущая ставка: " << stavka->toString() << endl;
				}
			}
			int choose;
			bool success = false;
			while (!success) {
				cout << "Выберите номер лота для удаления: ";
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
							cout << "Текущая ставка: " << stavka->toString() << endl;
						}
					}
					system("pause");
					break;
				  }
					  
		case 27:
			cout << "Всего Доброго!" << endl;
			break;
		default: cout << "Выберите пункт меню корректно" << endl;
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
	cout << "Вы вошли как покупатель." << endl;
	while (menu1 != 27) {
		cout << "1.Личный кабинет.\n2.Просмотр лотов.\n3.Сортировка лотов.\n5.Фильтрация лотов.\nESC.Выход.\n";
		menu1 = _getche();
		switch (menu1) {
		case '1':{
			system("cls");
			cout << "Кабинет пользователя." << endl;
			User user = AuthService::getAuthInstance()->getCurrentUser();
			user.toString();
			system("pause");
			break;}
		case '2':
			//Lot::printLots();
			int num;
			cout << "1.Покупка.\n0.Выход. ";
			cin >> num;
			if (num == 1) {
				cout << endl << "Номер лота:";
				//int num1, idPart;
				//idPart = p1.retID();
				//cin >> num1;
				//найти num1-ый лот в списке и ???
				//l1.buyLot(num1, idPart);
			}
			system("pause");
			break;
		case '3':
			//Lot::menuSort();
			//дописать
			system("pause");
			break;
		case '4':
			//Lot::filtr();
			//дописать
			system("pause");
			break;
		case 27:
			cout << "Всего Доброго!" << endl;
			break;
		default: cout << "Выберите пункт меню корректно" << endl;
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
