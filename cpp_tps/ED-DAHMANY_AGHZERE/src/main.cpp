#include "tp1.h"


// int main()
// {
// 	/*int *n1, n2, tmp, &n3 = tmp;
// 	read();
// 	read(n1);
// 	Integer::read(n2);
// 	read(n3);*/

// 	int numberOfBooks;
// 	Book book1, book2, tableOfBooks[numberOfBooks];
// 	Book &book3 = book1, &book4 = book2;
// 	// book1 = newBook();
// 	// book2 = newBook();
// 	fillBooksTable(tableOfBooks, 2);
// 	// displayBook(book1);
// 	// displayTableOfBooks(tableOfBooks);
// 	// exchangeNumberOfPages(book3, book4);
// 	// displayBook(book3);//book1 will be also modified
// 	// displayBook(book4);//book2 will be also modified

// 	book3 = longerBook(tableOfBooks,2);
// 	book4 = shorterBook(tableOfBooks,2);
// 	// displayBook(book2);
// 	// displayBook(book1);

// 	return 0;
// }


int main()
{

	//Blague1 Beginning

	// Book tableOfBooks[4];
	// fillBooksTable(tableOfBooks, 4);
	// displayTableOfBooks(tableOfBooks);
	// exchangeNumberOfPages(longerBook(tableOfBooks, 4), shorterBook(tableOfBooks, 4));
	// cout << "\n\n\n" << endl;
	// displayTableOfBooks(tableOfBooks);

	//Blague1 End


	//Blague1 Beginning

	// Book tableOfBooks[4];
	// fillBooksTable(tableOfBooks, 4);
	// displayTableOfBooks(tableOfBooks);
	// Book &book1 = longerBook(tableOfBooks, 4), &book2 = shorterBook(tableOfBooks, 4); 
	// exchangeNumberOfPages(book1, book2);
	// cout << "\n\n\n" << endl;
	// displayTableOfBooks(tableOfBooks);

	//Blague1 End

	Book book;
	book1 = newBook();
	book2 = newBook();
	exchangeNumberOfPages(book1, book2);

	return 0;
}
