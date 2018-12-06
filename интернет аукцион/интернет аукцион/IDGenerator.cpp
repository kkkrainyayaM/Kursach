#include <fstream>
using namespace std;

class IDGenerator
{
private:
	int userId;
	int lotId;
	IDGenerator();
//<<<<<<< Updated upstream
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
		file << userId << ' ' << lotId<< '\n';
		file.close();
	}
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
		while (!(file.eof())) {
			if (file.peek() == EOF) {
				this->userId = 0;
				this->lotId = 99;
			}
			else {
				file >> this->userId;
				file >> this->lotId;
			}
		}
	}
	file.close();
}
