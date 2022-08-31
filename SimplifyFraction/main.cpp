#include <iostream>
#include <vector>
using namespace std;

class PrimeNumbers {
public:
    PrimeNumbers() : currentPrime(1) {}
    int getNext(){
        for(int i = currentPrime + 1; ; i++){
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
        return currentPrime;
    }

private:
    vector<int> primeNumbers;
    int currentPrime;
};

vector<int> factorize(int numberToFactorize){
    vector<int> result;
    PrimeNumbers p;
    int currentPrime = p.getNext();
    while(numberToFactorize > 1){
        while(numberToFactorize % currentPrime == 0){
            numberToFactorize /= currentPrime;
            result.push_back(currentPrime);
        }
        currentPrime = p.getNext();
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
    int numerator;
    int denominator;

    cout << "Numerator of fraction to simplify:  ";
    cin >> numerator;

    cout << "Denominator of fraction to simplify: ";
    cin >> denominator;

    if(numerator >= denominator){
        //Improper fraction
        int whole = numerator / denominator;
        numerator %= denominator;

        cout << whole << " ";
    }

    int g = gcf(numerator, denominator);
    denominator /= g;
    numerator /= g;

    cout << numerator << "/" << denominator << endl;

    return 0;
}
