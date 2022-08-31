#include <iostream>

using namespace std;

int main() {
    int rangeEnd;
    int numToInverse;
    int numToMultiply;

    cout << "Input end of range: ";
    cin >> rangeEnd;
    cout << "input number to inverse: ";
    cin >> numToInverse;

    for(numToMultiply = 0; numToMultiply < rangeEnd; numToMultiply++){
        if((numToInverse * numToMultiply) % rangeEnd == 1){
            cout << numToMultiply << endl;
            return 0;
        }
    }
    cout << "No such integer exists." << endl;
    return 0;
}
