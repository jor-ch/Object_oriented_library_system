#include "Student.h"

Student::Student(const std::string &id,
                 const std::string &name,
                 const std::string &contact,
                 const std::string &studentId,
                 const std::string &major) : LibraryPatron(id, name, contact), studentId_(studentId), major_(major)
{
    maxBorrowItems_ = 5; // Students can borrow up to 5 items
}