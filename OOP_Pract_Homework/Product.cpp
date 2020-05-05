#include "Product.h"
#include <iostream>
#include <cstring>

Product::Product() :_price{ 0.0f }, _weight{ 0.0f }
{
	setDescription("Default_Description");
}

Product::Product(const char* description, const double price, const double weight) : _price{ price }, _weight{ weight }
{
	setDescription(description);
}

Product::Product(const Product& other) : _price{ other._price }, _weight{ other._weight }
{
	setDescription(other.getDescription());
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		setDescription(other.getDescription());
		_price = other._price;
		_weight = other._weight;
	}
	return *this;
}

Product::~Product()
{
	if (_description != nullptr)
	{
		delete[] _description;
	}
}

char* Product::getDescription() const
{
	return _description;
}

double Product::getPrice() const
{
	return _price;
}

double Product::getWeight() const
{
	return _weight;
}

void Product::printInfo() const
{
	std::cout
		<< "Product Info\n"
		<< "---------------\n"
		<< "Description:\n\n"
		<< _description << "\n\n"
		<< "Price: " << _price << "\n"
		<< "Weight: " << _weight << "\n";
}

Product::Category Product::getCategory() const
{
	return Category::UNDEFINED;
}

void Product::setDescription(const char* description)
{
	if (_description != nullptr)
	{
		delete[] _description;
	}
	_description = new char[strlen(description) + 1];
	strcpy_s(_description, strlen(description) + 1, description);
}
