#include "Lot.h"
#include "DAO.h"
#include <algorithm>

Lot Lot::createLot() {
	string title, descr;
	float startPrice;
	int finishDay, finishMonth, finishYear;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "ДОБАВЛЕНИЕ ТОВАРА" << endl << "Название: ";
	cin >> title;
	cout << "\nОписание: ";
	cin.ignore(100, '\n');
	cin.clear();
	cin >> descr;
	cin.clear();
	cout << "\nСтартовая цена: ";
	cin >> startPrice;
	cout << "\nВремя окончания торгов: ";
	cout << "\nВведите год (цифрами (4 цифры)): ";
	cin >> finishYear;
	cout << "\nВведите месяц (цифрами): ";
	cin >> finishMonth;
	cout << "\nВведите день (цифрами): ";
	cin >> finishDay;
	return Lot(IDGenerator::getInstance()->getLotId(), title, descr, startPrice, finishDay, finishMonth, finishYear, -1, -1);
	cout << "\nЛот успешно добавлен!";
}


ostream& operator<< (ostream& s, Lot& lot) {
	s << lot.getID() << " " << lot.getTitle() << " " << lot.getDescr() << " " <<
		lot.getStartPrice() << " " << lot.getDay() << " " << lot.getMonth() << " " << lot.getYear() << " " << lot.getSellerId() << " " << lot.getLastStavkaId() << endl;
	return s;
}

int Lot::getID() {
	return ID;
}

void Lot::setID(int id) {
	this->ID = id;
}

int Lot::getDay() {
	return finishDay;
}

void Lot::setDay(int d) {
	this->finishDay = d;
}

int Lot::getMonth() {
	return finishMonth;
}

void Lot::setMonth(int m) {
	this->finishMonth = m;
}

int Lot::getYear() {
	return finishYear;
}

void Lot::setYear(int y) {
	this->finishYear = y;
}

string Lot::getTitle() {
	return this->title;
}

void Lot::setTitle(string title) {
	this->title = title;
}

string Lot::getDescr() {
	return this->descr;
}

void Lot::setDescr(string descr) {
	this->descr = descr;
}

float Lot::getStartPrice() {
	return this->startPrice;
}

void Lot::setStartPrice(float price) {
	this->startPrice = price;
}

int Lot::getSellerId() {
	return sellerID;
}

void Lot::setSellerId(int id) {
	this->sellerID = id;
}

int Lot::getLastStavkaId() {
	return this->lastStavkaId;
}

void Lot::setLastStavkaId(int id) {
	this->lastStavkaId = id;
}

void Lot::printLot() {
	cout << endl;
	cout.width(100);
	cout << setfill('_') << '_';
	cout << setfill(' ') << endl << setw(12) << getID() << '|'
		<< setw(20) << getTitle() << '|'
		<< setw(20) << getDescr() << '|'
		<< setw(14) << getDay() << '.' << getMonth() << '.' << getYear() << '|'
		<< setw(16) << getStartPrice();
}
Lot* Lot::filtrLotsByStPrise(Vector<Lot>& lots, float otPr, float doPr) {
	for (int i = 0; i < lots.size(); i++) {
		if ((lots[i].getStartPrice() > otPr) && (lots[i].getStartPrice() > doPr)) {
			return &lots[i];
		}
	}
	return NULL;
}

Vector<Lot>& Lot::sortLotsByTitle(Vector<Lot>& lots) {
	Lot tmp;
	for (int i = 1; i < lots.size(); i++) {
		for (int j = 1; j < lots.size(); j++) {
			if (lots[j - 1].getTitle() > lots[j].getTitle()) {
				tmp = lots[j - 1];
				lots[j - 1] = lots[j];
				lots[j] = tmp;
			}
		}
	}
	return lots;
}



Vector<Lot>& Lot::sortLotsByStPrice(Vector<Lot>& lots) {
	Lot tmp;
	for (int i = 1; i < lots.size(); i++) {
		for (int j = 1; j < lots.size(); j++) {
			if (lots[j - 1].getStartPrice() > lots[j].getStartPrice()) {
				tmp = lots[j - 1];
				lots[j - 1] = lots[j];
				lots[j] = tmp;
			}
		}
	}
	return lots;
}
