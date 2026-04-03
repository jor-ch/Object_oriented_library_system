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

    // Getters
    std::string getId() const { return id_; }
    std::string getName() const { return name_; }
    std::string getContactInfo() const { return contactInfo_; }
    bool isActive() const { return active_; }
    int getMaxBorrowItems() const { return maxBorrowItems_; }

    // setters
    void setActive(bool active) { active_ = active; }
    void setContactInfo(const std::string &contact) { contactInfo_ = contact; }

    // virtual functions for derived classes to implement
    virtual std::string getPatronType() const = 0;
    virtual int getLoanExtensionDays() const = 0;
    virtual std::string getDetails() const = 0;

    // common functions
    void deactivate() { active_ = false; }
    void activate() { active_ = true; }
};