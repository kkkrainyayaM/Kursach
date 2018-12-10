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
				cout << "Выберите номер лота для редактирования: ";
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
			cout << setw(12) << " Номер лота " << "|" << setw(10) << " Название " << "|" << setw(20) << " Описание " << "|" << setw(16) << " Стартовая цена " << "|" <<setw(14) << "Конец торгов "<<'|'<< " Текущая ставка " << endl;
			for (Lot lot : allLotsForUser) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << setw(16) << stavka->toString() << endl;
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
					cout << setw(12) << " Номер лота " << "|" << setw(10) << " Название " << "|" << setw(20) << " Описание " << "|" << setw(16) << " Стартовая цена " << "|" << setw(14) << "Конец торгов " << "|" << " Текущая ставка ";
					for (Lot lot : allLotsForUser) {
						lot.printLot();
						Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
						if (stavka != NULL) {
							cout << setw(16) << stavka->toString() << endl << endl;
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
			system("pause");
			break;}
		case '2': {
			system("cls");
			Vector<Lot> allLots = DAO::getInstance()->getAllLots();
			cout <<endl<< setw(12) << " Номер лота " << "|" << setw(10) << " Название " << "|" << setw(20) << " Описание " << "|" << setw(16) << " Стартовая цена " << "|" << setw(14) << "Конец торгов " << "|"<< " Текущая ставка "<< endl;
			for (Lot lot : allLots) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout <<"|"<< setw(16)<< stavka->toString();
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
			cout << endl << setw(12) << " Номер лота " << "|" << setw(10) << " Название " << "|" << setw(20) << " Описание " << "|" << setw(16) << " Стартовая цена " << "|" << setw(14) << "Конец торгов " << "|" << " Текущая ставка ";
			for (Lot lot : lots) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << "|" << setw(16) << stavka->toString();
				}
			}
				system("pause");
			break; }
		case '4': {
			system("cls");
			string title;
			cout << "Введите название лота: ";
			cin >> title;
			Lot* lot = DAO::getInstance()->findByTitle(title);
			if (lot != NULL) {
				cout << endl << setw(12) << " Номер лота " << "|" << setw(10) << " Название "
					<< "|" << setw(20) << " Описание " << "|" << setw(16) 
					<< " Стартовая цена " << "|" << setw(14) << "Конец торгов " << "|" << " Текущая ставка ";
				lot->printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot->getLastStavkaId());
				if (stavka != NULL) {
					cout << "|" << setw(16) << stavka->toString();
				}
			}
			else cout << "\nЛотов с таким названием нет!";
			system("pause");
			break;
		}
		case '5': {
			system("cls");
			float otSt, doSt;
			cout << "Введите диапазон значений: от А=";
			cin >> otSt;
			cout << "  до В=";
			cin >> doSt;
			Vector<Lot> Lots = DAO::getInstance()->getAllLots();
			Lot* lot = Lot::filtrLotsByStPrise(Lots, otSt, doSt);
			cout << endl << setw(12) << " Номер лота " << "|" << setw(10) << " Название " << "|" << setw(20) << " Описание " << "|" << setw(16) << " Стартовая цена " << "|" << setw(14) << "Конец торгов " << "|" << " Текущая ставка " << endl;
			for (Lot lot : Lots) {
				lot.printLot();
				Stavka* stavka = DAO::getInstance()->getStavkaById(lot.getLastStavkaId());
				if (stavka != NULL) {
					cout << "|" << setw(16) << stavka->toString();
				}
			}
			system("pause");
			break; }
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
Role Menu::autorization() {

	AuthService::getAuthInstance()->auth();
	return AuthService::getAuthInstance()->getCurrentUser().getRole();
}

void Menu::programmTime() {
	int vih = 0;
	int year, day, month;
	while (vih != 1) {
		cout <<"\nВведите год (цифрами (4 цифры)): ";
		cin >> year;
		vih = prov_year(year);
	}
	vih = 0;
	while (vih != 1) {
		cout <<"\nВведите месяц (цифрами): ";
		cin >> month;
		vih = prov_month(month);
	}
	vih = 0;
	while (vih != 1) {
		cout <<"\nВведите день (цифрами): ";
		cin >> day;
		vih = prov_month(month);
	}
	if (vih == 1) {
		setDay(day);
		setMonth(month);
		setYear(year);
	}
	while (getchar() != '\n')
		continue;
}

int Menu::prov_year(int year)
{
	int i = 0, x = 0;
	while (year != 0)
	{
		if (year >= 2018 && year <= 2100)
			return 1;
		else
		{
			cout <<"Введите реальный год\n";
			return 0;
		}
	}
	return 0;
}
int Menu::prov_month(int month)
{
	int i = 0, x = 0;
	while (month != 0)
	{
		if (month >= 1 && month <= 12)
			return 1;
		else
		{
			cout << "Введите реальный месяц\n";
			return 0;
		}
	}
	return 0;
}

int Menu:: prov_day(int day){
	int i = 0, x = 0;
	while (day != '\0')
	{
		if (day >= 1 && day <= 30)
			return 1;
		else
		{
			cout << "Введите реальный день\n";
			return 0;
		}
	}
	return 0;
}

void Menu::setDay(int day1) {
	day = day1;
}
void Menu::setMonth(int month1) {
	month = month1;
}
void Menu::setYear(int year1) {
	year = year1;
}