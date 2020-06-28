#include "Code.hpp"
#include "Parser.hpp"
#include "SymbolTable.hpp"
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

bool check_int(std::string str) {
    try {
        ::stoi(str);
        return true;
    } catch(...) {
        return false;
    }
}

void init(Parser *parser, SymbolTable *symbolTable) {
    parser->reset();
    // first scan
    long addressCounter = 0;
    while(parser->hasMoreCommands()) {
        parser->advance();
        if(parser->commandType() == 2) {
            // case: L_COMMAND
            symbolTable->addEntry(parser->symbol(), addressCounter);
            continue;
        }
        addressCounter++;
    }
    // reset parser
    parser->reset();
    // second scan
    long varCounter = 16;
    while(parser->hasMoreCommands()) {
        parser->advance();
        if(parser->commandType() == 0) {
            // case: A_COMMAND
            string s = parser->symbol();
            if(!check_int(s) && !symbolTable->contains(s)) {
                symbolTable->addEntry(parser->symbol(), varCounter++);
            }
        }
    }
    // reset parser
    parser->reset();
}

string takeHackLine(Parser *parser, Code *code, SymbolTable *symbolTable) {
    int t = parser->commandType();
    if(t == 0) {
        // A
        string s = parser->symbol();
        if(check_int(s))
            return "0" + binary(s);
        else {
            if(symbolTable->contains(s)) {
                return "0" + binary(::to_string(symbolTable->getAddress(s)));
            } else {
                return "-1";
            }
        }
    } else if(t == 1) {
        // C
        string dest = code->dest(parser->dest());
        string comp = code->comp(parser->comp());
        string jump = code->jump(parser->jump());
        return "111" + comp + dest + jump;
    } else if(t == 2) {
        // L
        //シンボルフリーなアセンブリにてL_COMMANDは出現しない
        return "";
    } else {
        return "-1";
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "missing count of given argments" << endl;
        return 1;
    }
    std::string asmFilename = argv[1];
    Code *code = new Code();
    Parser *parser = new Parser(asmFilename);
    SymbolTable *symbolTable = new SymbolTable();
    init(parser, symbolTable);

    // make hack filename by asm filname.
    int dotIdx = asmFilename.rfind('.');
    std::string HackFilename = asmFilename.substr(0, dotIdx) + ".hack";

    // open output stream for hack
    ofstream hackFile;
    hackFile.open(HackFilename, ios::ate);
    if(!hackFile) {
        std::cerr << "failure to open the hack file." << std::endl;
        std::exit(1);
    }

    // generate hack
    while(parser->hasMoreCommands()) {
        parser->advance();
        string hackLine = takeHackLine(parser, code, symbolTable);
        if(hackLine != "")
            hackFile << hackLine << endl;
    }

    hackFile.close();
    return 0;
}
