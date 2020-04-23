#ifndef DEVICE_H
#define DEVICE_H
#include "Product.h"

class Device :public Product
{
public:
	//Device();
	Device(const char* brand, const char* model, const char* manufactorer, const char* description, const double price, const double weight);
	Device(const Device& other);
	Device& operator=(const Device& other);
	~Device();

	char* getBrand() const;
	char* getModel() const;
	char* getManufacturer() const;
	virtual Category getCategory() const override;

	void printInfo() const;

protected:
	void setBrand(const char* brand);
	void setModel(const char* model);
	void setManufacturer(const char* manufactorer);

private:
	char* _brand;
	char* _model;
	char* _manufacturer;

};

#endif // DEVICE_H