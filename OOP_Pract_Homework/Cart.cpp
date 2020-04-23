#include "Cart.h"

Cart::Cart()
{
	_total = 0;
	_size = 0;
	_cap = 1;
	_products = new Product*[_cap];
}

Cart::Cart(const Cart& other)
{
	_total = other.getTotal();
	_size = other.getSize();
	_cap = other.getCap();
	_products = new Product*[_cap];
	for (unsigned int i = 0; i < _size; ++i)
	{
		_products[i] = other._products[i];
	}
}

Cart& Cart::operator=(const Cart& other)
{
	if (this != &other)
	{
		_total = other.getTotal();
		_size = other.getSize();
		_cap = other.getCap();
		clear();
		_products = new Product*[_cap];
		for (unsigned int i = 0; i < _size; ++i)
		{
			_products[i] = other._products[i];
		}
	}
	return *this;
}

Cart::~Cart()
{
	clear();
}

Cart& Cart::operator+(Product* product)
{
	addProduct(product);
	return *this;
}

void Cart::addProduct(Product* product)
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

void Cart::printProducts() const
{
	for (unsigned int i = 0; i < _size; ++i)
	{
		_products[i]->printInfo();
	}
}

void Cart::clear()
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

bool Cart::isEmpty() const
{
	return (_size == 0);
}

unsigned int Cart::getSize() const
{
	return _size;
}

unsigned int Cart::getCap() const
{
	return _cap;
}

double Cart::getTotal() const
{
	return _total;
}

void Cart::resize()
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

void Cart::incrementSize()
{
	++_size;
}

void Cart::updateTotal()
{
	_total = 0;
	for (unsigned int i = 0; i < _size; ++i)
	{
		_total += _products[i]->getPrice();
	}
}
