#include "DVD.h"

DVD::DVD(const std::string &id, const std::string &title, const std::string &director, int durationMinutes)
    : LibraryItem(id, title), director_(director), durationMinutes_(durationMinutes)
{
    dailyFine_ = 1.0; // DVDs have a higher fine rate than books
    maxLoanDays_ = 5; // DVDs can be loaned for a shorter period
}

std::string DVD::getDirector() const
{
    return director_;
}

int DVD::getDurationMinutes() const
{
    return durationMinutes_;
}

std::string DVD::getItemType() const
{
    return "DVD";
}

double DVD::calculateFine(int overdueDays) const
{
    if (overdueDays <= 0)
    {
        return 0.0;
    }
    return dailyFine_ * overdueDays;
}

std::string DVD::getDetails() const
{
    return "ID: " + id_ + "\nTitle: " + title_ + "\nDirector: " + director_ +
           "\nDuration: " + std::to_string(durationMinutes_) + " minutes" +
           "\nAvailable: " + (available_ ? "Yes" : "No") +
           "\nDaily Fine: $" + std::to_string(dailyFine_) + "\nMax Loan Days: " + std::to_string(maxLoanDays_);
}