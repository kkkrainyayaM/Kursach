#pragma once
#include <fstream>
using namespace std;

class IDGenerator
{
private:
	int userId;
	int lotId;
	IDGenerator();
	~IDGenerator();
	static void init();
	static IDGenerator* instance;
public:
	int getUserId();
	int getLotId();
	static IDGenerator* getInstance();
};
