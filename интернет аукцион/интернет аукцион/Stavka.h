#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Lot.h"
#include "IDGenerator.h"
#include "Participant.h"
using namespace std;

class Stavka{
	float stavka;
	int IDlot;
	int IDpart;
public:
	Stavka() {
		stavka = 10;
		IDpart = IDGenerator::getInstance()->getUserId();
		IDlot = IDGenerator::getInstance()->getLotId();
	}
	Stavka(float st) {
		stavka = st;
		IDpart = IDGenerator::getInstance()->getUserId();
		IDlot = IDGenerator::getInstance()->getLotId();
	}
	void menuStavka();
	int getIDPart();
	int getIDLot();
	float getStavka();
	friend ostream& operator<< (ostream& s, Stavka& stavka);
};
