#include "User.h"
#include "Lot.h"
#include "Menu.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto time = std::time(nullptr);
	cout.imbue(std::locale("ru_RU.utf8"));
	//cout << std::put_time(std::gmtime(&time), "%c");
	char menu1 = NULL;
	int vozvr;
	cout << endl << endl << setw(65) << "��������-�������" << endl << endl;
	cout << "-----------------------------------����� ����������!----------------------------------\n" << endl;
	while (menu1 != 27) {
		
		cout << setw(66) << "����� ����������!" << endl;
		cout << setw(63) << "�������� ����� ����" << endl
			<< setw(65) << "1.�����������" << endl
			<< setw(56) << "2.����" << endl
			<< setw(60) << "Esc.�����" << endl;
		menu1 = _getche();
		switch (menu1) {
		case '1':
			system("cls");
			vozvr = (Menu::registration());
			/*Menu::setStatus(vozvr);
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
				cout << "\n��������� ������!";
				system("pause");
				break;
			}
			break;*/

		/*case '2':
		{
			system("cls");
			int Id = (Menu::autorization());
			if (Id < 200) {
				Seller s;
				s.getID(Id);
				s.getName(Id);
				Menu::menuSel();
				system("pause");
				break;
			}
			else {
				Participant p;
				p.getID(Id);
				p.getName(Id);
				Menu::menuPart();
				system("pause");
				break;
			}
			break;
		}*/
		case 27:
			cout << "����� �������!";
			break;
		default:
			cout << "�������� ����� ���� ���������";
			system("pause");
			break;
		}
	}
	exit(-1);
}
