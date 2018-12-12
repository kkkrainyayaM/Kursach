#pragma once
#include "Menu.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char menu1 = NULL;
	int vozvr;
	while (menu1 != 27) {
		system("cls");
		//Menu::programmTime();
		cout << endl << endl << setw(65) << "ИНТЕРНЕТ-АУКЦИОН" << endl
			<< setw(65) << "----------------" << endl;
		cout << setw(66) << "ДОБРО ПОЖАЛОВАТЬ!" << endl << endl;

		cout << setw(67) << "Выберите пункт меню:" << endl
			<< setw(65) << "1.Регистрация" << endl
			<< setw(58) << "2.Вход" << endl
			<< setw(59) << "ESC.Выход" << endl << endl
			<< setw(61) << "Ваш выбор: ";
		menu1 = _getche();
		switch (menu1) {
		case '1':
			system("cls");
			vozvr = (Menu::registration());
			switch (vozvr) {
			case 1:
				Menu::menuSel();
				system("pause");
				break;
			case 2:
				Menu::menuPart();
				system("pause");
				break;
			default:
				cout << "\nПроизошла Ошибка!"<< endl;
				system("pause");
				break;
			}
			break;

		case '2':
		{
			system("cls");
			Role role;
			role = Menu::autorization();
			switch (role) {
			case SELLER:
				Menu::menuSel();
				system("pause");
				break;
			case PARTICIPANT:
				Menu::menuPart();
				system("pause");
				break;
			default:
				cout << "\nПроизошла Ошибка!"<< endl;
				system("pause");
				break;
			}
			break;

		}
		case 27:
			IDGenerator::getInstance()->~IDGenerator();
			cout << " Всего Доброго!" << endl;
			break;
		default:
			cout << "\nВыберите пункт меню корректно"<< endl;
			system("pause");
			break;
		}
	}
	exit(-1);
}
