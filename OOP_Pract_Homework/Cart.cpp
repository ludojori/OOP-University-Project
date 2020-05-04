#include "Cart.h"

Product* productCategorizer(Product* product)
{
	if (product->getCategory() == Product::Category::DEVICE)
	{
		Device* device = new Device;
		device = dynamic_cast<Device*>(product);
		return device;
	}
	return product;
}

Cart::Cart() :_total(0.0f)
{
}

Cart::~Cart()
{
}

Cart& Cart::operator+(Product* product)
{
	add(product);
	return *this;
}

Cart& Cart::add(Product* product)
{
	_products.add(product);
	_total += product->getPrice();
	return *this;
}

void Cart::print() const
{
	for (unsigned int i = 0; i < _products.size(); ++i)
	{
		_products[i]->printInfo();
	}
}

void Cart::clear()
{
	_products.clear();
	_total = 0.0f;
}

double Cart::getTotal() const
{
	return _total;
}

bool Cart::isEmpty() const
{
	return _products.isEmpty();
}
