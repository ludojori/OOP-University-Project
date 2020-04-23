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
	double getBalance() const;

	void changePassword(const char* verification, const char* newPassword);
	void printClientInfo() const;
	void printCartProducts() const;
	void addToCart(Product* product);
	void payProducts();

private:
	const Cart& getCart() const;

	void setName(const char* name);
	void setPassword(const char* password);
	void setBalance(const double balance);
	void setCart(const Cart& cart);
	void encryptPassword();
	void decryptPassword();

	char* _name;
	char* _password;
	double _balance;
	Cart _cart;

};

#endif // CLIENT_H