#include <iostream>
#include "Book.h"
#include "Student.h"
#include <memory>
#include "Checkout.h"
#include <vector>
#include "Magazine.h"
#include "DVD.h"
#include "Faculty.h"
#include "Guest.h"
#include "Return.h"

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
    // Magazine mag1("5678", "The Best Magazine", 42, "Best Publisher");
    // std::cout << "Magazine details:\n"
    //           << mag1.getDetails() << std::endl;
    // std::cout << "test fine for 3 days is $" << mag1.calculateFine(3) << std::endl; // example overdue days for magazine

    // // test functionality of DVD class
    // DVD dvd1("8888", "The Best DVD", "Best Director", 120);
    // std::cout << "DVD details:\n"
    //           << dvd1.getDetails() << std::endl;
    // std::cout << "test fine for 8 days is $" << dvd1.calculateFine(8) << std::endl; // example overdue days for DVD

    // // test functionality of faculty patron class
    // Faculty faculty1("5555", "Best Faculty", "best.faculty@example.com", "FAC123456", "Computer Science");
    // std::cout << "Faculty details:\n"
    //           << faculty1.getDetails() << std::endl;

    // // test functionality of guest patron class
    // Guest guest1("9999", "Best Guest", "best.guest@example.com");
    // std::cout << "Guest details:\n"
    //           << guest1.getDetails() << std::endl;

    // test functionality of checkout and return transactions with different item and patron types
    std::shared_ptr<LibraryItem> dvd2 = std::make_shared<DVD>("7777", "Another Great DVD", "Another Great Director", 90);
    std::shared_ptr<LibraryPatron> faculty2 = std::make_shared<Faculty>("6666", "Another Great Faculty", "another.faculty@example.com", "FAC654321", "Mathematics");
    std::vector<std::shared_ptr<Transaction>> transactions;
    try
    {
        std::shared_ptr<Checkout> checkout2 = std::make_shared<Checkout>(dvd2, faculty2);
        transactions.push_back(checkout2);
        std::cout << "Checkout successful:\n"
                  << checkout2->getDetails() << std::endl;

        std::cout << "item details in checkout procedure are:\n"
                  << checkout2->getItem()->getDetails() << std::endl;
        std::cout << "patron details in checkout procedure are:\n"
                  << checkout2->getPatron()->getDetails() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    // simulate returning the DVD with a fine for overdue days
    std::shared_ptr<Return> return2 = std::make_shared<Return>(faculty2, dvd2);
    transactions.push_back(return2);
    int overdueDays = 10; // example overdue days for DVD
    double fine = dvd2->calculateFine(overdueDays);
    std::cout << "Return successful:" << std::endl;
    std::cout << return2->getDetails() << std::endl;
    std::cout << "DVD returned. Overdue days: " << overdueDays << ", Fine: $" << fine << std::endl;

    return 0;
}