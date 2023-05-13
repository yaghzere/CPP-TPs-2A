#ifndef _BOOK__H_
#define _BOOK__H_

#include <iostream>

using namespace std;

struct Book
{
	char title[50];
	int numberOfPages;
};

int read();
void read(int *);
namespace Integer {
	void read(int);
}
void read(int &);

Book newBook();
void fillBooksTable(Book *, int );
void displayBook(Book);
void displayTableOfBooks(Book[]);
void exchangeNumberOfPages(Book&, Book&);

Book & longerBook(Book *, int);
Book & shorterBook(Book *, int);
#endif
