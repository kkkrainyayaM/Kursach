#pragma once
#include "Menu.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//auto time = std::time(nullptr);
	//cout.imbue(std::locale("ru_RU.utf8"));
	//cout << std::put_time(std::gmtime(&time), "%c"); добавить время
	char menu1 = '0';
	int vozvr;
	cout << endl << endl << setw(65) << "ИНТЕРНЕТ-АУКЦИОН" << endl << endl;
	cout << "-----------------------------------Добро Пожаловать!----------------------------------\n" << endl;
	while (menu1 != 27) {
		
		cout << setw(66) << "ДОБРО ПОЖАЛОВАТЬ!" << endl;
		cout << setw(63) << "Выберите пункт меню" << endl
			<< setw(65) << "1.Регистрация" << endl
			<< setw(56) << "2.Вход" << endl
			<< setw(60) << "0.Выход" << endl;
		cin >> menu1;
		switch (menu1) {
		case '1':
			system("cls");
			vozvr = (Menu::registration());
			//Menu::setStatus(vozvr);
			switch (vozvr) {
			case 1:
				//Menu::menuSel();
				system("pause");
				break;
			case 2:
				//Menu::menuPart();
				system("pause");
				break;
			default:
				cout << "\nПроизошла Ошибка!";
				system("pause");
				break;
			}
			break;

		case '2':
		{
			system("cls");
			Menu::autorization();
			system("pause");
			break;
		}
		case '0':
			IDGenerator::getInstance()->~IDGenerator();
			cout << "Всего Доброго!";
			break;
		default:
			cout << "Выберите пункт меню корректно";
			system("pause");
			break;
		}
	}
	exit(-1);
}
