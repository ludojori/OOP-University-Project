#include "Store.h"

Store::Store()
{
	_size = 0;
	_cap = 1;
	_products = new Product*[_cap];
}

Store::Store(const Store& other)
{
	_size = other.getSize();
	_cap = other.getCap();
	_products = new Product*[_cap];
	for (unsigned int i = 0; i < _size; ++i)
	{
		_products[i] = other._products[i];
	}
}

Store& Store::operator=(const Store& other)
{
	if (this != &other)
	{
		_size = other.getSize();
		_cap = other.getCap();
		clear();
		_products = new Product * [_cap];
		for (unsigned int i = 0; i < _size; ++i)
		{
			_products[i] = other._products[i];
		}
	}
	return *this;
}

Store::~Store()
{
	clear();
}

void Store::addProduct(Product* product)
{
	if (product == nullptr)
	{
		std::cout << "Error: Failed to add product to cart - product was nullptr.\n";
		return;
	}
	if (_size == _cap)
	{
		resize();
	}
	if (product->getCategory() == Product::Category::UNDEFINED)
	{
		_products[_size - 1] = product;
	}
	if (product->getCategory() == Product::Category::DEVICE)
	{
		_products[_size - 1] = dynamic_cast<Device*>(product);
	}
	if (product->getCategory() == Product::Category::ACCESSORY)
	{
		_products[_size - 1] = dynamic_cast<Accessory*>(product);
	}
	if (product->getCategory() == Product::Category::BOOK)
	{
		_products[_size - 1] = dynamic_cast<Book*>(product);
	}
	incrementSize();
}

void Store::clear()
{
	if (_products != nullptr)
	{
		for (unsigned int i = 0; i < _size; ++i)
		{
			if (_products[i] != nullptr)
			{
				delete _products[i];
			}
		}
		delete[] _products;
	}
}

void Store::printByCategory(const Product::Category category) const
{
	if (isEmpty())
	{
		std::cout << "ERROR: Unable to print - Store empty.\n";
		return;
	}
	for (unsigned int i = 0; i < _size; ++i)
	{
		if (_products[i]->getCategory() == category)
		{
			_products[i]->printInfo();
		}
	}
}

bool Store::isEmpty() const
{
	return (_size == 0);
}

unsigned int Store::getSize() const
{
	return _size;
}

unsigned int Store::getCap() const
{
	return _cap;
}

void Store::resize()
{
	_cap *= 2;
	Product** temp = new Product*[_cap];
	for (unsigned int i = 0; i < _size; ++i)
	{
		temp[i] = _products[i];
	}
	clear();
	_products = temp;
}

void Store::incrementSize()
{
	++_size;
}
