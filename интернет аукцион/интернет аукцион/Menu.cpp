#pragma once
#include "Menu.h"
using namespace DataAccessObject;

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
		cout << "1.Кабинет пользователя.\n2.Добавление лота.\n3.Редактирование лота.\n4.Удаление лота.\n5.Просмотр лотов.\nESC.Выход.\n";
		cout << "Ваш выбор: ";
		menu1 = _getche();
		switch (menu1) {
		case '1': {
			system("cls");
			cout << "Кабинет пользователя." << endl;
			User user = AuthService::getAuthInstance()->getCurrentUser();
			user.toString();
			cout << endl<<"Проданные лоты:" << endl;
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			cout << setw(12) << " Номер лота " << "|" << setw(12) << "Статус" << "|" << setw(20) << " Название " << "|" << setw(20) << " Описание " << "|"
				<< setw(14) << "Конец торгов " << "|" << setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
			for (Lot lot : allLotsForUser) {
				if (lot.getStatus() == "Окончен") {
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
			cout << endl << "Лот успешно добавлен!";
			system("pause");
			break;
		}
			
		case '3': {
			system("cls");
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			cout << setw(12) << " Номер лота " << "|" << setw(12) << "Статус" << "|" << setw(20) << " Название " << "|" << setw(20) << " Описание " << "|"
				<< setw(14) << "Конец торгов " << "|" << setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
			for (Lot lot : allLotsForUser) {
				if (lot.getStatus() != "Окончен") {
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
				cout << "\nВыберите номер лота для редактирования: ";
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
			cout << setw(12) << " Номер лота " << "|" << setw(12) << "Статус" << "|" << setw(20) << " Название " << "|" << setw(20) << " Описание " << "|"
				<< setw(14) << "Конец торгов " << "|" << setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
			for (Lot lot : allLotsForUser) {
				if (lot.getStatus() != "Окончен") {
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
				cout <<endl<< "Выберите номер лота для удаления: ";
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
					cout <<  setw(12) << " Номер лота " << "|"<<setw(12) << "Статус" << "|" <<setw(20) << " Название " << "|" << setw(20) << " Описание " << "|" 
						<< setw(14) << "Конец торгов " <<"|" <<setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
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
			cout << " Всего Доброго!" << endl;
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
    
	cout << "Вы вошли как покупатель." << endl;
	while (menu1 != 27) {
		system("cls");
		cout << "1.Личный кабинет.\n2.Просмотр лотов.\n3.Сортировка лотов.\n4.Поиск лотов.\n5.Фильтрация лотов.\nESC.Выход.\n";
		cout << "Ваш выбор: ";
		menu1 = _getche();
		switch (menu1) {
		case '1':{
			system("cls");
			cout << "Кабинет пользователя." << endl;
			User user = AuthService::getAuthInstance()->getCurrentUser();
			user.toString();
			cout << endl << "Ваши выигрыши:" << endl;
			Vector<Lot> allLotsForUser = DAO::getInstance()->getLotsBySellerId(
				AuthService::getAuthInstance()->getCurrentUser().getID());
			cout << setw(12) << " Номер лота " << "|" << setw(12) << "Статус" << "|" << setw(20) << " Название " << "|" << setw(20) << " Описание " << "|"
				<< setw(14) << "Конец торгов " << "|" << setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
			for (Lot lot : allLotsForUser) {
				if (lot.getStatus() == "Окончен") {
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
			cout <<endl << setw(12) << " Номер лота " << "|" << setw(12) << "Статус" << "|" << setw(20) << " Название " << "|" << setw(20) << " Описание " << "|"
				<< setw(14) << "Конец торгов " << "|" << setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
			for (Lot lot : allLots) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << setw(16)<<fixed<< setprecision(2)<<stavka->toString();
				}
			}
			int vib, num;
			cout <<endl<< "1.Покупка.\n0.Выход. "<< endl <<"Ваш выбор: ";
			cin >> vib;
			if (vib == 1) {
				cout << endl << "Номер лота: ";
				cin >> num;
				Lot* lot = DAO::getInstance()->getLotById(num);
				Stavka* oldStavka = DAO::getInstance()->getStavkaById(lot->getLastStavkaId());
				float stavka;
				cout << endl << "Сумма ставки: ";
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
			cout << "1.Сортировка по алфавиту.\n2.Сортировка по стартовой цене.\n" << "Ваш выбор: ";
			int vib;
			Vector<Lot> lots = DAO::getInstance()->getAllLots();
			cin >> vib;
			if (vib == 1) {
				Lot::sortLotsByTitle(lots);
			}
			else if (vib == 2) {
				Lot::sortLotsByStPrice(lots);
			}
			cout << setw(12) << " Номер лота " << "|" << setw(12) << "Статус" << "|" << setw(20) << " Название " << "|" << setw(20) << " Описание " << "|"
				<< setw(14) << "Конец торгов " << "|" << setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
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
			cout << "Введите название лота: ";
			cin >> title;
			Lot* lot = DAO::getInstance()->findByTitle(title);
			if (lot != NULL) {
				cout << endl << setw(12) << " Номер лота " << "|" << setw(12) << "Статус" << "|" << setw(20) << " Название " << "|" << setw(20) << " Описание " << "|"
					<< setw(14) << "Конец торгов " << "|" << setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
				lot->printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot->getLastStavkaId());
				if (stavka != NULL) {
					cout << setw(16) << fixed << setprecision(2)<< stavka->toString();
				}
			}
			else cout << "\nЛотов с таким названием нет!";
			cout << endl;
			system("pause");
			break;
		}
		case '5': {
			system("cls");
			float otSt, doSt;
			cout << "Введите диапазон значений: \n  от А=";
			cin >> otSt;
			cout << "  до В=";
			cin >> doSt;
			Vector<Lot> Lots = DAO::getInstance()->getAllLots();
			Vector<Lot> filtr = Lot::filtrLotsByStPrise(Lots, otSt, doSt);
			cout << endl <<setw(12) << " Номер лота " << "|" << setw(12) << "Статус" << "|" << setw(20) << " Название " << "|" << setw(20) << " Описание " << "|"
				<< setw(14) << "Конец торгов " << "|" << setw(16) << " Стартовая цена " << "|" << " Текущая ставка ";
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
			cout << " ВВсего Доброго!" << endl;
			break;
		default: cout << "Выберите пункт меню корректно" << endl;
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
