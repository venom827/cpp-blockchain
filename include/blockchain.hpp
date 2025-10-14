#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP
#include <vector>
#include "block.hpp"
class Blockchain{
    private:
        std::vector<Block> chain;
        void createGenesisBlock();

    public:
        Blockchain();
        
        Block getLatestBlock() const;
        void addNewBlock(Block &newBlock);
        bool isChainValid() const;

};
#endif