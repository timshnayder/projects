#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void sieve(int min, int max, vector<int>& primes){
    vector<bool> isPrime(max+1, true);
    for(int i = 2; i*i < max; i++){
        if(isPrime[i] == true){
            for(int j = i*2; j < max; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i < max; i++){
        if(isPrime[i] && i != 1){
            cout << i << endl;
            primes.push_back(i);
        }
    }
}

void segmentedPrimes(int min, int max){
    int maxN = sqrt(max)+1;
    vector<int> primes;
    sieve(min, maxN, primes);
    int limit = max;

    bool isPrime[maxN];
    memset(isPrime, true, sizeof(isPrime));

    for(int i = maxN; i < max; i++){
        for(int j = 0; j < primes.size(); j++){
            if(i%primes[j]==0){
                isPrime[i-maxN] = false;
                continue;
            }
        }
        if(isPrime[i-maxN]){
            cout << i << endl;
        }
    }
}

int main() {
    int min, max;
    cin >> min >> max;
    segmentedPrimes(min, max);

    return 0;
}
