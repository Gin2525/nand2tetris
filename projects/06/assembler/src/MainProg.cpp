#include "Code.hpp"
#include "Parser.hpp"
#include <bits/stdc++.h>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

void writeHackLine(std::string filename, std::string line) {
    ofstream wHackStream;
    wHackStream.open(filename, ios::app);
    if(!wHackStream) {
        std::cerr << "failure to open the file." << std::endl;
        std::exit(1);
    }
    cout << line << endl;
    wHackStream.close();
}

string binary(string strN) {
    int n = stoi(strN);
    string bin = "";
    for(int i = 0; n > 0; i++) {
        bin = bin + to_string(n % 2);
        strN = n / 2;
    }
    return bin;
}

string takeHackLine(Parser *parser, Code *code) {
    int t = parser->commandType();
    if(t == 0) {
        return binary(parser->symbol());
    } else if(t == 1) {
        string dest = code->dest(parser->dest());
        string comp = code->comp(parser->comp());
        string jump = code->jump(parser->jump());
        return dest + comp + jump;
    } else if(t == 2) {
        //シンボルフリーなバイナリーにてL_COMMANDは出現しない
        return "-1";
    }else{
        return "-1";
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "missing count of given argments" << endl;
        return 1;
    }
    std::string filename = argv[1];
    Code *code = new Code();
    Parser *parser = new Parser(filename);
    int dotIdx = filename.find('.');
    std::string writtenFilename = filename.substr(0,dotIdx)+"hack";

    while(parser->hasMoreCommands()) {
        parser->advance();
        string hackLine = takeHackLine(parser, code);
        writeHackLine(writtenFilename,hackLine);
    }
    return 0;
}