#include "Food.h"
#include <iostream>
#include <cstring>

Food::Food()
{
	setName("Default_Name");
	setCalories(0.0f);
	setFats(0.0f);
	setProteins(0.0f);
	setCarbohydrates(0.0f);
}

Food::Food(const Food& other)
{
	setName(other.getName());
	setCalories(other.getCalories());
	setFats(other.getFats());
	setProteins(other.getProteins());
	setCarbohydrates(other.getCarbohydrates());
}

Food& Food::operator=(const Food& other)
{
	if (this != &other)
	{
		setName(other.getName());
		setCalories(other.getCalories());
		setFats(other.getFats());
		setProteins(other.getProteins());
		setCarbohydrates(other.getCarbohydrates());
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
	std::cout
		<< "--> Food Info:\n"
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

void Food::setCalories(const double calories)
{
	_calories = calories;
}

void Food::setFats(const double fats)
{
	_fats = fats;
}

void Food::setProteins(const double proteins)
{
	_proteins = proteins;
}

void Food::setCarbohydrates(const double carbohydrates)
{
	_carbohydrates = carbohydrates;
}
