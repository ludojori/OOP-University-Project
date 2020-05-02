#ifndef STORE_H
#define STORE_H
#include "Device.h"
#include "Book.h"
#include "Accessory.h"
#include "Food.h"

class Store
{
public:
	Store();
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	void addProduct(Product* product);
	void clear();
	void printByCategory(const Product::Category category) const;

	bool isEmpty() const;

private:
	Product** _products;
	unsigned int _size;
	unsigned int _cap;

	unsigned int getSize() const;
	unsigned int getCap() const;

	void resize();
	void incrementSize();
};

#endif // STORE_H