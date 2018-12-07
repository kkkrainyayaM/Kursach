#include "DAO.h"

	DAO *DAO::instance = 0;

	void DAO::initSellerVector() {
		ifstream file("seller.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			if (file.peek() != EOF) {
				int id, raiting;
				string name, login, password;
				file >> id  >> login >> password >> name >> raiting;
				Seller seller = Seller(id, name, login, password, raiting);
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
			file >> id >> name >> login >> password;
			Participant participant = Participant(id, name, login, password);
			participants.push_back(participant);
		}
		file.close();
	}
	void DAO::initLotVector() {
		ifstream file("lots.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			int ID, period;
			string title, descr;
			float startPrice, maxStavka, blicPrice;
			file >> ID >> title >> descr >> startPrice >> maxStavka >> blicPrice >> period;
			Lot lot = Lot(ID, title, descr, startPrice, maxStavka, blicPrice, period);
			lots.push_back(lot);
		}
		file.close();
	}

	void DAO::initStavkaVector() {
		ifstream file("stavki.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			float _stavka;
			int IDl, IDp;
			file >> IDp >> IDl >> _stavka;
			Stavka stavka = Stavka(IDp, IDl, _stavka);
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
			//instance->initStavkaVector();
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

	Stavka* DAO::getStavkaByIdPart(int id) {
		for (int i = 0; i < stavki.size(); i++) {
			if (stavki[i].getIDPart() == id) {
				return &stavki[i];
			}
		}
		return NULL;
	}

	Stavka* DAO::getStavkaByIdLot(int id) {
		for (int i = 0; i < stavki.size(); i++) {
			if (stavki[i].getIDLot() == id) {
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
		ofstream file;
		file.open("lots.txt", ios::binary | ios::app | ios::out);
		file << lot;
		file.close();
		lots.push_back(lot);
	}

	void DAO::saveStavka(Stavka stavka) {
		ofstream file;
		file.open("stavki.txt", ios::binary | ios::app | ios::out);
		file << stavka;
		file.close();
		stavki.push_back(stavka);
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