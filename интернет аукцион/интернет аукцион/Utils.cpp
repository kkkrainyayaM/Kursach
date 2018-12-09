#include "Lot.h"
#include "DAO.h"
#include <algorithm>
bool funcTitile (Lot & a, Lot & b) { 
		return a.getTitle() < b.getTitle(); 
	}

Vector<Lot>& sortLotsByTitle(Vector<Lot>& lots) {
	bool funcTitle(Lot & a, Lot & b);
sort(lots.begin(), lots.end(), funcTitle);
	std::sort(lots.begin(), lots.end());
	return lots;
}

bool funcStartPrice(Lot & a, Lot & b) {
	return a.getStartPrice() < b.getStartPrice();
}

Vector<Lot>& sortLotsByTitle(Vector<Lot>& lots) {
	bool funcStartPrice(Lot & a, Lot & b);
	sort(lots.begin(), lots.end(), funcStartPrice);
	std::sort(lots.begin(), lots.end());
	return lots;
}

Lot* filtrLotsByStartPrise(Vector<Lot>& lots, float otPr, float doPr) {
	for (int i = 0; i < lots.size(); i++) {
		if ((lots[i].getStartPrice() > otPr)&&(lots[i].getStartPrice() > doPr)) {
			return &lots[i];
		}
	}
	return NULL;
}

Lot* findByTitle(Vector<Lot>& lots, string title) {
	for (int i = 0; i < lots.size(); i++) {
		if (lots[i].getTitle() == title){
			return &lots[i];
		}
	}
	return NULL;
}


