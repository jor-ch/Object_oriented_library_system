#pragma once
#include "LibraryItem.h"
#include <string>

class Magazine : public LibraryItem
{
private:
    int issueNumber_;
    std::string publisher_;

public:
    Magazine(const std::string &id, const std::string &title, int issueNumber, const std::string &publisher);
    int getIssueNumber() const;
    std::string getPublisher() const;

    std::string getItemType() const override;
    double calculateFine(int overdueDays) const override;
    std::string getDetails() const override;
};