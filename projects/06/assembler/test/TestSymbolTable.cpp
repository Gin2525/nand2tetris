#include "SymbolTable.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    SymbolTable *table = new SymbolTable();
    string symbol0 = "xxx";
    int address0 = 123;
    table->addEntry(symbol0, address0);
    int actAdd0 = table->getAddress(symbol0);
    if(actAdd0 != address0) {
        cout << "test failured" << endl;
        exit(1);
    }
    return 0;
}