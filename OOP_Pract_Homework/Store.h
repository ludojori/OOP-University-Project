#ifndef STORE_H
#define STORE_H
#include "Client.h"

class Store
{
public:
	Store();
	Store(const Store& other) = delete;
	Store& operator=(const Store& other) = delete;

	Store& addProduct(Product* product);
	Store& clear();
	void print() const;
	void printByCategory(const Product::Category category) const;

	bool isEmpty() const;

private:
	TemplateArray<Product*> _products;
};

#endif // STORE_H