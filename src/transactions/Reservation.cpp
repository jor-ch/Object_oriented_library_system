#include "Reservation.h"

Reservation::Reservation(std::shared_ptr<LibraryItem> item,
                         std::shared_ptr<LibraryPatron> patron)
    : item_(item), patron_(patron)
{
}

std::shared_ptr<LibraryItem> Reservation::getItem() const
{
    return item_;
}

std::shared_ptr<LibraryPatron> Reservation::getPatron() const
{
    return patron_;
}

std::string Reservation::getTransactionType() const
{
    return "Reservation";
}

std::string Reservation::getDetails() const
{
    return "Transaction ID: " + transactionId_ +
           "\n" + "Transaction Type: " + getTransactionType() +
           "\n" + "Timestamp: " + getFormattedTimestamp() +
           "\n" + "Item: " + item_->getTitle() + " (ID: " + item_->getId() + ")\n" +
           "Patron: " + patron_->getName() + " (ID: " + patron_->getId() + ")";
}