#include <iostream>
#include <vector>
using namespace std;

vector<int> factorize(int numberToFactorize){
    vector<int> result;
    vector<int> primeNumbers {2};
    int currentPrime = 2;
    while(numberToFactorize > 1){
        while(numberToFactorize % currentPrime == 0){
            numberToFactorize /= currentPrime;
            result.push_back(currentPrime);
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
    return result;
}

vector<int> intersection(const vector<int>& v1, const vector<int>& v2){
    vector<int> result;
    int v2index = 0;
    for(auto n1: v1){
        if(v2index >= v2.size()){
            break;
        }
        while (v2index < v2.size() && v2[v2index] < n1){
            v2index++;
        }
        if(v2index < v2.size() && v2[v2index] == n1){
            result.push_back(n1);
            v2index++;
        }
    }
    return result;
}

int gcf(int n1, int n2){
    auto f1 = factorize(n1);
    auto f2 = factorize(n2);
    auto commonFactors = intersection(f1, f2);
    int gcfResult = 1;
    for(auto n: commonFactors){
        gcfResult*=n;
    }
    return gcfResult;
}

long lcm(int n1, int n2){
    return (n1 * n2) / gcf(n1, n2);
}

int main() {
    int n1;
    int n2;

    cout << "Pick first number to find LCM: ";
    cin >> n1;

    cout << "Pick second number to find LCM: ";
    cin >> n2;

    cout << lcm(n1, n2) << endl;

    return 0;
}
