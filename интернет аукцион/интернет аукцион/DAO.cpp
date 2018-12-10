#include "DAO.h"

using namespace DataAccessObject;

DAO *DAO::instance = 0;



Lot* DAO::findByTitle( string title) {
	for (int i = 0; i < lots.size(); i++) {
		if (lots[i].getTitle() == title){
			return &lots[i];
		}
	}
	return NULL;
}


void DAO::initSellerVector() {
	ifstream file("seller.txt", ios::in | ios::binary);
	while (!(file.eof())) {
		if (file.peek() != EOF) {
			int id;
			string name, login, password;
			file >> id >> login >> password >> name;
			Seller seller = Seller(id, name, login, password);
			sellers.push_back(seller);
		}
	}
	file.close();
}

void DAO::initPartVector() {
	ifstream file("participant.txt", ios::in | ios::binary);
	while (!(file.eof())) {
		int id;
		string name, login, password;
		file >> id >> login >> password >> name ;
		Participant participant = Participant(id, name, login, password);
		participants.push_back(participant);
	}
	file.close();
}
void DAO::initLotVector() {
	ifstream file("lots.txt", ios::in | ios::binary);
	while (!(file.eof())) {
		int ID, sellerId, stavkaId, finishDay, finishMonth, finishYear;
		string title, descr;
		float startPrice;
		file >> ID >> title >> descr >> startPrice >> finishDay>> finishMonth>> finishYear>> sellerId >> stavkaId;
		if (ID >= 0) {
			Lot lot = Lot(ID, title, descr, startPrice, finishDay, finishMonth, finishYear, sellerId, stavkaId);
			lots.push_back(lot);
		}
	}
	file.close();
}

void DAO::initStavkaVector() {
	ifstream file("stavki.txt", ios::in | ios::binary);
	while (!(file.eof())) {
		float _stavka;
		int IDl, IDp, IDst;
		file >> IDst >> IDp >> IDl >> _stavka;
		Stavka stavka = Stavka(IDst, IDp, IDl, _stavka);
		stavki.push_back(stavka);
	}
	file.close();
}

DAO* DAO::getInstance() {
	if (!instance) {
		instance = new DAO;
		instance->initSellerVector();
		instance->initPartVector();
		instance->initLotVector();
		instance->initStavkaVector();
	}
	return instance;
}

Vector<Seller>& DAO::getAllSellers() {
	return sellers;
}

Vector<Participant>& DAO::getAllPart() {
	return participants;
}

Vector<Lot>& DAO::getAllLots() {
	return lots;
}

Vector<Stavka>& DAO::getAllStavki() {
	return stavki;
}

Seller* DAO::getSellerById(int id) {
	for (int i = 0; i < sellers.size(); i++) {
		if (sellers[i].getID() == id) {
			return &sellers[i];
		}
	}
	return NULL;
}

Participant* DAO::getPartById(int id) {
	for (int i = 0; i < participants.size(); i++) {
		if (participants[i].getID() == id) {
			return &participants[i];
		}
	}
	return NULL;
}

Lot* DAO::getLotById(int id) {
	for (int i = 0; i < lots.size(); i++) {
		if (lots[i].getID() == id) {
			return &lots[i];
		}
	}
	return NULL;
}

Stavka* DAO::getStavkiByIdPart(int id) {
	for (int i = 0; i < stavki.size(); i++) {
		if (stavki[i].getIDPart() == id) {
			return &stavki[i];
		}
	}
	return NULL;
}

Vector<Stavka> DAO::getStavkiByIdLot(int id) {
	Vector<Stavka> result = Vector<Stavka>();
	for (int i = 0; i < stavki.size(); i++) {
		if (stavki[i].getIDLot() == id) {
			result.push_back(stavki[i]);
		}
	}
	return result;
}

Stavka* DAO::getStavkaById(int id) {
	for (int i = 0; i < stavki.size(); i++) {
		if (stavki[i].getIDStavka() == id) {
			return &stavki[i];
		}
	}
	return NULL;
}

void DAO::saveSeller(Seller seller) {
	ofstream file;
	file.open("seller.txt", ios::binary | ios::app | ios::out);
	file << seller;
	file.close();
	sellers.push_back(seller);
}

void DAO::saveParticipant(Participant participant) {
	ofstream file;
	file.open("participant.txt", ios::binary | ios::app | ios::out);
	file << participant;
	file.close();
	participants.push_back(participant);
}

void DAO::saveLot(Lot lot) {
	writeLotToFile(lot);
	lots.push_back(lot);
}

void DAO::writeLotToFile(Lot lot) {
	ofstream file;
	file.open("lots.txt", ios::binary | ios::app | ios::out);
	file << lot;
	file.close();
}

void DAO::saveStavka(Stavka stavka) {
	writeStavkaToFile(stavka);
	stavki.push_back(stavka);
}

void DAO::writeStavkaToFile(Stavka stavka) {
	ofstream file;
	file.open("stavki.txt", ios::binary | ios::app | ios::out);
	file << stavka;
	file.close();
}

User* DAO::getUserByLogin(string login) {
	for (int i = 0; i < sellers.size(); i++) {
		if (sellers[i].getLogin()._Equal(login)) {
			return &sellers[i];
		}
	}
	for (int i = 0; i < participants.size(); i++) {
		if (participants[i].getLogin()._Equal(login)) {
			return &participants[i];
		}
	}
	return nullptr;
}

Vector<Lot> DAO::getLotsBySellerId(int id) {
	Vector<Lot> result = Vector<Lot>();
	for (int i = 0; i < lots.size(); i++) {
		if (lots[i].getSellerId() == id) {
			result.push_back(lots[i]);
		}
	}
	return result;
}

void DAO::clearLotFile() {
	ofstream file;
	file.open("lots.txt", ios::out);
	file.close();
}

void DAO::clearStavkiFile() {
	ofstream file;
	file.open("stavki.txt", ios::out);
	file.close();
}

void DAO::deleteLotById(int id) {
	for (int i = 0; i < lots.size(); i++) {
		if (lots[i].getID() == id) {
			Vector<Stavka> references = getStavkiByIdLot(id);
		    for (Stavka stavka : references) {
				deleteStavkaById(stavka.getIDStavka());
			}
			lots.erase(lots.begin() + i);
			clearLotFile();
			for (int j = 0; j < lots.size(); j++) {
				writeLotToFile(lots[j]);
			}
			return;
		}
	}
}

void DAO::deleteStavkaById(int id) {
	for (int i = 0; i < stavki.size(); i++) {
		if (stavki[i].getIDStavka() == id) {
			clearStavkiFile();
			stavki.erase(stavki.begin() + i);
			for (int j = 0; j < stavki.size(); j++) {
				writeStavkaToFile(stavki[j]);
			}
			return;
		}
	}
}
