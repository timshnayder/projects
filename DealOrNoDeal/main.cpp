#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> cases = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
    int total = 0;
    int totalN = 0;
    int opened = 0;
    int offer = 0;
    cin >> opened;
    int caseN;
    for(int i = 0; i < opened; i++){
        cin >> caseN;
        cases[caseN-1] = 0;
    }

    for(int i = 0; i < 10; i++){
        if(cases[i]>=100){
            total += cases[i];
            totalN++;
        }
    }

    cin >> offer;
    if(total/totalN > offer){
        cout << "no deal" << endl;
    } else {
        cout << "deal" << endl;
    }


    return 0;
}
