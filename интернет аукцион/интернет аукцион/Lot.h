#pragma once
#include <string> 
#include "IDGenerator.h"
using namespace std;
class Lot {
	int ID;
	string title;
	string descr;
	float startPrice;
	float maxStavka;
	float blicPrice;
	int period;

public:
	Lot() {
		ID = IDGenerator::getInstance()->getLotId();
		title = " ";
		descr = " ";
		startPrice = 10;
		maxStavka = 10;
		blicPrice = 100;
		period = 5;
	};
	Lot(string t, string d, float s, float m, float b, int p) {
		ID = IDGenerator::getInstance()->getLotId();
		title = t;
		descr = d;
		startPrice = s;
		blicPrice = b;
		period = p;
	}
	Lot( int id, string t, string d, float s, float m, float b, int p) {
		ID = id;
		title = t;
		descr = d;
		startPrice = s;
		blicPrice = b;
		period = p;
	}
	~Lot() {
		/*delete &title;
		delete &descr;*/
	};
	//void setLot();
	//void setID();
	int getID();
	string getTitle();
	string getDescr();
	float getStartPrice();
	float getMaxStavka();
	float getBlicPrice();
	int getPeriod();
	//static void printLots();
	//static void menuSort();
	//static void filtr();
	//static void sortTitle();
	//static void sortStVozr();
	//static void sortPrice();
	//void redact();
	//void buyLot(int num1, int idPart);
	//void deleteLot();
	friend ostream& operator<<(ostream& s, Lot& lot);
};