#include "Reservation.h"

Reservation::Reservation(LibraryItem *item, LibraryPatron *patron)
    : item_(item), patron_(patron)
{
}

LibraryItem *Reservation::getItem() const
{
    return item_;
}

LibraryPatron *Reservation::getPatron() const
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