#include "Lot.h"
#include "DAO.h"
#include <algorithm>

Lot Lot::createLot() {
	string title, descr;
	float startPrice;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "ДОБАВЛЕНИЕ ТОВАРА" << endl << "Название: ";
	cin >> title;
	cout << "\nОписание: ";
	cin.ignore(100, '\n');
	cin.clear();
	getline(cin,descr);
	cin.clear();
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
	cout << endl;
	cout.width(76);
	cout << setfill('_') <<'_';
	cout << setfill(' ')<< endl << setw(12) << getID() << '|'
		<< setw(10) << getTitle() << '|'
		<< setw(20) << getDescr() << '|'
		<< setw(16) << getStartPrice();
}

bool funcTitile (Lot & a, Lot & b) { 
		return a.getTitle() < b.getTitle();  // интересно ты строки сравниваешь
	}

bool funcStartPrice(Lot & a, Lot & b) {
	return a.getStartPrice() < b.getStartPrice();
}

Vector<Lot>& Lot::sortLotsByTitle(Vector<Lot>& lots) {
	
	return lots;
}
//
//Lot* Lot::filtrLotsByStartPrise(Vector<Lot>& lots, float otPr, float doPr) {
//	for (int i = 0; i < lots.size(); i++) {
//		if ((lots[i].getStartPrice() > otPr)&&(lots[i].getStartPrice() > doPr)) {
//			return &lots[i];
//		}
//	}
//	return NULL;
//}
