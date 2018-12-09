#include "Lot.h"
#include "DAO.h"
#include <algorithm>

Lot Lot::createLot() {
	string title, descr;
	float startPrice;
	cout << "ДОБАВЛЕНИЕ ТОВАРА" << endl << "Название: ";
	cin >> title;
	cout << "\nОписание: ";
	cin >> descr;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\nСтартовая цена: ";
	cin >> startPrice;
	return Lot(IDGenerator::getInstance()->getLotId(), title, descr, startPrice, -1, -1);
	cout << "\nЛот успешно добавлен!";
}


ostream& operator<< (ostream& s, Lot& lot) {
	s << lot.getID() << " " << lot.getTitle() << " " << lot.getDescr() << " " <<
		lot.getStartPrice() << " " << lot.getSellerId() << " " << lot.getLastStavkaId() << endl;
	return s;
}

int Lot::getID() {
	return ID;
}

void Lot::setID(int id) {
	this->ID = id;
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
	
	getLastStavkaId();
	cout << "===============================" << endl;
	cout << "Номер лота: " << getID() << endl;
	cout << "Название: " << getTitle() << endl
		<< "Описание: " << getDescr() << endl
		<< "Стартовая цена: " << getStartPrice() << endl;
}


