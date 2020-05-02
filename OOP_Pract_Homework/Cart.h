#ifndef CART_H
#define CART_H
#include "Device.h"
#include "Book.h"
#include "Accessory.h"
#include "Food.h"

class Cart
{
public:
	Cart();
	Cart(const Cart& other);
	Cart& operator=(const Cart& other);
	~Cart();

	Cart& operator+(Product* product);

	Cart& addProduct(Product* product);
	void printProducts() const;
	void clear();

	double getTotal() const;
	bool isEmpty() const;

private:
	Product** _products = nullptr;
	unsigned int _size;
	unsigned int _cap;
	double _total;

	unsigned int getSize() const;
	unsigned int getCap() const;

	void resize();
	void incrementSize();
	void updateTotal();

};

#endif // CART_H