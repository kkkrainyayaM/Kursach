#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "IDGenerator.h"
#include "Lot.h"
#include "Participant.h"
using namespace std;

class Stavka{
	int IDstavka;
	float stavka;
	int IDlot;
	int IDpart;
public:
	Stavka() {
		stavka = 10;
	}
	Stavka(int IDst, int IDp, int IDl ,float st) {
		IDstavka = IDst;
		stavka = st;
		IDpart = IDp;
		IDlot = IDl;
	}
	/*Stavka(float st) {
		stavka = st;
		IDpart = IDGenerator::getInstance()->getUserId();
		IDlot = IDGenerator::getInstance()->getLotId();
	}*/
	~Stavka() {}
	void menuStavka();
	int getIDPart();
	int getIDLot();
	int getIDStavka();
	float getStavka();
	friend ostream& operator<< (ostream& s, Stavka& stavka);
	string toString();
};
