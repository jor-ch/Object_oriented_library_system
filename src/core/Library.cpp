#include "Library.h"
#include <iostream>
#include <algorithm>

LibraryItem *Library::findItemById(const std::string &id) const
{
    for (auto &item : items_)
    {
        if (item->getId() == id)
        {
            return item.get();
        }
    }
    throw ItemNotFoundException(id);
}

LibraryPatron *Library::findPatronById(const std::string &id) const
{
    for (auto &patron : patrons_)
    {
        if (patron->getId() == id)
        {
            return patron.get();
        }
    }
    throw PatronNotFoundException(id);
}

void Library::addItem(std::unique_ptr<LibraryItem> item)
{
    items_.push_back(std::move(item));
}

void Library::addPatron(std::unique_ptr<LibraryPatron> patron)
{
    patrons_.push_back(std::move(patron));
}

/*std::unique_ptr<Checkout>*/ int Library::checkOutItem(const std::string &itemId, const std::string &patronId)
{
    LibraryItem *item = findItemById(itemId);
    LibraryPatron *patron = findPatronById(patronId);

    if (!item->isAvailable())
    {
        throw CheckoutException("Item is not available for checkout.");
    }
    if (!patron->isActive())
    {
        throw CheckoutException("Patron is not active.");
    }
    // std::cout << "checking out..." << std::endl;
    // item->checkOut();
    // std::cout << "checking out successful" << std::endl;
    auto checkout = std::make_unique<Checkout>(item, patron);
    transactions_.push_back(std::move(checkout));
    // return std::unique_ptr<Checkout>(static_cast<Checkout *>(transactions_.back().get()));
    return 1;
}

/*std::unique_ptr<Return>*/ int Library::returnItem(const std::string &itemId)
{
    LibraryItem *item = findItemById(itemId);
    if (!item)
    {
        std::cout << "item via findItemById returned nothing!" << std::endl;
    }
    std::cout << "finding last patron who checked out this item!" << std::endl;
    // find last patron who checked out this item
    LibraryPatron *patron = nullptr;
    std::cout << "current number of transactions is " << transactions_.size() << std::endl;
    for (auto it = transactions_.rbegin(); it != transactions_.rend(); it++)
    {
        std::cout << "transaction type is " << (*it).get()->getTransactionType() << std::endl;
        if ((*it)->getTransactionType() == "Checkout")
        {
            Checkout *checkout = dynamic_cast<Checkout *>(it->get());
            if (checkout && checkout->getItem()->getId() == itemId)
            {
                patron = checkout->getPatron();
                break;
            }
        }
    }
    if (!patron)
    {
        throw CheckoutException("Cannot find patron for return.");
    }
    std::cout << "returning item" << std::endl;
    item->returnItem();

    auto returnTransaction = std::make_unique<Return>(patron, item);
    transactions_.push_back(std::move(returnTransaction));
    // return std::unique_ptr<Return>(static_cast<Return *>(transactions_.back().get()));
    return 1;
}

void Library::getLatestTransaction()
{
    int numTransactions = transactions_.size();
    if (!numTransactions)
    {
        std::cout << "No transactions recorded so far!" << std::endl;
        return;
    }
    std::cout << "Latest transaction details:" << std::endl;
    std::cout << transactions_[numTransactions - 1].get()->getDetails() << std::endl;
    std::cout << std::endl;
}

std::vector<LibraryItem *> Library::searchItems(const std::function<bool(const LibraryItem &)> &criteria)
{
    std::vector<LibraryItem *> results;
    for (auto &item : items_)
    {
        if (criteria(*item))
        {
            results.push_back(item.get());
        }
    }
    return results;
}

std::vector<LibraryPatron *> Library::searchPatrons(const std::function<bool(const LibraryPatron &)> &criteria)
{
    std::vector<LibraryPatron *> results;
    for (auto &patron : patrons_)
    {
        if (criteria(*patron))
        {
            results.push_back(patron.get());
        }
    }
    return results;
}

void Library::printInventory() const
{
    std::cout << "Library Inventory:" << std::endl;
    for (const auto &item : items_)
    {
        std::cout << item->getDetails() << std::endl;
        std::cout << "  Status: " << (item->isAvailable() ? "Available" : "Checked Out") << std::endl;
    }
}