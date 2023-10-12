#include <iostream>
#include <string>
using namespace std;

int main() {
    int numMessageLists, numRecpients;
    string name;
    cin >> numMessageLists;
    for(int i = 0; i < numMessageLists; i++){
        cin >> numRecpients;
        string names[numRecpients];
        for(int i = 0; i < numRecpients; i++){
            cin >> name;
            names[i] = name;
        }
    }
    return 0;
}
