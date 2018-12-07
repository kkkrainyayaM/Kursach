#pragma once
#include "DAO.h"

class AuthService {
private:
	User currentUser;
	static AuthService* instance;
	AuthService() {};
public:
	static AuthService* getAuthInstance();
	~AuthService() {};
	void setCurrentUser(User& user);
	User& getCurrentUser();
	void auth();
};
