#ifndef ACCESSORY_H
#define ACCESSORY_H
#include "Product.h"

class Accessory :public Product
{
public:
	Accessory();
	Accessory(const Accessory& other);
	Accessory& operator=(const Accessory& other);
	~Accessory();

	char* getName() const;

	void printInfo() const;

protected:
	void setName(const char* name);

private:
	char* _name;

};

#endif // ACCESSORY_H