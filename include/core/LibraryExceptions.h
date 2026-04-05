#pragma once
#include <stdexcept>
#include <string>

class LibraryException : public std::runtime_error
{
public:
    explicit LibraryException(const std::string &message);
};

class ItemNotFoundException : public LibraryException
{
public:
    explicit ItemNotFoundException(const std::string &id);
};

class PatronNotFoundException : public LibraryException
{
public:
    explicit PatronNotFoundException(const std::string &id);
};

class CheckoutException : public LibraryException
{
public:
    explicit CheckoutException(const std::string &message);
};
