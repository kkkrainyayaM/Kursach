#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>
//const int NotUsed = system("color F0");
using namespace std;
using std::string;
#if defined(max)
#undef max
#endif

class Menu {
	//static string status;
public:
	/*static void setStatus(int st) {
		if (st == 1) {
			status = "seller";
		}
		else if (st == 2) {
			status = "participant";
		}
		else status = " ";
	}*/
	static int registration();
	static int autorization();
	static int menuSel();
	static int menuPart();
};

