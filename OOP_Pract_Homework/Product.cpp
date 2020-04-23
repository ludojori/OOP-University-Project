#include "Product.h"
#include <iostream>
#include <cstring>



Product::Product()
{
	setDescription("Default_Description");
	setPrice(0.0f);
	setWeight(0.0f);
}

Product::Product(const char* description, const double price, const double weight)
{
	setDescription(description);
	setPrice(price);
	setWeight(weight);
}

Product::Product(const Product& other)
{
	setDescription(other.getDescription());
	setPrice(other.getPrice());
	setWeight(other.getWeight());
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		setDescription(other.getDescription());
		setPrice(other.getPrice());
		setWeight(other.getWeight());
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
		<< "--> Product Info\n"
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

void Product::setPrice(const double price)
{
	_price = price;
}

void Product::setWeight(const double weight)
{
	_weight = weight;
}
