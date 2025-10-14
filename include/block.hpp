#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <string>
#include <ctime>

class Block{
    public:
        int index;
        std::string data;
        std::string timestamp;
        std::string previoushash;
        std::string hash;

        Block(int idx, const std::string &data, const std::string &prevhash);

        std::string calculatehash() const;
};

#endif