#pragma once
#include "Lot.h"
#include "Vector.h"
#include "User.h"
#include "Participant.h"
#include "Seller.h"
#include "Stavka.h"

class DAO {
private:
	Vector<Seller> sellers = Vector<Seller>();
	Vector<Participant> participants = Vector<Participant>();
	Vector<Lot> lots = Vector<Lot>();
	Vector<Stavka> stavki = Vector<Stavka>();
	static DAO *instance;
	DAO() {
	}

	void initSellerVector() {
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

	void initPartVector() {
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
	void initLotVector() {
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

	void initStavkaVector() {
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

public:
	static DAO *getInstance() {
		if (!instance) {
			instance = new DAO;
			instance->initSellerVector();
			instance->initPartVector();
			instance->initLotVector();
			//instance->initStavkaVector();
		}
		return instance;
	}

	Vector<Seller>& getAllSellers() {
		return sellers;
	}

	Vector<Participant>& getAllPart() {
		return participants;
	}

	Vector<Lot>& getAllLots() {
		return lots;
	}

	Vector<Stavka>& getAllStavki() {
		return stavki;
	}

	Seller* getSellerById(int id) {
		for (int i = 0; i < sellers.size(); i++) {
			if (sellers[i].getID() == id) {
				return &sellers[i];
			}
		}
		return NULL;
	}

	Participant* getPartById(int id) {
		for (int i = 0; i < participants.size(); i++) {
			if (participants[i].getID() == id) {
				return &participants[i];
			}
		}
		return NULL;
	}

	Lot* getLotById(int id) {
		for (int i = 0; i < lots.size(); i++) {
			if (lots[i].getID() == id) {
				return &lots[i];
			}
		}
		return NULL;
	}

	Stavka* getStavkaByIdPart(int id) {
		for (int i = 0; i < stavki.size(); i++) {
			if (stavki[i].getIDPart() == id) {
				return &stavki[i];
			}
		}
		return NULL;
	}

	Stavka* getStavkaByIdLot(int id) {
		for (int i = 0; i < stavki.size(); i++) {
			if (stavki[i].getIDLot() == id) {
				return &stavki[i];
			}
		}
		return NULL;
	}

	void saveSeller(Seller seller) {
		ofstream file;
		file.open("seller.txt", ios::binary | ios::app | ios::out);
		file << seller;
		file.close();
		sellers.push_back(seller);
	}

	void saveParticipant(Participant participant) {
		ofstream file;
		file.open("participant.txt", ios::binary | ios::app | ios::out);
		file << participant;
		file.close();
		participants.push_back(participant);
	}

	void saveLot(Lot lot) {
		ofstream file;
		file.open("lots.txt", ios::binary | ios::app | ios::out);
		file << lot;
		file.close();
		lots.push_back(lot);
	}

	void saveStavka(Stavka stavka) {
		ofstream file;
		file.open("stavki.txt", ios::binary | ios::app | ios::out);
		file << stavka;
		file.close();
		stavki.push_back(stavka);
	}
};
DAO *DAO::instance = 0;