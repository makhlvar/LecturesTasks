#include <iostream>
#include <fstream>

void process(std::string inS, std::string outS){
    std::ifstream inFile(inS);
    std::ofstream outFile(outS);
    std::string s;
    while(std::getline(inFile,s)){
        if(s == "EOF"){
            break;
        }
        if(s[s.length() - 1] == '?'){
            s += '{';
        }
        if(s[0] == '-'){
            s[0] = '~';
        }
        if(s[0] == '+'){
            s[0] = '=';
        }
        if(s[0] == '\0'){
            s += '}';
        }
        outFile << s << std::endl;  
    }
    inFile.close();
    outFile.close();
}
int main(){
    process ("1.txt","1.gift");
    return 0;
}