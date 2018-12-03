#pragma once
#pragma once
#include <map> 
class Mapper {
	map <int, int> SelLot;
	map <int, int> LotPart;
public:
	Mapper() {};
	void setSelLot(int s, int l) {
		SelLot.insert(pair<int, int>(s, l));
	}
	void setLotPart(int l, int p) {
		LotPart.insert(pair<int, int>(l, p));
	}
};