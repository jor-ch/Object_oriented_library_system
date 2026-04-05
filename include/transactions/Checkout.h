#pragma once
#include "Transaction.h"
#include "LibraryItem.h"
#include "LibraryPatron.h"
#include <memory>

class Checkout : public Transaction
{
private:
    LibraryItem *item_;
    LibraryPatron *patron_;
    std::chrono::system_clock::time_point dueDate_;

public:
    Checkout(LibraryItem *item, LibraryPatron *patron);
    LibraryItem *getItem() const;
    LibraryPatron *getPatron() const;
    std::chrono::system_clock::time_point getDueDate() const;

    std::string getTransactionType() const override;
    std::string getDetails() const override;

    std::string getFormattedDueDate() const;
};