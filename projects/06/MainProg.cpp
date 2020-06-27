#include "Parser.hpp"
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    std::string filename = "hogefile";
    Parser *parser = new Parser(filename);
    cout << parser->fileLength << endl;
    cout << parser->instructure.at(0);
    return 0;
}