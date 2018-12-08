#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <string>

using std::string;

class Encryptor {
public:
	Encryptor() {};
	~Encryptor() {};
	static void codePassword(string* password) {
		int i = 0;
		char alf[] = "abcedfghijklmnopqrstuvwxyz0123456789#!@$%^&*-+=";
		for (unsigned int n = 0; n < password->length() + 1; n++)
		{
			for (i = 0; i < 47; i++)
			{
				if ((*password)[n] == alf[i])
				{
					if (i >= 47)
						(*password)[n] = alf[i - 47];
					else
						(*password)[n] = alf[i + 4];
					break;
				}
			}
		}
	}
	
	static void decodePassword(string* password) {
		int i = 0;
		char alf[] = "abcedfghijklmnopqrstuvwxyz0123456789#!@$%^&*-+=";
		for (unsigned int n = 0; n < password->length() + 1; n++)
		{
			for (i = 0; i < 47; i++)
			{
				if ((*password)[n] == alf[i])
				{
					if (i >= 47)
						(*password)[n] = alf[i - 47];
					else
						(*password)[n] = alf[i - 4];
					break;
				}
			}
		}
	}
	static bool isEqual(string password, string encryptedPassword) {
		string buf = string(password);
		Encryptor::codePassword(&buf);
		return encryptedPassword._Equal(buf);

	}
};