#include <iostream>
#include "Book.h"

int main()
{
    Book book("123", "The Best Title", "The Best Author", "123-4567-89", "Fiction");
    std::cout << "Book Title: " << book.getTitle() << std::endl;
    std::cout << "Author: " << book.getAuthor() << std::endl;
    std::cout << "ISBN: " << book.getISBN() << std::endl;
    std::cout << "Genre: " << book.getGenre() << std::endl;
    return 0;
}