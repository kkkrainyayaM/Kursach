#include <fstream>
using namespace std;

class IDGenerator
{
private:
	int userId;
	int lotId;
	IDGenerator();
	~IDGenerator();
	void init();
	
public:
	int getUserId();
	int getLotId();
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

IDGenerator::~IDGenerator()
{
	ofstream file("ID.txt", ios::in | ios::binary | ios::trunc);
	if (file.is_open()) {
		file << userId << '\n' << lotId << '\n';
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