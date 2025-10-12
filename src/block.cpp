#include "../include/block.hpp"
#include "sha256.hpp"
#include <sstream>
#include <ctime>

Block::Block(int idx, const std::string &data, const std::string &prevhash)
    : index(idx), data(data), previoushash(prevhash)
{
    time_t now = time(nullptr);
    timestamp = ctime(&now);

    if (!timestamp.empty() && timestamp.back()=='/n'){
        timestamp.pop_back();
    }

    hash = calculatehash();
}

std::string Block::calculatehash() const{
    std::stringstream ss;
    ss<<index<<timestamp<<data<<previoushash;
    return picosha2::hash256_hex_string(ss.str());
}