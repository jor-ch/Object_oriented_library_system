#include "Return.h"

Return::Return(LibraryPatron *patron, LibraryItem *item)
    : patron_(patron), item_(item)
{
    item->returnItem();
}
LibraryPatron *Return::getPatron() const
{
    return patron_;
}

LibraryItem *Return::getItem() const
{
    return item_;
}
std::string Return::getTransactionType() const
{
    return "Return";
}
std::string Return::getDetails() const
{
    return "Return: " + item_->getTitle() + " by " + patron_->getName();
}
