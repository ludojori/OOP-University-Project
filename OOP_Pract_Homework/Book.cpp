#include "Book.h"
#include <iostream>
#include <cstring>

Book::Book()
{
	setTitle("Default_Title");
	setAuthor("Default_Author");
	setGenre("Default_Genre");
}

Book::Book(const char* title, const char* author, const char* genre)
{
	setTitle(title);
	setAuthor(author);
	setGenre(genre);
}

Book::Book(const Book& other)
{
	setTitle(other.getTitle());
	setAuthor(other.getAuthor());
	setGenre(other.getGenre());
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		setTitle(other.getTitle());
		setAuthor(other.getAuthor());
		setGenre(other.getGenre());
	}
	return *this;
}

Book::~Book()
{
	if (_title != nullptr)
	{
		delete[] _title;
	}
	if (_author != nullptr)
	{
		delete[] _author;
	}
	if (_genre != nullptr)
	{
		delete[] _genre;
	}
}

char* Book::getTitle() const
{
	return _title;
}

char* Book::getAuthor() const
{
	return _author;
}

char* Book::getGenre() const
{
	return _genre;
}

void Book::printInfo() const
{
	std::cout
		<< "--> Book Info\n"
		<< "Title: " << _title << "\n"
		<< "Author: " << _author << "\n"
		<< "Genre: " << _genre << "\n";
}

void Book::setTitle(const char* title)
{
	if (_title != nullptr)
	{
		delete[] _title;
	}
	_title = new char[strlen(title) + 1];
	strcpy_s(_title, strlen(title) + 1, title);
}

void Book::setAuthor(const char* author)
{
	if (_author != nullptr)
	{
		delete[] _author;
	}
	_author = new char[strlen(author) + 1];
	strcpy_s(_author, strlen(author) + 1, author);
}

void Book::setGenre(const char* genre)
{
	if (_genre != nullptr)
	{
		delete[] _genre;
	}
	_genre = new char[strlen(genre) + 1];
	strcpy_s(_genre, strlen(genre) + 1, genre);
}
