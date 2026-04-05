#include "LibraryExceptions.h"

LibraryException::LibraryException(const std::string &message) : std::runtime_error(message)
{
}

ItemNotFoundException::ItemNotFoundException(const std::string &id)
    : LibraryException("Item with ID '" + id + "' not found.")
{
}

PatronNotFoundException::PatronNotFoundException(const std::string &id)
    : LibraryException("Patron with ID '" + id + "' not found.")
{
}

CheckoutException::CheckoutException(const std::string &message)
    : LibraryException("Checkout Error: " + message)
{
}
