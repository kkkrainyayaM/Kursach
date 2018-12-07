#include "Lot.h"
//void Lot::setID() {
//	const int LEN = 4;
//	const char CH = '\n', SPACE = ' ';
//	int  q = 0;
//	char sel[LEN];
//	char lot[LEN];
//	char part[LEN];
//	fstream file("ID.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++)
//		{
//			file >> sel[r];
//			file >> lot[r];
//			file >> part[r];
//			//file >> ch;
//			q++;
//		}
//		if (lot[q] == 0) ID = 300;
//		else { ID = lot[q] + 1; };
//	}
//	file << ID << ' ';
//	file.close();
//}
int Lot::getID() {
	return ID;
}
//void Lot::printLots() {
//	int id[20];
//	string t[20], d[20];
//	float s[20], m[20], b[20];
//	fstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++) {
//			file >> id[r];
//			file >> t[r];
//			file >> d[r];
//			file >> s[r];
//			file >> m[r];
//			file >> b[r];
//			cout << "Название: " << t[r] << endl << "Описание: " << d[r] << endl
//				<< "Стартовая цена: " << s[r] << endl << "Максимальная ставка: " << m[r] << endl
//				<< "Блиц-цена: " << b[r] << endl;
//		}
//	}
//	file.close();
//	cout << "Нажмите 0 для возврата в меню.";
//	int q;
//	cin >> q;
//	if (q == 0) Menu::menuSel();
//}
//void Lot::setLot() {
//	cout << "ДОБАВЛЕНИЕ ТОВАРА" << endl << "Название: ";
//	cin >> title;
//	cout << "\nОписание: ";
//	cin >> descr;
//	cout << "\nСтартовая цена: ";
//	cin >> startPrice;
//	cout << "\nБлиц-цена: ";
//	cin >> blicPrice;
//	cout << "\nПериод торгов: ";
//	cin >> period;
//}
//void Lot::filtr() {
//	float ot, doo;
//	int id[20], q = 1;
//	string t[20], d[20];
//	float s[20], m[20], b[20];
//	ifstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
//	while (q == 1) {
//		cout << "Фильтрация по максимальной текущей ставке." << endl << "Введите диапазон значений:" << endl << "от ";
//		cin >> ot;
//		cout << endl << "до ";
//		cin >> doo;
//
//		while (!(file.eof())) {
//			for (int r = 0; r < file.eof(); r++) {
//				file >> id[r];
//				file >> t[r];
//				file >> d[r];
//				file >> s[r];
//				file >> m[r];
//				file >> b[r];
//				if (m[r] > ot || m[r] < doo) {
//					cout << "Название: " << t[r] << endl << "Описание: " << d[r] << endl
//						<< "Стартовая цена: " << s[r] << endl << "Максимальная ставка: " << m[r] << endl
//						<< "Блиц-цена: " << b[r] << endl;
//				}
//			}
//		}
//		file.close();
//		cout << "Нажмите 0 для возврата в меню.";
//		int q;
//		cin >> q;
//		if (q == 0) Menu::menuSel(); break;
//	}
//}
//void Lot::menuSort() {
//	cout << "1.Сортировка по алфавиту.\n2.Сортировка по макс. ставке(по возрастанию).\n3.Сортровка по макс. ставке(по убыванию).\nEsc.Выход.\n";
//	char vib = NULL;
//	switch (vib) {
//	case '1': sortTitle(); break;
//	case '2': sortStVozr(); break;
//	case '3': sortPrice(); break;
//	case 23: break;
//	}
//}
//void Lot::sortTitle() {
//	int id[20], q = 0;
//	string t[20], d[20];
//	float s[20], m[20], b[20];
//	ifstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++) {
//			file >> id[r];
//			file >> t[r];
//			file >> d[r];
//			file >> s[r];
//			file >> m[r];
//			file >> b[r]; q++;
//		}
//	}
//	sort(begin(t), end(t));
//	for (int i = 0; i < q + 1; i++) {
//		cout << "Название: " << t[i] << endl << "Описание: " << d[i] << endl
//			<< "Стартовая цена: " << s[i] << endl << "Максимальная ставка: " << m[i] << endl
//			<< "Блиц-цена: " << b[i] << endl;
//	}
//	file.close();
//}
//void Lot::sortStVozr() {
//	int id[20], q = 0;
//	string t[20], d[20], temp;
//	float s[20], m[20], b[20];
//	ifstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++) {
//			file >> id[r];
//			file >> t[r];
//			file >> d[r];
//			file >> s[r];
//			file >> m[r];
//			file >> b[r]; q++;
//		}
//	}
//	sort(begin(m), end(m));
//	for (int i = 0; i < q + 1; i++) {
//		cout << "Название: " << t[i] << endl << "Описание: " << d[i] << endl
//			<< "Стартовая цена: " << s[i] << endl << "Максимальная ставка: " << m[i] << endl
//			<< "Блиц-цена: " << b[i] << endl;
//	}
//	file.close();
//}
//void Lot::sortPrice() {
//	int id[20], q = 0;
//	string t[20], d[20], temp;
//	float s[20], m[20], b[20];
//	ifstream file("lots.txt", ios::in | ios::binary);
//	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
//	while (!(file.eof())) {
//		for (int r = 0; r < file.eof(); r++) {
//			file >> id[r];
//			file >> t[r];
//			file >> d[r];
//			file >> s[r];
//			file >> m[r];
//			file >> b[r]; q++;
//		}
//	}
//	sort(begin(s), end(s));
//	for (int i = 0; i < q + 1; i++) {
//		cout << "Название: " << t[i] << endl << "Описание: " << d[i] << endl
//			<< "Стартовая цена: " << s[i] << endl << "Максимальная ставка: " << m[i] << endl
//			<< "Блиц-цена: " << b[i] << endl;
//	}
//	file.close();
//}
//void Lot::buyLot(int num1, int idPart) {
//	cout << "1.Купить.\n0.Выход.";
//	int q;
//	cin >> q;
//	if (q == 1) {
//		Mapper m1;
//		m1.setSelLot(num1, idPart);
//		cout << endl << "Заказ принят. Спасибо  за покупку!";
//	}
//}
ostream& operator<< (ostream& s, Lot& lot) {
	s << lot.getID() << " " << lot.getTitle() << " " << lot.getDescr() << " " <<
		lot.getStartPrice() << " " << lot.getMaxStavka() << " " << lot.getBlicPrice()<< " " << lot.getPeriod() << endl;
	return s;
}

string Lot::getTitle() {
	return this->title;
}
string Lot::getDescr() {
	return this->descr;
}
float Lot::getBlicPrice() {
	return this->blicPrice;
}
float Lot::getMaxStavka() {
	return this->maxStavka;
}
float Lot::getStartPrice() {
	return this->startPrice;
}
int Lot::getPeriod() {
	return this->period;
}
