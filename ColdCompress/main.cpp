#include <iostream>
#include <string>
using namespace std;

int main() {
    int numberOfLines;
    string line;
    getline(cin, line);
    numberOfLines = stoi(line);
    for(int i = 0; i < numberOfLines; i++){

        int length = 0;
        getline(cin, line);
        char currentCharacter = line[0];
        for(auto c: line){
            if(c == currentCharacter){
                length++;
            } else {
                cout << length << " " << currentCharacter << " ";
                length = 1;
                currentCharacter = c;
            }
        }
        cout << length << " " << currentCharacter;
        cout << endl;

    }
    return 0;
}
