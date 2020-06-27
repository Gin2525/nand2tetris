#include "Parser.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string testFilename = "test.asm";
    Parser *parser = new Parser(testFilename);

    parser->advance();
    cout << parser->commandType() << endl;
}