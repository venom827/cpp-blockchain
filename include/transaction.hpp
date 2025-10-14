#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP
#include <vector>
#include<string>
#include <ctime>
#include "block.hpp"
class Transaction{
    private:
        std::string sender;
        std::string receiver;
        double amount;
        time_t timestamp;
    public:
        Transaction::Transaction(const std::string& sender, const std::string& receiver, double amount, time_t timestamp=time(0));
        const std::string& getSender()const;
        const std::string& getReceiver()const;
        double getAmount() const;
        time_t getTimestamp()const;
        std::string toString();

};
#endif