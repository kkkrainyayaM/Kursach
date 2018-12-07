#pragma once
#include <fstream>
using namespace std;

class IDGenerator
{
private:
	int userId;
	int lotId;
	IDGenerator();
	void init();
	static IDGenerator* instance;
public:
	~IDGenerator();
	int getUserId();
	int getLotId();
	static IDGenerator* getInstance();
};
