#include "../include/block.hpp"
#include "sha256.hpp"
#include <sstream>
#include <ctime>

Block::Block(int idx, const std::vector<Transaction>& data, const std::string& prevhash)
    : index(idx), data(data), previoushash(prevhash)
{
    time_t now = time(nullptr);
    timestamp = ctime(&now);

    if (!timestamp.empty() && timestamp.back()=='/n'){
        timestamp.pop_back();
    }
    merkleroot=calculateMerkleRoot(data);
    hash = calculatehash();
}
std::string calculateMerkleRoot(const std::vector<Transaction>& data){
    std::vector<std::string> hashes_pair;
    
    for (auto i:data){
        hashes_pair.push_back(picosha2::hash256_hex_string((i.toString())));
    }
    while(hashes_pair.size()>1){
        std::vector<std::string> newLevel;
        for (size_t i=0;i<hashes_pair.size();i+=2){
            std::string left = hashes_pair[i];
            std::string right = (i+1<hashes_pair.size()?hashes_pair[i+1]:left);
            std::stringstream counter;
            counter<<left<<right;
            newLevel.push_back(picosha2::hash256_hex_string(counter.str()));
        }

        hashes_pair=newLevel;
    }
    return hashes_pair.empty()?"":hashes_pair[0];
}
std::string Block::calculatehash() const{
    std::stringstream ss;
    ss<<index<<timestamp<<previoushash;
    for (auto i:data){
        ss<<i.toString();
    }
    return picosha2::hash256_hex_string(ss.str());
}