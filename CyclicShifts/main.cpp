#include <iostream>
#include <string>

using namespace std;

string shift(string textToShift){
    return textToShift.substr(1) + textToShift[0];
}

int main() {
    string textToSearch;
    string textToShift;
    string result = "no";
    cin >> textToSearch >> textToShift;
    for(unsigned int i = 0; i < textToShift.length(); i++){
        if(textToSearch.find(textToShift) != string::npos){
            result = "yes";
            break;
        }
        textToShift = shift(textToShift);
    }
    cout << result << endl;
    return 0;
}
