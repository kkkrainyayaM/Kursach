#pragma once
#include "Lot.h"
#include "List.h"
#include "User.h"

class DAO {
private:
	List<Seller> sellerList;
	List<Participant> participantList;
	List<Lot> lotList;
	static DAO* instance;
	DAO() {}
	DAO(const DAO&);
public:
	static DAO& getInstance() {
		if (instance == NULL) {
			instance = new DAO();
			instance->sellerList = List<Seller>();
			instance->participantList = List<Participant>();
			instance->lotList = List<Lot>();
		}
		return *instance;
	}

	void initUserList() {
		ifstream file("seller.txt", ios::in | ios::binary);
		while (!(file.eof())) {
			Seller seller = Seller();
			/*file.read(reinterpret_cast<char*>(seller.getID()), sizeof(seller.ID));
			file.read(reinterpret_cast<char*>(s.name), sizeof(s.name));
			file.read(reinterpret_cast<char*>(s.raiting), sizeof(s.raiting));*/
			sellerList.push_back(seller);
		}

		file.close();
	}



};