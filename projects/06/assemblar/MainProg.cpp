#include "Parser.hpp"
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    Parser *parser = new Parser("hoge.asm");
    cout << parser->fileLength << endl;
    cout << parser->currentComannd <<  endl;
    return 0;
}