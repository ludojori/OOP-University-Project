#ifndef FOOD_H
#define FOOD_H
#include "Product.h"

class Food :public Product
{
public:
	Food();
	Food(const Food& other);
	Food& operator=(const Food& other);
	~Food();

	char* getName() const;
	double getCalories() const;
	double getFats() const;
	double getProteins() const;
	double getCarbohydrates() const;

	void printInfo() const;

protected:
	void setName(const char* name);

private:
	char* _name = nullptr;
	double _calories;
	double _fats;
	double _proteins;
	double _carbohydrates;
};

#endif // FOOD_H