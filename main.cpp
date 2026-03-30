#include <iostream>
#include "Book.h"

int main()
{
    Book book("123", "The Best Title", "The Best Author", "123-4567-89", "Fiction");
    std::cout << book.getDetails() << std::endl;

    std::cout << "Checking out the book..." << std::endl;
    try
    {
        book.checkOut();
        std::cout << "Book checked out successfully." << std::endl
                  << "Is the book available? " << (book.isAvailable() ? "Yes" : "No") << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        book.checkOut();
        std::cout << "Book checked out successfully." << std::endl
                  << "Is the book available? " << (book.isAvailable() ? "Yes" : "No") << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Returning the book..." << std::endl;
    book.returnItem();
    std::cout << "Book returned successfully." << std::endl
              << "Is the book available? " << (book.isAvailable() ? "Yes" : "No") << std::endl;
    std::cout << "Calculating fine for 5 overdue days: $" << book.calculateFine(5) << std::endl;
    return 0;
}