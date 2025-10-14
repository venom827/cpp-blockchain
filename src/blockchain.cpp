#include "../include/blockchain.hpp"
#include <vector>

Blockchain::Blockchain(){
    createGenesisBlock();
}

void Blockchain::createGenesisBlock(){
    Block genBlock(0,"genBlock","0");
    chain.push_back(genBlock);
}
bool Blockchain::isChainValid()const{
    for (int i=1;i<chain.size();i++){
        if (chain[i].hash != chain[i].calculatehash() || chain[i].previoushash!=chain[i-1].hash){
            return false;
        }
        
    }
    return true;
}
Block Blockchain::getLatestBlock()const{
    return chain.back();
}

void Blockchain::addNewBlock(Block &newBlock){
    Block lastBlock = getLatestBlock();
    newBlock.previoushash = lastBlock.hash;
    newBlock.hash = newBlock.calculatehash();
    chain.push_back(newBlock);

}