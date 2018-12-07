#pragma once
#include "DAO.h"

class AuthService {
private:
	User currentUser;
	AuthService() {};
public:
	static AuthService getAuthInstance();
	~AuthService() {};
	void setCurrentUser(User user);
	User getCurrentUser();
	void auth();
};
