#include "SymbolTable.hpp"
#include "Parser.hpp"
#include <map>
#include <string>

SymbolTable::SymbolTable() {
    this->symbolTable["SP"] = this->SP_ADDRESS;
    this->symbolTable["LCL"] = this->LCL_ADDRESS;
    this->symbolTable["ARG"] = this->ARG_ADDRESS;
    this->symbolTable["THIS"] = this->THIS_ADDERSS;
    this->symbolTable["THAT"] = this->THAT_ADDRESS;

    for(int r = 0; r <= this->R_MAX_NUMBER; r++) 
        this->symbolTable["R" + std::to_string(r)] = r;

    this->symbolTable["SCREEN"] = this->SCREEN_ADDRESS;
    this->symbolTable["KBD"] = this->KBD_ADDRESS;
}

void SymbolTable::addEntry(std::string symbol, int address) {
    this->symbolTable[symbol] = address;
}

bool SymbolTable::contains(std::string symbol) {
    auto ite = this->symbolTable.find(symbol);
    if(ite != this->symbolTable.end())
        return true;
    else
        return false;
}

int SymbolTable::getAddress(std::string symbol) {
    return this->symbolTable[symbol];
}
