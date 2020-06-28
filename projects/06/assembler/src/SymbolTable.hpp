#include <map>
#include <string>

class SymbolTable {
  private:
    std::map<std::string, long> symbolTable;

  public:
    SymbolTable();
    void addEntry(std::string, int);
    bool contains(std::string);
    int getAddress(std::string);
};