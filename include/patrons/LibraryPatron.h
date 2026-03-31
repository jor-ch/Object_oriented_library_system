#pragma once
#include <string>

class LibraryPatron
{
protected:
    std::string id_;
    std::string name_;
    std::string contactInfo_;
    bool active_;
    int maxBorrowItems_;

public:
    LibraryPatron(const std::string &id,
                  const std::string &name,
                  const std::string &contact) : id_(id), name_(name), contactInfo_(contact), active_(true), maxBorrowItems_(0){};
    virtual ~LibraryPatron() = default;
};