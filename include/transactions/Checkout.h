#pragma once
#include "Transaction.h"
#include "LibraryItem.h"
#include "LibraryPatron.h"
#include <memory>

class Checkout : public Transaction
{
private:
    std::shared_ptr<LibraryItem> item_;
    std::shared_ptr<LibraryPatron> patron_;
    std::chrono::system_clock::time_point dueDate_;

public:
    Checkout(std::shared_ptr<LibraryItem> item, std::shared_ptr<LibraryPatron> patron);
    std::shared_ptr<LibraryItem> getItem() const;
    std::shared_ptr<LibraryPatron> getPatron() const;
    std::chrono::system_clock::time_point getDueDate() const;

    std::string getTransactionType() const override;
    std::string getDetails() const override;

    std::string getFormattedDueDate() const;
};