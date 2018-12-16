#pragma once
#include "DAO.h"
#include "Time.h"

class AuthService {
private:
	User currentUser;
	Time currentTime;
	static AuthService* instance;
	AuthService() {};
public:
	static AuthService* getAuthInstance();
	~AuthService() {};
	void setCurrentTime(Time& time);
	void setCurrentUser(User& user);
	Time& getCurrentTime();
	User& getCurrentUser();
	void auth();
};
