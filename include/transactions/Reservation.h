#pragma once
#include "Transaction.h"
#include "LibraryPatron.h"
#include "LibraryItem.h"
#include <memory>

class Reservation : public Transaction
{
private:
    LibraryItem* item_;
    LibraryPatron* patron_;

public:
    Reservation(LibraryItem* item, LibraryPatron* patron);
    LibraryItem* getItem() const;
    LibraryPatron* getPatron() const;

    std::string getTransactionType() const override;
    std::string getDetails() const override;
};