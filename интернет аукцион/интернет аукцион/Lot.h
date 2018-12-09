#pragma once
#include <string>
#include <iostream>
#include "IDGenerator.h"
#include "Stavka.h"

using namespace std;
class Lot {
	int ID;
	string title;
	string descr;
	float startPrice;
	int lastStavkaId;
	int sellerID;

public:
	Lot() {};
	Lot(int id, string t, string d, float s, int sellerId, int stavkaId) {
		ID = id;
		title = t;
		descr = d;
		startPrice = s;
		sellerID = sellerId;
		lastStavkaId = stavkaId;
	}
	~Lot() {
		/*delete &title;
		delete &descr;*/
	};
	void setID(int id);
	int getID();
	string getTitle();
	void setTitle(string title);
	string getDescr();
	void setDescr(string descr);
	float getStartPrice();
	void setStartPrice(float startPrice);
	int getSellerId();
	void setSellerId(int id);
	int getLastStavkaId();
	void setLastStavkaId(int id);
	void printLot();
	//Vector<Lot>& sortLotsByTitle(Vector<Lot>& lots);
	static Lot createLot();
	friend ostream& operator<<(ostream& s, Lot& lot);
};