#include "transaction.hpp"
#include <ctime>
#include <sstream>
Transaction::Transaction(const std::string& sndr, const std::string& recvr, double amt, time_t timestmp):
    sender(sndr),receiver(recvr),amount(amt),timestamp(timestmp)
    {}

double Transaction::getAmount() const{
    return amount;
}

const std::string& Transaction::getReceiver()const{
    return receiver;
}

const std::string& Transaction::getSender()const{
    return sender;
}

time_t Transaction::getTimestamp()const{
    return timestamp;
}

std::string Transaction::toString(){
    std::stringstream counter;
    counter<<sender<<receiver<<amount<<timestamp;
    return counter.str();
}
