#include "Time.h"

void Time::setTime() {
	cout << "\n������� ���� (�������): ";
	cin >> day;
	cout << "\n������� ����� (�������): ";
	cin >> month;
	cout << "\n������� ��� (������� (4 �����)): ";
	cin >> year;
}
int Time::getday() {
	return day;
}
int Time::getmonth() {
	return month;
}
int Time::getyear() {
	return year;
}