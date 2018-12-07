#include "Seller.h"
//
//void Seller::printInf(User *user) {
//	user->toString();
//    cout << "Вы вошли в личный аккаунт." << endl;
//	char w = NULL;
//	cout.fill('*');
//	//cout << "Ваш рейтинг: " << setw(user->getRaiting()) << " (" << user->getRaiting() << ")" << endl;
//
//	//DAO::getIDLotByIDSel(ID);
//	//cout << "Ваши товары:" << endl;
//
//	//Lot::cout << "Название: " << title << endl << "Описание: " << d[r] << endl
//	//	<< "Стартовая цена: " << s[r] << endl << "Максимальная ставка: " << m[r] << endl
//	//	<< "Блиц-цена: " << b[r] << endl;
//
//	//cout << "Добавьте лот!" << endl << "Добавить лот?(1 - да/ 2 - нет)";
//	//int v;
//	//cin >> v;
//	////if (v == 1) Seller::createLot();
//	//		cout << "Для выхода нажмите Esc.";
//	//		cin >> w;
//	//		if (w == 27)break;
//	//	}
//}
//void Seller::createLot(int idSel) {
//	Lot l;
//	int q = 1, i = 0;
//	while (q == 1) {
//		Mapper m1;
//		l.setID();
//		int idLot = l.getID();
//		l.setLot();
//		m1.setSelLot(idSel, idLot);
//		cout << "Лот успешно добавлен!" << endl << "Продолжить - 1. Выход - 0";
//		cin >> q;
//		if (q == 1) Seller::createLot(idSel);
//		else break;
//	}
//}

//istream& Seller::operator>> (istream& s,const Seller& seller) {
//	s << seller.getID() << ' ';
//	s << seller.getLogin() << ' '
//	return s;
//}

int Seller::getRaiting() {
	return this->raiting;
}

void Seller::toString() {
	cout << "Имя: " << getName() << endl
		<< "Логин: " << getLogin() << endl
		<< "Пароль: " << getPassword() << endl;
}

ostream& operator<< (ostream& s, Seller& seller) {
	s << seller.getID() << " " << seller.getLogin() << " " << seller.getPassword() << " " <<
		seller.getName() << " " << seller.getRaiting() << endl;
	return s;
}

