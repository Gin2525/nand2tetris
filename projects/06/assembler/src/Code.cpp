#include "Code.hpp"
#include <map>
#include <string>

Code::Code(){
    this->destMap["null"]="000";
    this->destMap["M"] = "001";
    this->destMap["D"] = "010";
    this->destMap["MD"] = "011";
    this->destMap["A"] = "100";
    this->destMap["AM"] = "101";
    this->destMap["AD"] = "110";
    this->destMap["AMD"] = "111";

    this->compMap["0"] = "0101010";
    this->compMap["1"] = "0111111";
    this->compMap["-1"] = "0111010";
    this->compMap["D"] = "0001100";
    this->compMap["A"] = "0110000";
    this->compMap["!D"] = "0001101";
    this->compMap["!A"] = "0110001";
    this->compMap["-D"] = "0001111";
    this->compMap["-A"] = "0110011";
    this->compMap["D+1"] = "0111111";
    this->compMap["A+1"] = "0110111";
    this->compMap["D-1"] = "0001110";
    this->compMap["A-1"] = "0110010";
    this->compMap["D+A"] = "0000010";
    this->compMap["D-A"] = "0010011";
    this->compMap["A-D"] = "0000111";
    this->compMap["D&A"] = "0000000";
    this->compMap["D|A"] = "0010101";
    this->compMap["M"] = "1110000";
    this->compMap["!M"] = "1110001";
    this->compMap["-M"] = "1110011";
    this->compMap["M+1"] = "1110111";
    this->compMap["M-1"] = "1110010";
    this->compMap["D+M"] = "1000010";
    this->compMap["D-M"] = "1010011";
    this->compMap["M-D"] = "1000111";
    this->compMap["D&M"] = "1000000";
    this->compMap["D|M"] = "1010101";

    this->jumpMap["null"] = "000";
    this->jumpMap["JGT"] = "001";
    this->jumpMap["JEQ"] = "010";
    this->jumpMap["JGE"] = "011";
    this->jumpMap["JLT"] = "100";
    this->jumpMap["JNE"] = "101";
    this->jumpMap["JLE"] = "110";
    this->jumpMap["JMP"] = "111";
}

std::string Code::dest(std::string mnemonic) {
    auto itr = this->destMap.find(mnemonic);
    if(itr != this->destMap.end()){
        return this->destMap[mnemonic];
    }else{
        return "-1";
    }
}

std::string Code::comp(std::string mnemonic) {
    auto itr = this->compMap.find(mnemonic);
    if(itr != this->compMap.end()) {
        return this->compMap[mnemonic];
    } else {
        return "-1";
    }
}

std::string Code::jump(std::string mnemonic) {
    auto itr = this->jumpMap.find(mnemonic);
    if(itr != this->jumpMap.end()) {
        return this->jumpMap[mnemonic];
    } else {
        return "-1";
    }
}
