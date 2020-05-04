#ifndef CART_H
#define CART_H
#include "Device.h"
#include "Book.h"
#include "Accessory.h"
#include "Food.h"
#include "TemplateArray.h"

class Cart
{
public:
	Cart();
	Cart(const Cart& other) = delete;
	Cart& operator=(const Cart& other) = delete;
	~Cart();

	Cart& operator+(Product* product);

	Cart& add(Product* product);
	void print() const;
	void clear();

	double getTotal() const;
	bool isEmpty() const;

private:
	TemplateArray<Product*> _products;
	double _total;

};

#endif // CART_H