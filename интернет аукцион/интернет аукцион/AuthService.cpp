#include "User.h"

class AuthService {
private:
	User currentUser;
	AuthService() {};
	~AuthService() {};
public:
	static AuthService getInstance() {
		static AuthService instance;
		return instance;
	}

	void setCurrentUser(User user) {
		currentUser = user;
	}

	User getCurrentUser() {
		return currentUser;
	}
};