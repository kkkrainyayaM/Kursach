#pragma once
#include "Menu.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//auto time = std::time(nullptr);
	//cout.imbue(std::locale("ru_RU.utf8"));
	//cout << std::put_time(std::gmtime(&time), "%c"); добавить время
	char menu1 = NULL;
	int vozvr;
	cout << endl << endl << setw(65) << "ИНТЕРНЕТ-АУКЦИОН" << endl
		<< setw(65) << "----------------" << endl;
	cout << setw(66) << "ДОБРО ПОЖАЛОВАТЬ!" << endl<< endl;
	while (menu1 != 27) {
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
			//Menu::setStatus(vozvr);
			switch (vozvr) {
			case 1:
				Menu::menuSel();
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
			vozvr = Menu::autorization();
			switch (vozvr) {
			case 1:
				Menu::menuSel();
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
			
		}
		case 27:
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
