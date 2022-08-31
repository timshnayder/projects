#include <iostream>
#include <string>

using namespace std;

int findLetterButton(char letter){
    switch(letter){
        case 'a':
        case 'b':
        case 'c':
            return 2;
        case 'd':
        case 'e':
        case 'f':
            return 3;
        case 'g':
        case 'h':
        case 'i':
            return 4;
        case 'j':
        case 'k':
        case 'l':
            return 5;
        case 'm':
        case 'n':
        case 'o':
            return 6;
        case 'p':
        case 'q':
        case 'r':
        case 's':
            return 7;
        case 't':
        case 'u':
        case 'v':
            return 8;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return 9;
    }
    return 0;
}

int orderOfLetter(char letter){
    switch(letter){
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
            return 1;
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x':
            return 2;
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y':
            return 3;
        case 's':
        case 'z':
            return 4;

    }
    return 0;
}

int main() {
    string word;
    while (true){
        int lastLetterButton = 0;
        cin >> word;
        if(word == "halt"){
            break;
        }
        int result = 0;
        for(unsigned int i = 0; i < word.length(); i++){
            result += orderOfLetter(word[i]);
            if(lastLetterButton == findLetterButton(word[i])){
                result+=2;
            }
            lastLetterButton = findLetterButton(word[i]);
        }
        cout << result << endl;
    }
    return 0;
}
