#include "Student.h"

Student::Student(const std::string &id,
                 const std::string &name,
                 const std::string &contact,
                 const std::string &studentId,
                 const std::string &major) : LibraryPatron(id, name, contact), studentId_(studentId), major_(major)
{
    maxBorrowItems_ = 5; // Students can borrow up to 5 items
}

std::string Student::getStudentId() const
{
    return studentId_;
}

std::string Student::getMajor() const
{
    return major_;
}

std::string Student::getPatronType() const
{
    return "Student";
}

int Student::getLoanExtensionDays() const
{
    return 7; // Students can extend loans by 7 days
}