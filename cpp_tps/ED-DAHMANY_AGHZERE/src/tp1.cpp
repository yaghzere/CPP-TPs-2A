#include "tp1.h"

int read()
{
	int numberOfPages,i = 0;
	while(!i){
		cout << "Number of pages between 3 and 1999 :" << endl;
		cin >> numberOfPages;
		if(numberOfPages > 2 || numberOfPages < 2000){
			i = 1;
		}
	}	
	return numberOfPages;
}

void read(int *  numberOfPages)
{
	while(*numberOfPages <= 2 || *numberOfPages >= 2000){
		cout << "Number of pages between 3 and 1999 :" << endl;
		cin >> * numberOfPages;
	}
	return;
}

void Integer::read(int numberOfPages)
{
	while(numberOfPages <= 2 || numberOfPages >= 2000){
		cout << "Number of pages between 3 and 1999 :" << endl;
		cin >> numberOfPages;
	}
	return;
}

void read(int & numberOfPages)
{
	while(numberOfPages <= 2 || numberOfPages >= 2000){
		cout << "Number of pages between 3 and 1999 :" << endl;
		cin >> numberOfPages;
	}
	return;
}

Book newBook(){
	Book book;
	int i = 0;

	cout << "Title : ";
	cin.getline(book.title, 50);
	while(!i){
		cout << "Number of pages between 3 and 1999 :" << endl;
		cin >> book.numberOfPages;
		if(book.numberOfPages > 2 || book.numberOfPages < 2000){
			i = 1;
		}
		cin.ignore();
	}
	return book;
}


void fillBooksTable(Book table[], int numberOfBooks){
	int counter = 0;
	while(counter < numberOfBooks){
		cout << "Title : ";
		cin >> table[counter].title;
		int i = 0;
		while(!i){
			cout << "Number of pages between 3 and 1999 :" << endl;
			cin >> table[counter].numberOfPages;
			if(table[counter].numberOfPages > 2 || table[counter].numberOfPages < 2000){
				i = 1;
			}
		}
		counter++;
	}
	cin.ignore();
	return;
}


void displayBook(Book book){
	cout << "Title : " << book.title << "\nPages : " << book.numberOfPages << endl;
	return;
}

void displayTableOfBooks(Book table[]){
	int index = 0;
	while(table[index].numberOfPages){
		displayBook(table[index]);
		index++;
	}
}

void exchangeNumberOfPages(Book & book1, Book & book2){
	int tmp;
	tmp = book1.numberOfPages;
	book1.numberOfPages = book2.numberOfPages;
	book2.numberOfPages = tmp;
	return;
}

Book & longerBook(Book tableOfBooks[], int numberOfBooks){
	int i, maxPages = 0, maxPagesIndex = -1;
	for (i = 0; i < numberOfBooks; i++){
		if (maxPages < tableOfBooks[i].numberOfPages){
			maxPagesIndex = i;
			maxPages = tableOfBooks[i].numberOfPages;
		}
	}
	Book & bookToReturn = tableOfBooks[maxPagesIndex];
	return tableOfBooks[maxPagesIndex];

}


Book & shorterBook(Book tableOfBooks[], int numberOfBooks){
	int i, minPages = 2000, minPagesIndex = -1;
	for (i = 0; i < numberOfBooks; i++){
		if (minPages > tableOfBooks[i].numberOfPages){
			minPagesIndex = i;
			minPages = tableOfBooks[i].numberOfPages;
		}
	}
	Book & bookToReturn = tableOfBooks[minPagesIndex];
	return bookToReturn;

}