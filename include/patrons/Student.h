#pragma once
#include "LibraryPatron.h"
#include <string>

class Student : public LibraryPatron
{
private:
    std::string studentId_;
    std::string major_;

public:
    Student(const std::string &id,
            const std::string &name,
            const std::string &contact,
            const std::string &studentId,
            const std::string &major);
    std::string getStudentId() const;
    std::string getMajor() const;

    // Implement virtual functions from LibraryPatron
    std::string getPatronType() const override;
    int getLoanExtensionDays() const override;
    std::string getDetails() const override;
};