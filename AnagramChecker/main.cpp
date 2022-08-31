#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string word1, word2;
    getline(cin, word1);
    getline(cin, word2);
    vector<int> frequencyOfCharacters(256,0);
    for(auto c: word1){
        if(c != ' '){
            frequencyOfCharacters[c]++;
        }
    }
    for(auto c: word2){
        if(c != ' '){
            frequencyOfCharacters[c]--;
        }
    }
    for(auto frequency: frequencyOfCharacters){
        if(frequency != 0){
            cout << "Is not an anagram." << endl;
            return 0;
        }
    }
    cout << "Is an anagram." << endl;
    return 0;
}
