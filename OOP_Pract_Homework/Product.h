#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <cstring>

class Product
{
public:
	Product();
	Product(const char* description, const double price, const double weight);
	Product(const Product& other);
	Product& operator=(const Product& other);
	virtual ~Product();

	virtual char* getDescription() const;
	virtual double getPrice() const;
	virtual double getWeight() const;

	virtual void printInfo() const;

	enum class Category
	{
		UNDEFINED, DEVICE, BOOK, FOOD, ACCESSORY
	};
	
	/* Make pure virtual if class Product must be abstract. */
	virtual Category getCategory() const;

protected:
	void setDescription(const char* description);

private:
	char* _description = nullptr;
	double _price;
	double _weight;

};

#endif // PRODUCT_H