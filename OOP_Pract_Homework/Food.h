#ifndef FOOD_H
#define FOOD_H

/*
To Inherit Class Product
*/
class Food
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
	void setCalories(const double calories);
	void setFats(const double fats);
	void setProteins(const double proteins);
	void setCarbohydrates(const double carbohydrates);

private:
	char* _name;
	// type - to be enum
	double _calories;
	double _fats;
	double _proteins;
	double _carbohydrates;
};

#endif // FOOD_H