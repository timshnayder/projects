#include <iostream>
#include <string>
using namespace std;

int main() {
    int numberOfS = 0;
    int numberOfT = 0;
    int numberOfLines;
    string line;

    cin>>numberOfLines;
    getline(cin, line); //Need to consume new line charachter after numberOfLines
    for(int i = 0; i < numberOfLines; i++){
        getline(cin, line);
        for(char character: line){
            if(character == 's' || character == 'S'){
                numberOfS++;
            } else if(character == 't' || character == 'T'){
                numberOfT++;
            }
        }
    }

    if(numberOfT>numberOfS){
        cout << "English" << endl;
    } else {
        cout << "French" << endl;
    }

    return 0;
}
