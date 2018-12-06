#include <fstream>
using namespace std;

class IDGenerator
{
private:
	int userId;
	int lotId;
	IDGenerator();
	~IDGenerator() {};
	void init();
public:
	void saveIDUser();
	void saveIDLot();
	int getUserId();
	int getLotId();
	int getIDLotByIDSel(int id);
	static IDGenerator* getInstance();
};


IDGenerator* IDGenerator::getInstance() {
	static IDGenerator* instance = new IDGenerator();
	return instance;
}

IDGenerator::IDGenerator()
{
	init();
}

void IDGenerator::saveIDUser()
{
	ofstream file("ID.txt", ios::in | ios::binary | ios::trunc);
	if (file.is_open()) {
		file <<userId << ' ';
	}
	file.close();
}
void IDGenerator::saveIDLot()
{
	ofstream file("ID.txt", ios::in | ios::binary | ios::trunc);
	if (file.is_open()) {
		file << lotId << '\n';
	}
	file.close();
}

int IDGenerator::getUserId() {
	return ++userId;
}

int IDGenerator::getLotId() {
	return ++lotId;
}

void IDGenerator::init() {
	ifstream file("ID.txt", ios::in | ios::binary);
	if (file.is_open()) {
		file >> this->userId;
		file >> this->lotId;
	}
	file.close();
}

//int IDGenerator:: getIDLotByIDSel(int id) {
//	for (int i = 0; i < lotId; i++) {
//		if (userId  == id) {//доделать
//			return lotId;
//		}
//	}
//	return NULL;
//}