#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(int argc, char* argv[]){
    if(argc != 2){
        cerr << "引数の数が間違っています。"<< endl;
        cerr << "./getline input.txt"<<endl;
        return 1;
    }

    ifstream ifs(argv[1],ios::in);

    if(!ifs){
        cerr<<"Error: file not opened." << endl;
        return 1;
    }

    string tmp;
    string str;
    int num = 1;

    while(getline(ifs,tmp)){
        cout << num << ": "<< tmp <<endl;
        num++;
    }
    ifs.close();
}