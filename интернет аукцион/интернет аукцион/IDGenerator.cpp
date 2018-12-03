#include "IDGenerator.h"

IDGenerator* IDGenerator::getInstance() {
	if (instance == nullptr) {
		instance = new IDGenerator();
		init();
		return instance;
	}
}

IDGenerator::IDGenerator()
{
}

IDGenerator::~IDGenerator()
{
	ofstream file("ID.txt", ios::in | ios::binary | ios::trunc);
	if (file.is_open()) {
		file << instance->userId << '\n' << instance->lotId << '\n';
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
		file >> instance->userId;
		file >> instance->lotId;
	}
	file.close();
}