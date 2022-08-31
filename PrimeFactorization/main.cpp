#include <iostream>
#include <vector>
using namespace std;

/*
 * Let's assume user entered 12
 * First prime is 2
 * Is 12 dividable by 2? Yes
 * 12 / 2 = 6
 * Is 6 dividable by 2? Yes
 * 6 / 2 = 3
 * Is 3 dividable by 2? No
 * Get next prime = 3
 * Is 3 dividable by 3? Yes
 * 3 / 3 = 1
 * Ended up with 1 -> exit loop
 * Factors are: 2 2 3
 */
int main() {
    long numberToFactorize = 0;
    vector<long> primeNumbers {2};
    cout << "What number do you want to prime factorize?: ";
    cin >> numberToFactorize;
    long currentPrime = 2;
    while(numberToFactorize > 1){
        while(numberToFactorize % currentPrime == 0){
            numberToFactorize /= currentPrime;
            cout << currentPrime << endl;
        }
        for(int i = currentPrime + 1; i <= numberToFactorize; i++){
            bool isDividable = false;
            for(auto prime: primeNumbers){
                if(i%prime == 0){
                    isDividable = true;
                    break;
                }
            }
            if(!isDividable){
                primeNumbers.push_back(i);
                currentPrime = i;
                break;
            }
        }
    }
    return 0;
}
