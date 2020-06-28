#include "SymbolTable.hpp"
#include <string>
#include <map>

void SymbolTable::addEntry(std::string symbol, int address){
    this->symbolTable[symbol]=address;
}

int SymbolTable::getAddress(std::string symbol){
    return this->symbolTable[symbol];
}