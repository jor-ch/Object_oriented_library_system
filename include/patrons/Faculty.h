#include "LibraryPatron.h"

class Faculty : public LibraryPatron
{
private:
    std::string department_;
    std::string facultyId_;

public:
    Faculty(const std::string &id, const std::string &name, const std::string &email,
            const std::string &facultyId, const std::string &department);
    std::string getDepartment() const;
    std::string getPatronType() const override;
    std::string getFacultyId() const;
    int getLoanExtensionDays() const override; // Faculty get a 14-day extension on loans
    std::string getDetails() const override;
};
