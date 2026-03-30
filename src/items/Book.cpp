#include "Book.h"
#include <sstream>

Book::Book(const std::string &id,
           const std::string &title,
           const std::string &author,
           const std::string &ISBN,
           const std::string &genre)
    : LibraryItem(id, title), author_(author), ISBN_(ISBN), genre_(genre)
{
    dailyFine_ = 0.50; // Example fine for overdue books
    maxLoanDays_ = 14; // Example loan period for books
}

// Getters
std::string Book::getAuthor() const
{
    return author_;
}
std::string Book::getISBN() const
{
    return ISBN_;
}
std::string Book::getGenre() const
{
    return genre_;
}