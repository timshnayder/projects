#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word){
    string wordReversed;
    for(int i = word.length()-1; i >= 0; i--){
        wordReversed+=word[i];
    }

    if(wordReversed == word){
        return true;
    } else {
        return false;
    }
}

int findLongestPalindrome(string word){
    int longestPalindrome = 0;
    for(int i = 0; i < word.length(); i++){
        for(int j = i; j <= word.length(); j++){
            string palindrome = word.substr(i,j);
            if(isPalindrome(palindrome) && palindrome.length() > longestPalindrome){
                longestPalindrome = palindrome.length();
            }
        }
    }
    return longestPalindrome;
}

int main() {
    int longestPalindrome = 0;
    string word;
    cin >> word;
    longestPalindrome = findLongestPalindrome(word);
    cout << longestPalindrome << endl;
    return 0;
}