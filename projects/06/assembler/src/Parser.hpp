#include <string>
#include <vector>

class Parser {
  private:
    int fileLength;
    std::vector<std::string>::iterator nextIte;
    std::vector<std::string> instructure;
    std::string currentCommand;

  public:
    Parser(std::string);

    bool hasMoreCommands();
    void advance();
    int commandType();
    std::string symbol();
    std::string dest();
    std::string comp();
    std::string jump();
};