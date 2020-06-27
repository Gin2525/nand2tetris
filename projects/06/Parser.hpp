#include<string>
#include<vector>
class Parser{
public:
    int fileLength;
    std::vector<std::string> instructure;

    Parser(std::string);
    
    bool hasMoreCommands();
    void init(std::string filename);
};