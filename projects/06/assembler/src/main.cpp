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

string takeHackLine(Parser *parser, Code *code) {
    int t = parser->commandType();
    if(t == 0) {
        // A
        return "0" + binary(parser->symbol());
    } else if(t == 1) {
        // C
        string dest = code->dest(parser->dest());
        string comp = code->comp(parser->comp());
        string jump = code->jump(parser->jump());
        return "111" + comp + dest + jump;
    } else if(t == 2) {
        // L
        //シンボルフリーなアセンブリにてL_COMMANDは出現しない
        return "-1";
    } else {
        return "-1";
    }
}

void initSymbolTable(Parser *parser, SymbolTable *symbolTable) {
    long addressCounter = 0;
    while(parser->hasMoreCommands()) {
        parser->advance();
        if(parser->commandType() == 2) {
            // case: L_COMMAND
            symbolTable->addEntry(parser->symbol(), addressCounter+1);
            continue;
        }
        addressCounter++;
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

    // create hack file name by asm filname.
    int dotIdx = asmFilename.rfind('.');
    std::string HackFilename = asmFilename.substr(0, dotIdx) + ".hack";

    // open output stream for hack
    ofstream hackFile;
    hackFile.open(HackFilename, ios::ate);
    if(!hackFile) {
        std::cerr << "failure to open the hack file." << std::endl;
        std::exit(1);
    }

    while(parser->hasMoreCommands()) {
        parser->advance();
        hackFile << takeHackLine(parser, code) << endl;
    }

    hackFile.close();
    return 0;
}