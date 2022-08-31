#include <iostream>

using namespace std;

int main() {
    int numberOfInputs;
    long a;
    long b;
    long p;
    cin >> numberOfInputs;
    for(int i = 0; i < numberOfInputs; i++){
        cin >> a;
        cin >> b;
        cin >> p;
        cout << endl;
        if(a * b == p){
            cout << "POSSIBLE DOUBLE SIGMA" << endl;
        } else {
            cout << "16 BIT S/W ONLY" << endl;
        }
    }
    return 0;
}
