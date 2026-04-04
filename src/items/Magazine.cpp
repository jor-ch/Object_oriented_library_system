#include "Magazine.h"

Magazine::Magazine(const std::string &id, const std::string &title, int issueNumber,
                   const std::string &publisher)
    : LibraryItem(id, title), issueNumber_(issueNumber), publisher_(publisher)
{
    dailyFine_ = 0.25; // Magazines have a lower fine rate than books
    maxLoanDays_ = 7;  // Magazines can be loaned for a shorter period
}

int Magazine::getIssueNumber() const
{
    return issueNumber_;
}

std::string Magazine::getPublisher() const
{
    return publisher_;
}

std::string Magazine::getItemType() const
{
    return "Magazine";
}

double Magazine::calculateFine(int overdueDays) const
{
    if (overdueDays <= 0)
    {
        return 0.0;
    }
    return dailyFine_ * overdueDays;
}

std::string Magazine::getDetails() const
{
    return "ID: " + id_ + "\nTitle: " + title_ + "\nIssue Number: " + std::to_string(issueNumber_) +
           "\nPublisher: " + publisher_ + "\nAvailable: " + (available_ ? "Yes" : "No") +
           "\nDaily Fine: $" + std::to_string(dailyFine_) + "\nMax Loan Days: " + std::to_string(maxLoanDays_);
}