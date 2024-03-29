#include<iostream>
#include<fstream>
using namespace std;


bool isAlphaNumeric(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}
bool isKeyword(const string& word) {
    return (word == "int" || word == "float" || word == "double" || word == "char" || word == "bool");
}
void generateToken(const string& line){
    string lexeme = "";
    for (int i = 0; i < line.length(); i++) {
       
        if (isAlphaNumeric(line[i]) || line[i] == '_') {
            lexeme += line[i];
        } else {
            if (lexeme.length() > 0) {
                if (isKeyword(lexeme)) {
                    cout << "Keyword: " << lexeme << endl;
                } else {
                    cout << "Identifier: " << lexeme << endl;
                }
                 if(line[i]>='0' && line[i]<='9'){
                cout << "can't start with digit " << line[i] << endl;
                return;
            }
                lexeme = "";
            }
            if (line[i] == ' ') {
                continue;
            }
            if (line[i] == '(' || line[i] == ')' || line[i] == '{' || line[i] == '}' || line[i] == ';' || line[i] == ',' || line[i] == '=') {
                cout << "Special Symbol: " << line[i] << endl;
            }
        }
    }

}
int main(){
    char buffer1 [4096];
    char buffer2 [4096];
    bool use_buffer1 = true;
    ifstream MyReadFile("readingfile.txt");
    while(!MyReadFile.eof()){
        if(use_buffer1){
            MyReadFile.read(buffer1, 4096);
            generateToken(buffer1);
            use_buffer1 = false;
        }
        else{
            MyReadFile.read(buffer2, 4096);
            generateToken(buffer2);
            use_buffer1 = true;
        }

    }
    MyReadFile.close();
}
