#include "User.h"
#include "Lot.h"
#include "Mapper.h"
#include "List.h"
void Seller::setName() {
	std::string name;
	cin.clear();
	cout << "Ваше Имя: ";
	getline(cin, name);
	ofstream file("seller.txt");
	file << ID << ' ' << name;
	file.close();
}
void Seller::getName(int id) {
	Seller s;
	List<Seller>l;
	ifstream file("seller.txt", ios::in | ios::binary);
	while (!(file.eof())) {

		file.read(reinterpret_cast<char*>(s.ID), sizeof(s.ID));
		file.read(reinterpret_cast<char*>(s.name), sizeof(s.name));
		file.read(reinterpret_cast<char*>(s.raiting), sizeof(s.raiting));
		l.push_back(s);
	}

	//if (Id[r] == id) {
		//name = Name[r]; raiting = Rait[r];
		//break;
	file.close();
}
void Participant::setName() {
	std::string name;
	fflush(stdin);
	cout << "Ваше Имя: ";
	getline(cin, name);
	ofstream file("participant.txt");
	file << ID << ' ' << name;
	file.close();
}
void Participant::getName(int id) {
	int Id[20];
	float St[20];
	string Name[20];
	ifstream file("participant.txt");
	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
	while (!(file.eof())) {
		for (int r = 0; r < file.eof(); r++)
		{
			file >> Id[r];
			file >> Name[r];
			file >> St[r];
			if (Id[r] == id) {
				name = Name[r]; stavka = St[r];
				break;
			}
		}
	}
	file.close();
};
void User::setLogPas() {
	cout << "Введите логин: ";
	cin.getline(login, 15);
	int q = 0;
	while (q == 0) {
		cout << "Введите пароль: "; cin.getline(password, 15);
		if ((strlen(password) > 4) || (strlen(password) < 14)) {
			q = 1;
			break;
		}
		else {
			cout << "Повторите ввод! Длина пароля не должна быть меньше 5 и больше 15 символов!" << endl;
			cin.clear();
		}
	}
	ofstream file;
	file.open("log_pas.txt", ios::binary | ios::app | ios::out);
	file << ID << ' ' << login << ' ';
	file.close();
}
void User::shifrPas() {
	int i = 0, n = 0;
	char alf[] = "abcedfghijklmnopqrstuvwxyz0123456789#!@$%^&*-+=";
	for (n = 0; n < strlen(password) + 1; n++)
	{
		for (i = 0; i < 47; i++)
		{
			if (password[n] == alf[i])
			{
				if (i >= 47)
					password[n] = alf[i - 47];
				else
					password[n] = alf[i + 4];//сдвигаем вправо на 4
				break;//принудительно выходим из цикла
			}
		}
	}
	ofstream file("log_pas.txt", ios::binary | ios::app | ios::out);
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		file << password << '\n';
	}
	file.close();
}
void Seller::setID() {
	//Mapper map;
	List<User>l1;
	User *u;
	Seller s;
	u = &s;
	const char ch = '\n', pr = ' ';
	int r = 0;
	int sel[4] = { 0 };
	int lot[4] = { 0 };
	int part[4] = { 0 };
	fstream file("ID.txt", ios::in | ios::binary | ios::app | ios::out);
	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
	else if (file.eof()) {
		ID = 100;
	}
	//while (!(file.eof())) {
	else {
		for (r; r + 1 < !(file.eof()); r++)
		{
			file >> sel[r] >> lot[r] >> part[r];
		}
		ID = sel[r] + 1;
	}
	//}
	//if (sel[r] == NULL)
	//else {  };
	file << ID << ' ';
	file.close();

}
int Seller::getID(int id) {
	ID = id;
	return ID;
}
void Participant::setID() {
	const int len = 4;
	const char ch = '\n', pr = ' ';
	int  q = 0;
	char sel[len];
	char lot[len];
	char part[len];
	fstream file("ID.txt", ios::in | ios::binary | ios::out | ios::app);
	if (!file.is_open()) cout << "Файл не может быть открыт!\n";
	while (!(file.eof())) {
		for (int r = 0; r < file.eof(); r++)
		{
			file >> sel[r];
			file >> lot[r];
			file >> part[r];
			//file >> ch;
			q++;
		}
		if (part[q] == 0) ID = 200;
		else { ID = part[q] + 1; };
	}
	file << ID << ' ';
	file.close();
}
int Participant::getID(int id) {
	ID = id;
	return ID;
}
void Seller::viewInf() {
	char w = NULL;
	cout << name << ", вы вошли в личный аккаунт." << endl;
	cout << "Ваш логин: " << login << endl;
	cout.fill('*');
	cout << "Ваш рейтинг: " << setw(raiting) << "(" << raiting << ")" << endl;
	const int len = 4;
	const char ch = '\n', pr = ' ';
	char sel[len];
	char lot[len];
	char part[len];
	int lots[5], q = 0;
	ifstream file1("ID.txt", ios::in | ios::binary);
	if (!file1.is_open()) cout << "Файл не может быть открыт!\n";
	while (!(file1.eof())) {
		for (int r = 0; r < file1.eof(); r++)
		{
			file1 >> sel[r];
			file1 >> lot[r];
			file1 >> part[r];
			//file >> ch;
			if (sel[r] == ID) {
				lots[q] = lot[r];
				q++;
			}
		}
	}
	file1.close();
	cout << "Ваши товары:" << endl;
	ifstream file2("lots.txt", ios::in | ios::binary);
	if (!file2.is_open()) cout << "Файл не может быть открыт!\n";
	int id[20], p = 0;
	string t[20], d[20];
	float s[20], m[20], b[20];
	while (!(file2.eof())) {
		for (int r = 0; r < file2.eof(); r++) {
			file2 >> id[r];
			file2 >> t[r];
			file2 >> d[r];
			file2 >> s[r];
			file2 >> m[r];
			file2 >> b[r];
			for (q = 0; q < 5; q++) {
				if (id[r] == lots[q]) {
					cout << "Название: " << t[r] << endl << "Описание: " << d[r] << endl
						<< "Стартовая цена: " << s[r] << endl << "Максимальная ставка: " << m[r] << endl
						<< "Блиц-цена: " << b[r] << endl;
					p++;
				}
				else {
					cout << "Добавьте лот!" << endl << "Добавить лот?(1 - да/ 2 - нет)";
					int v;
					cin >> v;
					if (v == 1) Seller::createLot();
				}
			}
			cout << "Для выхода нажмите Esc.";
			cin >> w;
			if (w == 27)break;
		}
	}
	file2.close();
}
void Participant::myBuy() {
	cout << "Вы вошли в личный аккаунт." << endl;
	//dopisat
}
void Seller::createLot(int idSel) {
	Lot l;
	int q = 1, i = 0;
	while (q == 1) {
		Mapper m1;
		l.setID();
		int idLot = l.getID();
		l.setLot();
		m1.setSelLot(idSel, idLot);
		cout << "Лот успешно добавлен!" << endl << "Продолжить - 1. Выход - 0";
		cin >> q;
		if (q == 1) Seller::createLot(idSel);
		else break;
	}
}
int Seller::retID() {
	return ID;
}
int Participant::retID() {
	return ID;
}