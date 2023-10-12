#include <iostream>
#include <map>
using namespace std;

long long fib(int n){
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
       long long number = fib(n-1) + fib(n-2);
       numbers[n] = number;
       return number;
   }
}

int main() {
    for(int i = 1; i < 100; i++){
        cout << i << " " << fib(i) << endl;
    }

    return 0;
}
