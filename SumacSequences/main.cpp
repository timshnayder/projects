#include <iostream>
using namespace std;

int main() {
    int lastNumber;
    int beforeLastNumber;
    int lengthOfSequence = 2;
    cin >> beforeLastNumber >> lastNumber;
    while(beforeLastNumber >= lastNumber){
        int nextNumber = beforeLastNumber - lastNumber;
        beforeLastNumber = lastNumber;
        lastNumber = nextNumber;
        lengthOfSequence++;
    }
    cout << lengthOfSequence << endl;
    return 0;
}
