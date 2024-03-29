#include <iostream>
#include <fstream>
using namespace std;

enum COL{Slash, Asterisk, Nasterisk, A, R, Tok};  
enum Tok{N=0};
enum A{F=0, T=1};
int transitiontable[5][6]{
    {1, 0, 0, F, F, N},
    {0, 2, 0, F, F, N},
    {0, 3, 2, F, F, N},
    {4, 3, 2, F, F, N},
    {0, 0, 0, T, F, N}
};

COL getColumnType(char c) {
    if (c == '/') return Slash;
    else if (c == '*') return Asterisk;
    else if (c != '*') return Nasterisk;
    else return A;
}

int main() {
    ifstream file("readingfile.txt");
    char buffer1[4096];
    char buffer2[4096];
    int state = 0;
    bool useBuffer1 = true;

    while (!file.eof()) {
        char* buffer = useBuffer1 ? buffer1 : buffer2;
        file.read(buffer, 4096);
        // buffer[file.gcount()] = '\0';
        useBuffer1 = !useBuffer1;

        for (int i = 0; buffer[i] != '\0'; i++) {
            char currentChar = buffer[i];
            COL col = getColumnType(currentChar);
            state = transitiontable[state][col];
            if (state ==1 || state == 2 || state == 3) {
                cout << currentChar;
            }
            else if (state == 4) {
                cout << currentChar;
                state = 0;
            }

        }
    }

    file.close();
    return 0;
}
