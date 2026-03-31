#include <iostream>
#include "Book.h"
#include "Student.h"

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
    std::cout << "Student Name: " << student.getName() << std::endl;
    std::cout << "Student ID: " << student.getStudentId() << std::endl;
    std::cout << "Student Major: " << student.getMajor() << std::endl;
    std::cout << "Student Contact Info: " << student.getContactInfo() << std::endl;
    std::cout << "ID: " << student.getId() << std::endl;
    std::cout << "Is the student active? " << (student.isActive() ? "Yes" : "No") << std::endl;

    return 0;
}