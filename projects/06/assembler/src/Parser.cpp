#include "Parser.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

Parser::Parser(std::string filename) {
    std::ifstream ifs(filename);
    if(!ifs) {
        std::cerr << "failure to open the file." << std::endl;
        std::exit(1);
    }

    std::string buf;
    int fileLength = 0;
    while(std::getline(ifs, buf)) {
        // erase all space
        buf.erase(std::remove_if(buf.begin(), buf.end(), isspace), buf.end());

        // erase comment
        auto commentIdx = buf.find("//");
        if(commentIdx != std::string::npos)
            buf = buf.substr(0,commentIdx);

        // only comment line is invalid
        if(buf == "")
            continue;

        this->instructure.push_back(buf);
        fileLength++;
    }
    ifs.close();

    this->currentCommand = ' ';
    this->nextIte = this->instructure.begin();
    this->fileLength = fileLength;
}

bool Parser::hasMoreCommands() {
    if(this->nextIte == this->instructure.end())
        return false;
    else
        return true;
}

void Parser::advance() {
    if(this->hasMoreCommands()) {
        this->currentCommand = *this->nextIte;
        this->nextIte++;
    } else
        std::cout << "nothing next instructure." << std::endl;
}

// 0 : A_COMMAND
// 1 : C_COMMAND
// 2 : L_COMMAND
int Parser::commandType() {
    char prefix = this->currentCommand.at(0);
    if(prefix == '@')
        return 0;
    else if(prefix == '(')
        return 2;
    else
        return 1;
}

void Parser::reset() {
    this->currentCommand = ' ';
    this->nextIte = this->instructure.begin();
}

std::string Parser::symbol() {
    int commandType = this->commandType();
    if(commandType == 0)
        return this->currentCommand.substr(1);
    else if(commandType == 2) {
        return this->currentCommand.substr(1, this->currentCommand.size() - 2);
    } else
        return "error";
}

std::string Parser::dest() {
    if(this->commandType() != 1)
        return "error";
    for(int i = 0; i < this->currentCommand.size(); i++) {
        if(this->currentCommand.at(i) == '=')
            return this->currentCommand.substr(0, i);
    }
    return "null";
}

std::string Parser::comp() {
    if(this->commandType() != 1)
        return "error";
    int left = 0;
    int right = this->currentCommand.size();
    for(int i = 0; i < this->currentCommand.size(); i++) {
        if(this->currentCommand.at(i) == '=')
            left = i + 1;
        else if(this->currentCommand.at(i) == ';')
            right = i;
    }
    return this->currentCommand.substr(left, right - left);
}

std::string Parser::jump() {
    if(this->commandType() != 1)
        return "error";
    for(int i = 0; i < this->currentCommand.size(); i++) {
        if(this->currentCommand.at(i) == ';')
            return this->currentCommand.substr(i + 1);
    }
    return "null";
}
