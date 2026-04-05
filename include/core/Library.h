#pragma once
#include "LibraryExceptions.h"
#include "LibraryItem.h"
#include "LibraryPatron.h"
#include "Transaction.h"
#include "Checkout.h"
#include "Return.h"
#include <vector>
#include <memory>
#include <string>
#include <functional>

class Library
{
private:
    std::vector<std::unique_ptr<LibraryItem>> items_;
    std::vector<std::unique_ptr<LibraryPatron>> patrons_;
    std::vector<std::unique_ptr<Transaction>> transactions_;

    LibraryItem *findItemById(const std::string &id) const;
    LibraryPatron *findPatronById(const std::string &id) const;

public:
    void addItem(std::unique_ptr<LibraryItem> item);
    void addPatron(std::unique_ptr<LibraryPatron> patron);
    /*std::unique_ptr<Checkout>*/ int checkOutItem(const std::string &itemId, const std::string &patronId);
    /*std::unique_ptr<Return>*/ int returnItem(const std::string &itemId);
    void getLatestTransaction();
    std::vector<LibraryItem *> searchItems(const std::function<bool(const LibraryItem &)> &criteria);
    std::vector<LibraryPatron *> searchPatrons(const std::function<bool(const LibraryPatron &)> &criteria);
    void printInventory() const;
};