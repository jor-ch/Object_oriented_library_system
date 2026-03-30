#pragma once
#include "LibraryItem.h"
#include <string>

class Book : public LibraryItem
{
private:
    std::string author_;
    std::string ISBN_; // International Standard Book Number
    std::string genre_;

public:
    Book(const std::string &id,
         const std::string &title,
         const std::string &author,
         const std::string &ISBN,
         const std::string &genre);

    // Getters
    std::string getAuthor() const;
    std::string getISBN() const;
    std::string getGenre() const;

    // override virtual functions
    std::string getItemType() const override;
    double calculateFine(int overdueDays) const override;
    std::string getDetails() const override;
};