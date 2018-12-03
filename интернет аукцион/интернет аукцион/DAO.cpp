#pragma once
#include "Lot.h"
#include <vector>
#include "User.h"
#include "Participant.h"
#include "Seller.h"

class DAO {
private:
	vector<Seller> sellers;
	vector<Participant> participants;
	vector<Lot> lots;
	DAO() {
		initSellervector();
		initPartvector();
		initLotvector();
	}
	DAO(const DAO&);
public:
	static DAO& getInstance() {
		static DAO* instance = new DAO();
		return *instance;
	}

	void initSellervector() {
		ifstream file("seller.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			Seller seller = Seller();
			sellers.push_back(seller);
		}
		file.close();
	}

	void initPartvector() {
		ifstream file("participant.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			Participant participant = Participant();
			participants.push_back(participant);
		}
		file.close();
	}
	void initLotvector() {
		ifstream file("lots.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			Lot lot = Lot();
			lots.push_back(lot);
		}
		file.close();
	}

	vector<Seller>& getAllSellers() {
		return sellers;
	}

	vector<Participant>& getAllPart() {
		return participants;
	}

	vector<Lot>& getAllLots() {
		return lots;
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
};