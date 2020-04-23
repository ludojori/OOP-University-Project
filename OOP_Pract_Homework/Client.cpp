#include "Client.h"
#include <iostream>
#include <cstring>

Client::Client(const char* name, const char* password, const double balance)
{
	setName(name);
	setPassword(password);
	encryptPassword();
	setBalance(balance);
	setCart(Cart());
}

Client::Client(const Client& other)
{
	setName(other.getName());
	setPassword(other._password);
	setBalance(other.getBalance());
	setCart(other.getCart());
}

Client& Client::operator=(const Client& other)
{
	if (this != &other)
	{
		setName(other.getName());
		setPassword(other._password);
		setBalance(other.getBalance());
		setCart(other.getCart());
	}
	return *this;
}

Client::~Client()
{
	if (_name != nullptr)
	{
		delete[] _name;
	}
	if (_password != nullptr)
	{
		delete[] _password;
	}
}

char* Client::getName() const
{
	return _name;
}

double Client::getBalance() const
{
	return _balance;
}

const Cart& Client::getCart() const
{
	return _cart;
}

void Client::changePassword(const char* verification, const char* newPassword)
{
	decryptPassword();
	if (strcmp(_password, verification) != 0)
	{
		std::cout << "ERROR: Incorrect Password!\n";
	}
	else
	{
		setPassword(newPassword);
	}
	encryptPassword();
}

void Client::printClientInfo() const
{
	std::cout
		<< "--> Client Info\n"
		<< "Name: " << _name << "\n"
		<< "Balance: " << _balance << "\n";
}

void Client::printCartProducts() const
{
	if (_cart.isEmpty())
	{
		std::cout << _name << "'s cart is empty.\n";
		return;
	}
	std::cout << _name << "'s products in cart:\n";
	_cart.printProducts();
}

void Client::addToCart(Product* product)
{
	_cart.addProduct(product);
}

void Client::payProducts()
{
	if (_cart.isEmpty())
	{
		std::cout << "ERROR: Payment cancelled - \"" << _name << "\"'s cart is empty.\n";
		return;
	}
	if (_balance < _cart.getTotal())
	{
		std::cout << "ERROR: Payment cancelled - Total price exceeds \"" << _name << "\"'s balance.\n";
		return;
	}
	_balance -= _cart.getTotal();
	_cart.clear();
}

void Client::setName(const char* name)
{
	if (_name != nullptr)
	{
		delete[] _name;
	}
	_name = new char[strlen(name) + 1];
	strcpy_s(_name, strlen(name) + 1, name);
}

void Client::setPassword(const char* password)
{
	if (_password != nullptr)
	{
		delete[] _password;
	}
	_password = new char[strlen(password) + 1];
	strcpy_s(_password, strlen(password) + 1, password);
}

void Client::setBalance(const double balance)
{
	_balance = balance;
}

void Client::setCart(const Cart& cart)
{
	_cart = cart;
}

void Client::encryptPassword()
{
	unsigned int passwordSize = strlen(_password);
	for (unsigned int i = 0; i < passwordSize; ++i)
	{
		_password[i] = (_password[i] + passwordSize) % 255;
	}
}

void Client::decryptPassword()
{
	unsigned int passwordSize = strlen(_password);
	for (unsigned int i = 0; i < passwordSize; ++i)
	{
		_password[i] = (_password[i] - passwordSize) % 255;
	}
}
