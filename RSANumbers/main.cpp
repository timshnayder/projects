#include <iostream>
using namespace std;

bool isNumberRSA(int number){
    int amountOfDivisors = 2;
    for(int i = 2; i <= number/2;i++){
        if(number%i == 0){
            amountOfDivisors++;
        }
    }
    if(amountOfDivisors==4){
        return true;
    } else{
        return false;
    }
}

int main() {
    int rangeMinimum;
    int rangeMaximum;
    int numberOfRSA = 0;
    cin >> rangeMinimum >> rangeMaximum;

    for(int i = rangeMinimum; i<=rangeMaximum;i++){
        if(isNumberRSA(i)){
            numberOfRSA++;
        }
    }

    cout << "The number of RSA numbers between " << rangeMinimum << " and " << rangeMaximum << " is " << numberOfRSA << endl;

    return 0;
}
