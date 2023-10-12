#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;
/*
long long fib(unsigned long long n){
   static map<int, long long> numbers;
   auto f = numbers.find(n);
   if(f != numbers.end()){
       // cout << "Return from cache " << n << endl;
       return f->second;
   }
   // cout << "Calculate " << n << endl;
   if(n <= 2){
       numbers[n] = 1;
       return 1;
   } else {
       long long number = fib(n-1)%MOD + fib(n-2)%MOD;
       numbers[n] = number;
       return number;
   }
}
*/

void multiply(unsigned long long fibo[2][2], unsigned long long y[2][2]){
    unsigned long long a1 = (fibo[0][0])*(y[0][0])+(fibo[0][1])*(y[1][0]);
    unsigned long long a2 = (fibo[0][0])*(y[0][1])+(fibo[0][1])*(y[1][1]);
    unsigned long long b1 = (fibo[1][0])*(y[0][0])+(fibo[1][1])*(y[1][0]);
    unsigned long long b2 = (fibo[1][0])*(y[0][1])+(fibo[1][1])*(y[1][1]);

    fibo[0][0] = a1;
    fibo[0][1] = a2;
    fibo[1][0] = b1;
    fibo[1][1] = b2;

}

void power(unsigned long long fibo[2][2], unsigned long long pwr){
    if(pwr == 1){
        return;
    }
    if(pwr%2==0){
        multiply(fibo,fibo);
        power(fibo, pwr/2);
    } else {
        unsigned long long fiboCopy[2][2] = { { fibo[0][0], fibo[0][1] }, { fibo[1][0], fibo[1][1] } };
        multiply(fibo,fibo);
        power(fibo,(pwr-1)/2);
        multiply(fibo, fiboCopy);
    }
}

unsigned long long fib(unsigned long long n){
    if(n <= 2){
        return 1;
    }
    unsigned long long fibo[2][2] = { { 1, 1 }, { 1, 0 } };
    power(fibo, n-1);
    return fibo[0][0];
}

int main() {
    unsigned long long fibN = -1;
    while(fibN!=0) {
        cin >> fibN;
        if(fibN==0){
            break;
        }
        cout << fib(fibN) << endl;
    }

    return 0;
}

/*

0 0   0 1
[1  1]
[1  0]
1 0   1 1
*/
