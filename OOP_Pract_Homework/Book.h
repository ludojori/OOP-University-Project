#ifndef BOOK_H
#define BOOK_H
#include "Product.h"

class Book :public Product
{
public:
	Book();
	Book(const char* title, const char* author, const char* genre);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	char* getTitle() const;
	char* getAuthor() const;
	char* getGenre() const;

	void printInfo() const;

protected:
	void setTitle(const char* title);
	void setAuthor(const char* author);
	void setGenre(const char* genre);

private:
	char* _title;
	char* _author;
	char* _genre;
};

#endif // BOOK_H