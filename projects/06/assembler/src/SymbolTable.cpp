#include "SymbolTable.hpp"
#include <string>
#include <map>

void SymbolTable::addEntry(std::string symbol, int address){
    this->symbolTable[symbol]=address;
}

bool SymbolTable::contains(std::string symbol){
    auto ite = this->symbolTable.find(symbol);
    return ite != this->symbolTable.end();
}

int SymbolTable::getAddress(std::string symbol){
    return this->symbolTable[symbol];
}