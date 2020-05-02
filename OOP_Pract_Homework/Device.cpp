#include "Device.h"
#include <iostream>
#include <cstring>


Device::Device() :Product()
{
	setBrand("Default_Brand");
	setModel("Default_Model");
	setManufacturer("Default_Manufacturer");
}


Device::Device(const char* brand, const char* model, const char* manufactorer, const char* description, const double price, const double weight) :Product(description, price, weight)
{
	setBrand(brand);
	setModel(model);
	setManufacturer(manufactorer);
}

Device::Device(const Device& other) :Product(other)
{
	setBrand(other.getBrand());
	setModel(other.getModel());
	setManufacturer(other.getManufacturer());
}

Device& Device::operator=(const Device& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		setBrand(other.getBrand());
		setModel(other.getModel());
		setManufacturer(other.getManufacturer());
	}
	return *this;
}

Device::~Device()
{
	if (_brand != nullptr)
	{
		delete[] _brand;
	}
	if (_model != nullptr)
	{
		delete[] _model;
	}
	if (_manufacturer != nullptr)
	{
		delete[] _manufacturer;
	}
}

char* Device::getBrand() const
{
	return _brand;
}

char* Device::getModel() const
{
	return _model;
}

char* Device::getManufacturer() const
{
	return _manufacturer;
}

Product::Category Device::getCategory() const
{
	return Category::DEVICE;
}

void Device::printInfo() const
{
	Product::printInfo();
	std::cout
		<< "Type: Device\n"
		<< "Brand: " << _brand << "\n"
		<< "Model: " << _model << "\n"
		<< "Manufacturer: " << _manufacturer << "\n";
}

void Device::setBrand(const char* brand)
{
	if (_brand != nullptr)
	{
		delete[] _brand;
	}
	_brand = new char[strlen(brand) + 1];
	strcpy_s(_brand, strlen(brand) + 1, brand);
}

void Device::setModel(const char* model)
{
	if (_model != nullptr)
	{
		delete[] _model;
	}
	_model = new char[strlen(model) + 1];
	strcpy_s(_model, strlen(model) + 1, model);
}

void Device::setManufacturer(const char* manufactorer)
{
	if (_manufacturer != nullptr)
	{
		delete[] _manufacturer;
	}
	_manufacturer = new char[strlen(manufactorer) + 1];
	strcpy_s(_manufacturer, strlen(manufactorer) + 1, manufactorer);
}