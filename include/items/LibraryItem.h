#pragma once
#include <string>
#include <stdexcept>

class LibraryItem
{
protected:
    std::string id_;
    std::string title_;
    bool available_;
    double dailyFine_;
    int maxLoanDays_;

public:
    LibraryItem(const std::string &id, const std::string &title) : id_(id), title_(title), available_(true), dailyFine_(0.0), maxLoanDays_(0) {}

    virtual ~LibraryItem() = default;

    void checkOut()
    {
        if (!available_)
        {
            throw std::runtime_error("Item is not available for checkout.");
        }
        available_ = false;
    }

    void returnItem()
    {
        available_ = true;
    }
};