#include <iostream>
#include "Book.h"
#include "Student.h"
#include <memory>
#include "Checkout.h"
#include <vector>
#include "Magazine.h"

int main()
{
    // to test interaction functionality between checkout, book and patron
    // std::shared_ptr<LibraryItem> book1 = std::make_shared<Book>("1234", "The Best Book 1",
    //                                                             "The best author", "1234567890", "Fiction");
    // std::shared_ptr<LibraryPatron> student1 = std::make_shared<Student>("9876", "Best person",
    //                                                                     "best.person@example.com",
    //                                                                     "ID123456", "Computer Science");

    // std::vector<std::shared_ptr<Transaction>> transactions;

    // try
    // {
    //     // this should work and print the details of the checkout transaction
    //     std::shared_ptr<Checkout> checkout1 = std::make_shared<Checkout>(book1, student1);
    //     transactions.push_back(checkout1);
    //     std::cout << "Checkout successful:\n"
    //               << checkout1->getDetails() << std::endl;

    //     std::cout << "item details in checkout procedure are:\n"
    //               << checkout1->getItem()->getDetails() << std::endl;
    //     std::cout << "patron details in checkout procedure are:\n"
    //               << checkout1->getPatron()->getDetails() << std::endl;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }
    // try
    // {
    //     // this should NOT work because the book is already checked out, and should throw an exception
    //     std::shared_ptr<Checkout> checkout2 = std::make_shared<Checkout>(book1, student1);
    //     transactions.push_back(checkout2);
    //     std::cout << "Checkout successful:\n"
    //               << checkout2->getDetails() << std::endl;

    //     std::cout << "item details in checkout procedure are:\n"
    //               << checkout2->getItem()->getDetails() << std::endl;
    //     std::cout << "patron details in checkout procedure are:\n"
    //               << checkout2->getPatron()->getDetails() << std::endl;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

    // // to simulate returning the book, with a fine for overdue days
    // book1->returnItem();
    // int overdueDays = 5; // example overdue days
    // double fine = book1->calculateFine(overdueDays);
    // std::cout << "Book returned. Overdue days: " << overdueDays << ", Fine: $" << fine << std::endl;

    // test functionality of magazine class
    Magazine mag1("5678", "The Best Magazine", 42, "Best Publisher");
    std::cout << "Magazine details:\n"
              << mag1.getDetails() << std::endl;
    std::cout << "test fine for 3 days is $" << mag1.calculateFine(3) << std::endl; // example overdue days for magazine

    return 0;
}