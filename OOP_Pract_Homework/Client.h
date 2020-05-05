#ifndef CLIENT_H
#define CLIENT_H
#include "Cart.h"

class Client
{
public:
	Client() = delete;
	Client(const char* name, const char* password, const double balance);
	Client(const Client& other);
	Client& operator=(const Client& other);
	~Client();

	char* getName() const;

	Client& changePassword(const char* verification, const char* newPassword);
	void printClientInfo() const;
	void printCart() const;
	Client& addToCart(Product* product);
	Client& payProducts();

private:
	void setName(const char* name);
	void setPassword(const char* password);
	void encryptPassword();
	void decryptPassword();

	Cart _cart;
	char* _name = nullptr;
	char* _password = nullptr;
	double _balance;

};

#endif // CLIENT_H