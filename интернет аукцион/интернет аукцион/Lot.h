#pragma once
#include <string>
#include <iostream>
#include "IDGenerator.h"
#include "Stavka.h"
#include "Vector.h"
#include "time.h"
#include <ctime>

using namespace std;
class Lot {
	int ID;
	string title;
	string descr;
	float startPrice;
	int lastStavkaId;
	int sellerID;
	int finishYear;
	int finishMonth;
	int finishDay;

public:
	Lot() {};
	Lot(int id, string t, string d, float s,int _d, int m, int y,int sellerId, int stavkaId) {
		ID = id;
		title = t;
		descr = d;
		startPrice = s;
		finishDay = _d;
		finishMonth = m;
		finishYear = y;
		sellerID = sellerId;
		lastStavkaId = stavkaId;
		
	}
	~Lot() {};

	void setID(int id);
	int getID();
	string getTitle();
	void setTitle(string title);
	string getDescr();
	void setDescr(string descr);
	float getStartPrice();
	void setStartPrice(float startPrice);
    static Vector<Lot>& filtrLotsByStPrise(Vector<Lot>& lots, float otPr, float doPr);
	void setDay(int d);
	int getDay();
	void setMonth(int m);
	int getMonth();
	void setYear(int y);
	int getYear();
	int getSellerId();
	void setSellerId(int id);
	int getLastStavkaId();
	void setLastStavkaId(int id);
	void printLot();
	static Vector<Lot>& sortLotsByTitle(Vector<Lot>& lots);
	static Vector<Lot>& sortLotsByStPrice(Vector<Lot>& lots);
	static Lot createLot();
	friend ostream& operator<<(ostream& s, Lot& lot);
};