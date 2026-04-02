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

// override virtual functions
std::string Book::getItemType() const
{
    return "Book";
}

double Book::calculateFine(int overdueDays) const
{
    if (overdueDays <= 0)
    {
        return 0.0;
    }
    return overdueDays * dailyFine_;
}

std::string Book::getDetails() const
{
    return "Library item: " + getItemType() + " Details:\nID: " + id_ +
           "\nTitle: " + title_ + "\nAuthor: " + author_ + "\nISBN: " + ISBN_ +
           "\nGenre: " + genre_ + "\nAvailable: " + (available_ ? "Yes" : "No") +
           "\nMax Loan Days: " + std::to_string(maxLoanDays_) + "\nDaily Fine: $" + std::to_string(dailyFine_);
}