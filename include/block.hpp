#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <string>
#include <ctime>
#include <vector>
#include "transaction.hpp"
class Block{
    public:
        int index;
        std::vector<Transaction> data;
        std::string timestamp;
        std::string previoushash;
        std::string hash;

        Block(int idx, const std::vector<Transaction>& data, const std::string &prevhash);

        std::string calculatehash() const;
};

#endif