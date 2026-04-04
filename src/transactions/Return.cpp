#include "Return.h"

Return::Return(std::shared_ptr<LibraryPatron> patron, std::shared_ptr<LibraryItem> item)
    : patron_(patron), item_(item)
{
    item->returnItem();
}
std::shared_ptr<LibraryPatron> Return::getPatron() const
{
    return patron_;
}

std::shared_ptr<LibraryItem> Return::getItem() const
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
