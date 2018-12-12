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
		cout << endl << endl << setw(65) << "��������-�������" << endl
			<< setw(65) << "----------------" << endl;
		cout << setw(66) << "����� ����������!" << endl << endl;

		cout << setw(67) << "�������� ����� ����:" << endl
			<< setw(65) << "1.�����������" << endl
			<< setw(58) << "2.����" << endl
			<< setw(59) << "ESC.�����" << endl << endl
			<< setw(61) << "��� �����: ";
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
				cout << "\n��������� ������!"<< endl;
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
				cout << "\n��������� ������!"<< endl;
				system("pause");
				break;
			}
			break;

		}
		case 27:
			IDGenerator::getInstance()->~IDGenerator();
			cout << " ����� �������!" << endl;
			break;
		default:
			cout << "\n�������� ����� ���� ���������"<< endl;
			system("pause");
			break;
		}
	}
	exit(-1);
}
