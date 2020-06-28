#include "SymbolTable.hpp"
#include <iostream>
#include <string>

using namespace std;

void testFailured(std::string testTitle) {
    cout << "test failured." << endl;
    cout << "test title : " << testTitle << endl;
    exit(1);
}

int main() {
    SymbolTable *table = new SymbolTable();
    string dummySymbol0 = "yyy";
    string symbol0 = "xxx";
    int address0 = 123;
    table->addEntry(symbol0, address0);
    int actAdd0 = table->getAddress(symbol0);

    if(actAdd0 != address0)
        testFailured("whether getting the address?");

    if(table->contains(dummySymbol0))
        testFailured("throw a dummy address");

    if(!table->contains(symbol0))
        testFailured("throw a collect adderss");

    cout << "test sucessed" << endl;
    return 0;
}