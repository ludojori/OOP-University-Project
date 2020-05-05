#include "Store.h"

Store::Store()
{
}

Store& Store::addProduct(Product* product)
{
	_products.add(product);
	return *this;
}

Store& Store::clear()
{
	_products.clear();
	std::cout << "Warning: Store has been cleared!\n";
	return *this;
}

void Store::print() const
{
	for (unsigned int i = 0; i < _products.size(); ++i)
	{
		_products[i]->printInfo();
		std::cout << "\n";
	}
}

void Store::printByCategory(const Product::Category category) const
{
	for (unsigned int i = 0; i < _products.size(); ++i)
	{
		if (_products[i]->getCategory() == category)
		{
			_products[i]->printInfo();
			std::cout << "\n";
		}
	}
}

bool Store::isEmpty() const
{
	return _products.isEmpty();
}
