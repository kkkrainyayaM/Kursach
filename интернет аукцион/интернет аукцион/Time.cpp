#include "Time.h"

void Time::setTime() {
	cout << "\nֲגוהטעו הוםü (צטפנאלט): ";
	cin >> day;
	cout << "\nֲגוהטעו לוסÿצ (צטפנאלט): ";
	cin >> month;
	cout << "\nֲגוהטעו דמה (צטפנאלט (4 צטפנû)): ";
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