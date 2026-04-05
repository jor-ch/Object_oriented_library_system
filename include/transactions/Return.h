#pragma once
#include "Transaction.h"
#include "LibraryPatron.h"
#include "LibraryItem.h"
#include <memory>

class Return : public Transaction
{
private:
    LibraryPatron* patron_;
    LibraryItem* item_;

public:
    Return(LibraryPatron* patron, LibraryItem* item);
    LibraryPatron* getPatron() const;
    LibraryItem* getItem() const;

    std::string getTransactionType() const override;
    std::string getDetails() const override;
};