#pragma once
#include "Lot.h"
#include "List.h"
#include "User.h"
#include "Participant.h"
#include "Seller.h"

class DAO {
private:
	List<Seller> sellerList;
	List<Participant> participantList;
	List<Lot> lotList;
	static DAO* instance;
	DAO() {
		instance->sellerList = List<Seller>();
		instance->participantList = List<Participant>();
		instance->lotList = List<Lot>();
	}
	DAO(const DAO&);
public:
	static DAO& getInstance() {
		if (instance == NULL) {
			instance = new DAO();
			instance->initSellerList();
			instance->initPartList();
			instance->initLotList();
		}
		return *instance;
	}

	void initSellerList() {
		ifstream file("seller.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			Seller seller = Seller();
			sellerList.push_back(seller);
		}
		file.close();
	}

	void initPartList() {
		ifstream file("participant.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			Participant participant = Participant();
			participantList.push_back(participant);
		}
		file.close();
	}
	void initLotList() {
		ifstream file("lots.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			Lot lot = Lot();
			lotList.push_back(lot);
		}
		file.close();
	}

	List<Seller>& getAllSellers() {
		return sellerList;
	}

	List<Participant>& getAllPart() {
		return participantList;
	}

	List<Lot>& getAllLots() {
		return lotList;
	}

	Seller* getSellerById(int id) {
		for (int i = 0; i < sellerList.size(); i++) {
			if (sellerList.get(i)->getID() == id) {
				return sellerList.get(i);
			}
		}
		return NULL;
	}
	
	Participant* getPartById(int id) {
		for (int i = 0; i < participantList.size(); i++) {
			if (participantList.get(i)->getID() == id) {
				return participantList.get(i);
			}
		}
		return NULL;
	}

	Lot* getLotById(int id) {
		for (int i = 0; i < lotList.size(); i++) {
			if (lotList.get(i)->getID() == id) {
				return lotList.get(i);
			}
		}
		return NULL;
	}

	void saveSeller(Seller seller) {
		ofstream file;
		file.open("seller.txt", ios::binary | ios::app | ios::out);
		file << seller;
		file.close();
	}

	void saveParticipant(Participant participant) {
		ofstream file;
		file.open("participant.txt", ios::binary | ios::app | ios::out);
		file << participant;
		file.close();
	}

	void saveLot(Lot lot) {
		ofstream file;
		file.open("lots.txt", ios::binary | ios::app | ios::out);
		file << lot;
		file.close();
	}
};