#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <cstring>

/*
To Be Abstract Base Class
*/
class Product
{
public:
	Product();
	Product(const char* description, const double price, const double weight);
	Product(const Product& other);
	Product& operator=(const Product& other);
	//Product* operator=(Product* other);
	virtual ~Product();

	char* getDescription() const;
	double getPrice() const;
	double getWeight() const;

	void printInfo() const;

	enum class Category
	{
		UNDEFINED, DEVICE, BOOK, ACCESSORY
	};

	virtual Category getCategory() const;

protected:
	void setDescription(const char* description);
	void setPrice(const double price);
	void setWeight(const double weight);

private:
	char* _description;
	double _price;
	double _weight;

};

#endif // PRODUCT_H