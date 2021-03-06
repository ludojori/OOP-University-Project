#include "Accessory.h"
#include <iostream>
#include <cstring>

Accessory::Accessory() :Product()
{
	setName("Default_Name");
}

Accessory::Accessory(const Accessory& other) : Product(other)
{
	setName(other.getName());
}

Accessory& Accessory::operator=(const Accessory& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		setName(other.getName());
	}
	return *this;
}

Accessory::~Accessory()
{
	if (_name != nullptr)
	{
		delete[] _name;
	}
}

char* Accessory::getName() const
{
	return _name;
}

void Accessory::printInfo() const
{
	Product::printInfo();
	std::cout
		<< "Type: Accessory\n"
		<< "Name: " << _name << "\n";
}

void Accessory::setName(const char* name)
{
	if (_name != nullptr)
	{
		delete[] _name;
	}
	_name = new char[strlen(name) + 1];
	strcpy_s(_name, strlen(name) + 1, name);
}
