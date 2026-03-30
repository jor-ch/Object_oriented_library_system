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

    // Getters
    std::string getId() const { return id_; }
    std::string getTitle() const { return title_; }
    bool isAvailable() const { return available_; }
    double getMaxLoanDays() const { return maxLoanDays_; }

    // Setters
    void setAvailable(bool available) { available_ = available; }

    // methods to check out and return items
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