#include <iostream>
#include "Book.h"
#include "Student.h"
#include <memory>
#include "Checkout.h"

int main()
{
    // for testing of book and library item functionality
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

    // there should be an error here because the book is already checked out
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

    // for testing of student and library patron functionality
    Student student("ID456", "Best name", "best.name@example.com", "SID123456", "Computer Science");
    std::cout << student.getDetails() << std::endl;
    student.deactivate();
    std::cout << "Is the student active after deactivation? " << (student.isActive() ? "Yes" : "No") << std::endl;
    student.activate();
    std::cout << "Is the student active after reactivation? " << (student.isActive() ? "Yes" : "No") << std::endl;

    // for testing of checkout transaction functionality
    std::shared_ptr<LibraryItem> book1Ptr = std::make_shared<Book>("123", "The Best Title", "The Best Author", "123-4567-89", "Fiction");
    std::shared_ptr<LibraryItem> book2Ptr = std::make_shared<Book>("1232", "The Best Title2", "The Best Author2", "123-4567-892", "Fiction");
    std::shared_ptr<LibraryPatron> student1Ptr = std::make_shared<Student>("ID456", "Best name", "best.name@example.com", "SID123456", "Computer Science");
    try
    {
        {
            Checkout checkout(book1Ptr, student1Ptr);
            std::cout << checkout.getDetails() << std::endl;
            Checkout checkout2(book2Ptr, student1Ptr); // this should work because book2 is a different item and is available for checkout
            std::cout << checkout2.getDetails() << std::endl;
            Checkout checkout3(book1Ptr, student1Ptr); // this should throw an error because book1 is already checked out
            std::cout << checkout3.getDetails() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}