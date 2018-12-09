#pragma once
#include "Lot.h"
#include "Vector.h"
#include "User.h"
#include "Participant.h"
#include "Seller.h"
#include "Stavka.h"

namespace DataAccessObject {

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

		Stavka* getStavkiByIdPart(int id);

		Vector<Stavka> getStavkiByIdLot(int id);

		Stavka* getStavkaById(int id);

		void saveSeller(Seller seller);

		void saveParticipant(Participant participant);

		void saveLot(Lot lot);

		void writeLotToFile(Lot lot);

		void saveStavka(Stavka stavka);

		void writeStavkaToFile(Stavka stavka);

		void clearStavkiFile();

		void clearLotFile();

		//Lot* findByTitle(Vector<Lot>& lots, string title);



		void deleteLotById(int id);

		void deleteStavkaById(int id);

		User* getUserByLogin(string login);

		Vector<Lot> getLotsBySellerId(int id);
	};
}
