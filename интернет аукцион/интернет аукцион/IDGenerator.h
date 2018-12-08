#pragma once
#include <fstream>
using namespace std;

class IDGenerator
{
private:
	int userId;
	int lotId;
	int stavkaId;
	IDGenerator();
	void init();
	static IDGenerator* instance;
public:
	~IDGenerator();
	int getUserId();
	int getLotId();
	int getStavkaId();
	static IDGenerator* getInstance();
};
