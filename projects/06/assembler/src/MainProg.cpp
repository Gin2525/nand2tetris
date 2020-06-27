#include "Parser.hpp"
#include "Code.hpp"
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // std::string filename = "add.asm";
    // Parser *parser = new Parser(filename);
    // while(parser->hasMoreCommands()){
    //     parser->advance();
    //     if(parser->commandType()==1){
    //         cout << parser->dest() << ' ';
    //         cout << parser->comp() << ' ';
    //         cout << parser->jump() << endl;
    //     }else{
    //         cout << parser->symbol() << endl;
    //     }
    // }

    Code *code = new Code();
    cout << code->jump("JLE") << endl;

    return 0;
}