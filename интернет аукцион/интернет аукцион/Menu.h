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
#include <limits>
#include "AuthService.h"
const int NotUsed = system("color F0");
using namespace std;
using std::string;
#if defined(max)
#undef max
#endif

class Menu {
		/*static int day;
		static int month;
		static int year;*/
public:
	static int registration();
	static Role autorization();
	static int menuSel();
	static int menuPart();
	static void programmTime();
	/*static int prov_year(int year);
	static int prov_month(int month);
	static int prov_day(int day);*/
	/*static void setDay(int day1);
	static void setMonth(int month1);
	static void setYear(int month1);*/
};

