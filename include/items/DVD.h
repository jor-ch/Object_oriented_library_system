#pragma once
#include <string>
#include "LibraryItem.h"

class DVD : public LibraryItem
{
private:
    std::string director_;
    int durationMinutes_; // in minutes
public:
    DVD(const std::string &id, const std::string &title, const std::string &director, int durationMinutes);
    std::string getDirector() const;
    int getDurationMinutes() const;

    std::string getItemType() const override;
    double calculateFine(int overdueDays) const override;
    std::string getDetails() const override;
};