#include "Checkout.h"
#include <stdexcept>
#include <iomanip>
#include <chrono>

Checkout::Checkout(LibraryItem *item, LibraryPatron *patron) : item_(item), patron_(patron)
{
    if (!item_ || !patron_)
    {
        throw std::runtime_error("Item and Patron cannot be null.");
    }
    if (!item_->isAvailable())
    {
        throw std::runtime_error("Item is not available for checkout.");
    }
    if (!patron_->isActive())
    {
        throw std::runtime_error("Patron is not active and cannot check out items.");
    }

    // Perform Checkout
    item_->checkOut();

    // calculate due date based on current time and item's max loan days
    dueDate_ = std::chrono::system_clock::now() + std::chrono::hours(24 * item_->getMaxLoanDays());
}

LibraryItem *Checkout::getItem() const
{
    return item_;
}

LibraryPatron *Checkout::getPatron() const
{
    return patron_;
}

std::chrono::system_clock::time_point Checkout::getDueDate() const
{
    return dueDate_;
}

std::string Checkout::getTransactionType() const
{
    return "Checkout";
}

std::string Checkout::getDetails() const
{
    return "Transaction ID: " + transactionId_ +
           "\n" + "Transaction Type: " + getTransactionType() +
           "\n" + "Timestamp: " + getFormattedTimestamp() +
           "\n" + "Item: " + item_->getTitle() + " (ID: " + item_->getId() + ")\n" +
           "Patron: " + patron_->getName() + " (ID: " + patron_->getId() + ")\n" +
           "Due Date: " + getFormattedDueDate();
}

std::string Checkout::getFormattedDueDate() const
{
    auto timeDue = std::chrono::system_clock::to_time_t(dueDate_);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&timeDue), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}