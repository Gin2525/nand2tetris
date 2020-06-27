#include <map>
#include <string>

class Code {
  private:
    std::map<std::string, std::string> destMap;
    std::map<std::string, std::string> compMap;
    std::map<std::string, std::string> jumpMap;

  public:
    Code();
    std::string dest(std::string mnemonic);
    std::string comp(std::string mnemonic);
    std::string jump(std::string mnemonic);
};