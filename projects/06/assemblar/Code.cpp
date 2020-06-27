#include "Code.hpp"
#include <string>

std::string Code::dest(std::string mnemonic) {
    if(mnemonic == "null"){
        return "000";
    }else if(mnemonic == "M"){
        return "001";
    }else if(mnemonic == "D"){
        return "010";
    }else if(mnemonic == "MD"){
        return "011";
    }else if(mnemonic == "A"){
        return "100";
    }else if(mnemonic == "AM"){
        return "101";
    }else if(mnemonic == "AD"){
        return "110";
    }else if(mnemonic == "AMD"){
        return "111";
    }else{
        return "-1";
    }
}

std::string Code::jump(std::string mnemonic){
    if(mnemonic == "null") {
        return "000";
    } else if(mnemonic == "JGT") {
        return "001";
    } else if(mnemonic == "JEQ") {
        return "010";
    } else if(mnemonic == "JGE") {
        return "011";
    } else if(mnemonic == "JLT") {
        return "100";
    } else if(mnemonic == "JNE") {
        return "101";
    } else if(mnemonic == "JLE") {
        return "110";
    } else if(mnemonic == "JMP") {
        return "111";
    } else {
        return "-1";
    }
}
