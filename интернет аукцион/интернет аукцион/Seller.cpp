#include "Seller.h"
#include "User.h"

//void Seller::viewInf() {
//	char w = NULL;
//	cout << name << ", вы вошли в личный аккаунт." << endl;
//	cout << "Ваш логин: " << login << endl;
//	cout.fill('*');
//	cout << "Ваш рейтинг: " << setw(raiting) << "(" << raiting << ")" << endl;
//
//	DAO::getIDLotByIDSel(ID);//
//	cout << "Ваши товары:" << endl;
//
//	cout << "Название: " << t[r] << endl << "Описание: " << d[r] << endl
//		<< "Стартовая цена: " << s[r] << endl << "Максимальная ставка: " << m[r] << endl
//		<< "Блиц-цена: " << b[r] << endl;
//
//	cout << "Добавьте лот!" << endl << "Добавить лот?(1 - да/ 2 - нет)";
//	int v;
//	cin >> v;
//	//if (v == 1) Seller::createLot();
//			cout << "Для выхода нажмите Esc.";
//			cin >> w;
//			if (w == 27)break;
//		}
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

ostream& operator<< (ostream& s, Seller& seller) {
	s << seller.getID() << " " << seller.getLogin() << " " << seller.getPassword() << " " <<
		seller.getName() << " " << seller.getRaiting() << endl;
	return s;
}

