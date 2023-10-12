#include <iostream>
#include <stdlib.h>
#define ull unsigned long long
#define ll unsigned long long

using namespace std;

ull bigMul(ull first, ull second, ull mod){
    ull result = 0, y = first % mod;
    first%=mod;

    while(second > 0){
        if(second%2){
            result = (result+first)%mod;
        }
        first = (2*first)%mod;
        second/=2;
    }
    return result % mod;
}

ull fastPowerMod(ull base, ull exp, ull mod){
    ull result = 1;
    base=base%mod;
    while (exp > 0) {
        if (exp % 2) {
            result = bigMul(result, base, mod);
        }
        exp /=2;
        base = bigMul(base, base, mod);
    }
    return result;
}

void fermatPrimality(ull num, int tests){
    if(num == 1){
        cout << "NOT" << endl;
        return;
    }else if(num <= 3){
        cout << "PRIME" << endl;
        return;
    }
    for(ull i = 0; i < tests; i++){
        int r = rand() % (num-1)+1;

        if(fastPowerMod(r, num-1, num) != 1){
            cout << "NOT" << endl;
            return;
        }
    }
    cout << "PRIME" << endl;
}

bool millerRabinTest(ull num, ull testerNum){
    ull randomNumber = 2+rand()%(num-4);
    ull newNum = fastPowerMod(randomNumber, testerNum, num);
    if(newNum == 1 || newNum == num-1){
        return true;
    }
    while(testerNum != num-1){
        newNum = bigMul(newNum, newNum, num);
        testerNum *= 2;
        if(newNum == 1){
            return false;
        } else if(newNum == num-1){
            return true;
        }
    }
    return false;
}

void isPrime(ull num, ull tests){
    if(num == 1 || num == 4){
        cout << "NOT" << endl;
        return;
    } else if(num <= 3){
        cout << "PRIME" << endl;
        return;
    }

    ull testerNum = num -1;

    while( testerNum % 2 == 0 ){
        testerNum/=2;
    }

    for(int i = 0; i < tests; i++){
        if(!millerRabinTest(num, testerNum)){
            cout << "NOT" << endl;
            return;
        }
    }
    cout << "PRIME" << endl;
    return;
}

int main() {
    int numPrimes;
    cin >> numPrimes;
    ull num;
    for(int i = 0 ; i < numPrimes; i++){
        cin >> num;
//        cout << num << endl;
        isPrime(num, 10000);
    }

    return 0;
}