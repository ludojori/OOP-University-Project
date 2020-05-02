#include "Food.h"
#include <iostream>
#include <cstring>

Food::Food() :Product(), _calories(0.0f), _fats(0.0f), _proteins(0.0f), _carbohydrates(0.0f)
{
	setName("Default_Name");
}

Food::Food(const Food& other) : Product(other), _calories(other._calories), _fats(other._fats), _proteins(other._proteins), _carbohydrates(other._carbohydrates)
{
	setName(other.getName());
}

Food& Food::operator=(const Food& other)
{
	if (this != &other)
	{
		_calories = other._calories;
		_fats = other._fats;
		_proteins = other._proteins;
		_carbohydrates = other._carbohydrates;
		setName(other.getName());
	}
	return *this;
}

Food::~Food()
{
	if (_name != nullptr)
	{
		delete[] _name;
	}
}

char* Food::getName() const
{
	return _name;
}

double Food::getCalories() const
{
	return _calories;
}

double Food::getFats() const
{
	return _fats;
}

double Food::getProteins() const
{
	return _proteins;
}

double Food::getCarbohydrates() const
{
	return _carbohydrates;
}

void Food::printInfo() const
{
	Product::printInfo();
	std::cout
		<< "Type: Food\n"
		<< "Name: " << _name << "\n"
		<< "Calories: " << _calories << "%\n"
		<< "Fats: " << _fats << "%\n"
		<< "Proteins: " << _proteins << "%\n"
		<< "Carbohydrates: " << _carbohydrates << "%\n";
}

void Food::setName(const char* name)
{
	if (_name != nullptr)
	{
		delete[] _name;
	}
	_name = new char[strlen(name) + 1];
	strcpy_s(_name, strlen(name) + 1, name);
}
