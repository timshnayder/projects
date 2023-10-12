#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <memory>
typedef unsigned long long ull;

using namespace std;

void sieve(ull min, ull max, vector<ull>& primes){
    vector<bool> isPrime(max+1, true);
    for(ull i = 2; i*i < max; i++){
        if(isPrime[i]){
            for(ull j = i*2; j < max; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(ull i = 2; i < max; i++){
        if(isPrime[i] && i != 1){
            primes.push_back(i);
            if(i > min){
                cout << i << endl;
            }

        }
    }
}

void segmentedPrimes(ull minPrime, ull maxPrime){
    //Find all multiples
    //maxN is the number that we find up to when doing our simple sieve
    //primes will have all primes/multiples found in the simple sieve
    ull maxN = sqrt(maxPrime)+1;
    vector<ull> primes;
    sieve(minPrime, maxN, primes);

    unique_ptr<bool> isPrimePtr(new bool[maxPrime-minPrime+1]);
    bool *isPrime = isPrimePtr.get();
    memset(isPrime, true, sizeof(bool)*(maxPrime-minPrime+1));
    for(ull i = 0; i < primes.size(); i++){
        ull lowestMult = (minPrime/primes[i])*primes[i];
        if(lowestMult < minPrime){
            lowestMult+=primes[i];
        }
        for(ull j = lowestMult; j <= maxPrime; j+=primes[i]){
            isPrime[j-minPrime] = false;
        }
    }
    for(ull j = minPrime; j <= maxPrime; j++){
        if(isPrime[j-minPrime] && j != 1){
            cout << j << endl;
        }
    }

}

int main() {
    ull min, max;
    cin >> min >> max;
    segmentedPrimes(min, max);

    return 0;
}



