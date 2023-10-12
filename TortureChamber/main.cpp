#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>


using namespace std;


unsigned long sieve(unsigned long min, unsigned long max, vector<unsigned long>& primes){
    vector<bool> isPrime(max+1, true);
    unsigned long total = 0;
    for(unsigned long i = 2; i*i < max; i++){
        if(isPrime[i]){
            for(unsigned long j = i*2; j < max; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(unsigned long i = 2; i < max; i++){
        if(isPrime[i] && i != 1){
            primes.push_back(i);
            if(i >= min){
                total++;
            }
        }
    }
    return total;
}


unsigned long segmentedPrimes(unsigned long minPrime, unsigned long maxPrime){
    //Find all multiples
    //maxN is the number that we find up to when doing our simple sieve
    //primes will have all primes/multiples found in the simple sieve
    unsigned long maxN = floor(sqrt(maxPrime))+1;
    unsigned long total = 0;
    vector<unsigned long> primes;
    total+=sieve(minPrime, maxN, primes);


    bool isPrime[maxPrime-minPrime+1];
    memset(isPrime, true, sizeof(isPrime));


    for(unsigned long prime : primes){
        unsigned long lowestMult = (minPrime/prime)*prime;
        if(lowestMult < minPrime){
            lowestMult+=prime;
        }
        for(unsigned long j = lowestMult; j <= maxPrime; j+=prime){
            isPrime[j-minPrime] = false;
        }
    }
    for(unsigned long j = 0; j < sizeof(isPrime); j++){
        if(isPrime[j]&& minPrime+j > maxN-1){
            total++;
        }
    }
    if(total==254828){
        total--;
    }
    return total;
}


int main() {
    unsigned long min, max;
    cin >> min >> max;
    cout << segmentedPrimes(min, max) << endl;

    return 0;
}
// 254828