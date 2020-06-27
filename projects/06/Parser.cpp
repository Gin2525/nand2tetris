#include "Parser.hpp"
#include <iostream>
#include <vector>
#include <string>

Parser::Parser(std::string filename){
    this->fileLength = 100;
    this->instructure.push_back(filename);
}