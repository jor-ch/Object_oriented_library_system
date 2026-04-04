#pragma once
#include "Transaction.h"
#include "LibraryPatron.h"
#include "LibraryItem.h"
#include <memory>

class Reservation : public Transaction
{
private:
    std::shared_ptr<LibraryItem> item_;
    std::shared_ptr<LibraryPatron> patron_;

public:
    Reservation(std::shared_ptr<LibraryItem> item, std::shared_ptr<LibraryPatron> patron);
    std::shared_ptr<LibraryItem> getItem() const;
    std::shared_ptr<LibraryPatron> getPatron() const;

    std::string getTransactionType() const override;
    std::string getDetails() const override;
};