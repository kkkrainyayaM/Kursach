//#pragma once
//using namespace std;
//
//ostream& formatDateTime(ostream& out, const tm& t, const char* fmt) {
//
//	const time_put& dateWriter = use_facet >(out.getloc());
//
//	int n = strlen(fmt);
//
//	if (dateWriter.put(out, out, ' ', &t, fmt, fmt + n).failed()) {
//
//		throw runtime_error("невозможно отформатировать дату и время");
//
//	}
//
//	return out;
//
//}
//
//string dateTimeToString(const tm& t, const char* format) {
//
//	stringstream s;
//
//	formatDateTime(s, t.format);
//
//	return s.str();
//
//}
//
//tm now() {
//
//	time_t now = time(0);
//
//	return *localtime(&now);
//
//}