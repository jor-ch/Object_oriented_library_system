#include "Faculty.h"

Faculty::Faculty(const std::string &id, const std::string &name, const std::string &email, const std::string &facultyId, const std::string &department)
    : LibraryPatron(id, name, email), department_(department), facultyId_(facultyId)
{
    maxBorrowItems_ = 10; // Faculty can borrow up to 10 items
}

std::string Faculty::getDepartment() const
{
    return department_;
}

std::string Faculty::getPatronType() const
{
    return "Faculty";
}

std::string Faculty::getFacultyId() const
{
    return facultyId_;
}

std::string Faculty::getDetails() const
{
    return "ID: " + id_ + "\nName: " + name_ + "\nContact Info: " + contactInfo_ +
           "\nDepartment: " + department_ + "\nActive: " + (active_ ? "Yes" : "No") +
           "\nMax Borrow Items: " + std::to_string(maxBorrowItems_);
}

int Faculty::getLoanExtensionDays() const
{
    return 14; // Faculty get a 14-day extension on loans
}
