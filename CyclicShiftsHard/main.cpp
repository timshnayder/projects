#include <iostream>
#include <string>

using namespace std;

int main() {
    string textToSearch;
    string textToShift;
    string result = "no";
    cin >> textToSearch >> textToShift;
    for(unsigned int i = 0; i < textToSearch.length(); i++){
        if(textToSearch[i] == textToShift[0]){
            unsigned int indexLeft = textToShift.length() - 1;
            unsigned int indexRight = 1;
            while(i + indexRight < textToSearch.length() && indexRight < textToShift.length() && textToSearch[i+indexRight] == textToShift[indexRight]){
                indexRight++;
            }
            while(i + indexLeft - textToShift.length() < textToSearch.length() && indexLeft > 0 && textToSearch[i + indexLeft - textToShift.length()] == textToShift[indexLeft]) {
                indexLeft--;
            }
            if (indexRight - indexLeft >= textToShift.length()) {
                result = "yes";
                break;
            }
        }
    }
    cout << result << endl;
    return 0;
}
