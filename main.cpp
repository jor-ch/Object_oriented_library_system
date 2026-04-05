#include "Book.h"
#include "Student.h"
#include "Checkout.h"
#include "Magazine.h"
#include "DVD.h"
#include "Faculty.h"
#include "Guest.h"
#include "Return.h"
#include "Reservation.h"

#include "Library.h"
#include "LibraryExceptions.h"

#include <iostream>
#include <memory>
#include <vector>

int main()
{
    Library library;

    // Create and add items
    auto book1 = std::make_unique<Book>("B001", "The best book 1", "Best Author 1", "ISBN BOOK", "Fiction");
    auto book2 = std::make_unique<Book>("B002", "The best book 2", "Best Author 2", "ISBN BOOK2", "Nonfiction");
    auto magazine1 = std::make_unique<Magazine>("M001", "The best magazine 1", 5, "Best Publisher 1");
    auto dvd1 = std::make_unique<DVD>("D001", "The best DVD 1", "Best Director 1", 120);
    library.addItem(std::move(book1));
    library.addItem(std::move(book2));
    library.addItem(std::move(magazine1));
    library.addItem(std::move(dvd1));

    // Create and add patrons
    auto student1 = std::make_unique<Student>("S001", "Alice", "alice@email.com", "STU123", "Computer Science");
    auto faculty1 = std::make_unique<Faculty>("F001", "Dr. Smith", "dr.smith@email.com", "FAC456", "Computer Science");
    auto guest1 = std::make_unique<Guest>("G001", "Bob", "bob@email.com");
    library.addPatron(std::move(student1));
    library.addPatron(std::move(faculty1));
    library.addPatron(std::move(guest1));

    // Print initial inventory
    std::cout << "Initial Library Inventory:" << std::endl;
    library.printInventory();
    std::cout << std::endl;

    // Search for a book by title
    std::cout << "\nSearching for books with 'best' in the title:" << std::endl;
    auto foundBooks = library.searchItems([](const LibraryItem &item)
                                          { return item.getTitle().find("best") != std::string::npos; });
    for (auto *item : foundBooks)
    {
        std::cout << item->getDetails() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "moving on to checking out" << std::endl;
    // Test valid checkout
    try
    {
        auto checkout1 = library.checkOutItem("B001", "S001");
        library.getLatestTransaction();
        // std::cout << checkout1->getDetails() << std::endl;
    }
    catch (const LibraryException &e)
    {
        std::cerr << "Library error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "moving on to invalid checking out" << std::endl;
    // Test invalid checkout (already checked out)
    try
    {
        auto checkout2 = library.checkOutItem("B001", "F001");
        // std::cout << checkout2->getDetails() << std::endl;
        library.getLatestTransaction();
    }
    catch (const LibraryException &e)
    {
        std::cerr << "Expected error (double checkout): " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "moving on to checking out using inactive patron" << std::endl;
    // Test checkout with inactive patron
    // first, find a faulty patron
    auto foundPatron = library.searchPatrons([](const LibraryPatron &patron)
                                             { return patron.getPatronType().find("Faculty") != std::string::npos; });
    foundPatron[0]->setActive(0);
    std::cout << "patron found with ID:" << foundPatron[0]->getDetails() << std::endl;
    std::cout << std::endl;
    try
    {
        auto checkout3 = library.checkOutItem("B002", "F001");
        // std::cout << checkout3->getDetails() << std::endl;
        library.getLatestTransaction();
    }
    catch (const LibraryException &e)
    {
        std::cerr << "Expected error (inactive patron): " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test return
    std::cout << "moving on to returning" << std::endl;
    try
    {
        auto return1 = library.returnItem("B001");
        // std::cout << return1->getDetails() << std::endl;
        library.getLatestTransaction();
    }
    catch (const LibraryException &e)
    {
        std::cerr << "Library error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test return of item not checked out
    std::cout << "moving on to returning of item not checked out" << std::endl;
    try
    {
        auto return2 = library.returnItem("M001");
        // std::cout << return2->getDetails() << std::endl;
        library.getLatestTransaction();
    }
    catch (const LibraryException &e)
    {
        std::cerr << "Expected error (return not checked out): " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Print final inventory
    std::cout << "Final Library Inventory:" << std::endl;
    library.printInventory();

    return 0;
}