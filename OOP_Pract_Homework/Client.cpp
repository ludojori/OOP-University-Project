#include "Client.h"
#include <iostream>
#include <cstring>

Client::Client(const char* name, const char* password, const double balance) :_balance(balance)
{
	setName(name);
	setPassword(password);
	encryptPassword();

}

Client::Client(const Client& other) :_balance(other._balance)
{
	setName(other.getName());
	setPassword(other._password);

}

Client& Client::operator=(const Client& other)
{
	if (this != &other)
	{
		setName(other.getName());
		setPassword(other._password);
		_balance = other._balance;
	}
	return *this;
}

Client::~Client()
{
	if (_name != nullptr)
	{
		delete[] _name;
		_name = nullptr;
	}
	if (_password != nullptr)
	{
		delete[] _password;
		_password = nullptr;
	}
}

char* Client::getName() const
{
	return _name;
}

Client& Client::changePassword(const char* verification, const char* newPassword)
{
	decryptPassword();
	if (strcmp(_password, verification) != 0)
	{
		std::cout << "ERROR: Incorrect Password!\n";
	}
	else
	{
		setPassword(newPassword);
		std::cout << "Notice: Password successfully changed.\n";
	}
	encryptPassword();
	return *this;
}

void Client::printClientInfo() const
{
	std::cout
		<< "--> Client Info\n"
		<< "Name: " << _name << "\n"
		<< "Balance: " << _balance << "\n";
}

void Client::printCart() const
{
	_cart.print();
}

Client& Client::addToCart(Product* product)
{
	_cart.add(product);
	return *this;
}

Client& Client::payProducts()
{
	if (_balance < _cart.getTotal())
	{
		std::cout << "Error: Unable to pay products - total sum exceeding balance.\n";
		return *this;
	}
	_balance -= _cart.getTotal();
	std::cout << "Successfully purchased all products for: " << _cart.getTotal() << "\n";
	_cart.clear();
	return *this;
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
