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
	DAO() {}

	void initSellerVector();

	void initPartVector();

	void initLotVector();

	void initStavkaVector();

public:
	static DAO* getInstance();

	Vector<Seller>& getAllSellers();

	Vector<Participant>& getAllPart();

	Vector<Lot>& getAllLots();

	Vector<Stavka>& getAllStavki();

	Seller* getSellerById(int id);

	Participant* getPartById(int id);

	Lot* getLotById(int id);

	Stavka* getStavkaByIdPart(int id);

	Stavka* getStavkaByIdLot(int id);

	Stavka* getStavkaById(int id);

	void saveSeller(Seller seller);

	void saveParticipant(Participant participant);

	void saveLot(Lot lot);

	void saveStavka(Stavka stavka);

	User* getUserByLogin(string login);

	Vector<Lot> getLotsBySellerId(int id);
};
