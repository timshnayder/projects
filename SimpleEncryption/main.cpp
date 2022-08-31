#include <iostream>
#include <vector>
#include <string>

using namespace std;

char encryptCharacter(char letter, char key) {
    int shift = key - 'A';
    char encryptedLetter = letter + shift;
    if (encryptedLetter > 'Z'){
        encryptedLetter -= 'Z' - 'A' + 1;
    }
    return encryptedLetter;
}

int main() {
    string keyword;
    string originalMessageToEncrypt;

    getline(cin, keyword);
    getline(cin, originalMessageToEncrypt);

    string messageToEncrypt;
    for(auto letter: originalMessageToEncrypt){
        if(letter >= 'A' && letter <= 'Z'){
            messageToEncrypt += letter;
        }
    }

    unsigned int keywordIndex = 0;
    string encryptedMessage;

    for(auto letter: messageToEncrypt){
        encryptedMessage += encryptCharacter(letter, keyword[keywordIndex]);

        keywordIndex++;
        if(keywordIndex >= keyword.length()){
            keywordIndex = 0;
        }
    }

    cout << encryptedMessage << endl;

    return 0;
}
