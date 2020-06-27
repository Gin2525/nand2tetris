#include "Parser.hpp"
#include <fstream>
#include <iostream>
#include <string>

Parser::Parser(std::string filename){
    std::ifstream ifs(filename);
    if(!ifs){
        std::cerr << "failure to open the file." << std::endl;
        std::exit(1);
    }

    std::string buf;
    int fileLength = 0;
    while(std::getline(ifs,buf)){
        this->instructure.push_back(buf);
        fileLength++;
    }
    this->fileLength = fileLength;
    this->currentComannd = this->instructure.at(0);
}