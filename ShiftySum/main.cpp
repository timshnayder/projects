#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int numberToShift, amountToShift, total;
    cin >> numberToShift >> amountToShift;
    total = numberToShift;

    for(int i = 1; i <= amountToShift; i++){
        total = total + (numberToShift*pow(10,i));
    }
    cout << total << endl;
    return 0;
}
