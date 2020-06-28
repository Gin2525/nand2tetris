#include <map>
#include <string>

class SymbolTable {
  private:
    std::map<std::string, long> symbolTable;
    const int SP_ADDRESS = 0;
    const int LCL_ADDRESS = 1;
    const int ARG_ADDRESS = 2;
    const int THIS_ADDERSS = 3;
    const int THAT_ADDRESS = 4;
    const int R_MAX_NUMBER = 15;
    const int SCREEN_ADDRESS = 16384;
    const int KBD_ADDRESS = 24576;

  public:
    SymbolTable();
    void addEntry(std::string, int);
    bool contains(std::string);
    int getAddress(std::string);
};