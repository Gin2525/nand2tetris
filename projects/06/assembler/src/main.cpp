#include "Code.hpp"
#include "Parser.hpp"
#include <bits/stdc++.h>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

string binary(string strN) {
    if(strN == "0") {
        return "000000000000000";
    }
    int n = stoi(strN);
    string bin = "";
    for(int i = 0; n > 0; i++) {
        bin = to_string(n % 2) + bin;
        n = n / 2;
    }
    while(bin.size() < 15) {
        bin = "0" + bin;
    }
    return bin;
}

string takeHackLine(Parser *parser, Code *code) {
    int t = parser->commandType();
    if(t == 0) {
        return "0" + binary(parser->symbol());
    } else if(t == 1) {
        string dest = code->dest(parser->dest());
        string comp = code->comp(parser->comp());
        string jump = code->jump(parser->jump());
        return "111" + comp + dest + jump;
    } else if(t == 2) {
        //シンボルフリーなアセンブリにてL_COMMANDは出現しない
        return "-1";
    } else {
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
    int dotIdx = filename.rfind('.');
    std::string writtenFilename = filename.substr(0,dotIdx) + ".hack";

    ofstream wHackStream;
    wHackStream.open(writtenFilename, ios::ate);
    if(!wHackStream) {
        std::cerr << "failure to open the hack file." << std::endl;
        std::exit(1);
    }

    while(parser->hasMoreCommands()) {
        parser->advance();
        string hackLine = takeHackLine(parser, code);
        wHackStream << hackLine << endl;
    }

    wHackStream.close();
    return 0;
}