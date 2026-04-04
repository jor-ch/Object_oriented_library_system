#pragma once

#include "LibraryPatron.h"
#include <string>

class Guest : public LibraryPatron
{
public:
    Guest(const std::string &id, const std::string &name, const std::string &email);
    std::string getPatronType() const override;
    int getLoanExtensionDays() const override;
    std::string getDetails() const override;
};