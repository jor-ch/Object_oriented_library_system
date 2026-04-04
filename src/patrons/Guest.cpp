#include "Guest.h"

Guest::Guest(const std::string &id, const std::string &name, const std::string &email)
    : LibraryPatron(id, name, email)
{
    maxBorrowItems_ = 2; // Guests can borrow up to 2 items
}

std::string Guest::getPatronType() const
{
    return "Guest";
}

int Guest::getLoanExtensionDays() const
{
    return 0; // Guests do not get loan extensions
}

std::string Guest::getDetails() const
{
    return "ID: " + id_ + "\nName: " + name_ + "\nContact: " + contactInfo_ +
           "\nActive: " + (active_ ? "Yes" : "No") +
           "\nMax Borrow Items: " + std::to_string(maxBorrowItems_);
}
