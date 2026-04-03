#pragma once
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>

class Transaction
{
protected:
    std::string transactionId_;
    std::chrono::system_clock::time_point timestamp_;

public:
    Transaction() : timestamp_(std::chrono::system_clock::now())
    {
        auto time = std::chrono::system_clock::to_time_t(timestamp_);
        std::stringstream ss;
        ss << "TXN" << time;
        transactionId_ = ss.str();
    }
    virtual ~Transaction() = default;
    std::string getTransactionId() const { return transactionId_; }
    std::chrono::system_clock::time_point getTimestamp() const { return timestamp_; }

    std::string getFormattedTimestamp() const
    {
        auto time = std::chrono::system_clock::to_time_t(timestamp_);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

    virtual std::string getTransactionType() const = 0;
    virtual std::string getDetails() const = 0;
};