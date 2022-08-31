#include <iostream>
using namespace std;

int main() {
    string shelf;
    int numberOfL = 0;
    int numberOfM = 0;
    cin >> shelf;
    for(auto book: shelf){
        if(book == 'L'){
            numberOfL++;
        }
        if(book == 'M'){
            numberOfM++;
        }
    }

    int outliersInL = 0;
    int outliersInM = 0;
    int LsInM = 0;
    int MsInL = 0;

    for(int i = 0; i < numberOfL; i++){
        if(shelf[i] != 'L'){
            outliersInL++;
        }
        if(shelf[i] == 'M'){
            MsInL++;
        }
    }

    for(int i = numberOfL; i < numberOfL+numberOfM; i++){
        if(shelf[i] != 'M'){
            outliersInM++;
        }
        if(shelf[i] == 'L'){
            LsInM++;
        }
    }

    int numberOfEfficentSwaps = 0;
    if(LsInM < MsInL){
        numberOfEfficentSwaps = LsInM;
    } else {
        numberOfEfficentSwaps = MsInL;
    }

    int numberOfSwaps = outliersInL + outliersInM - numberOfEfficentSwaps;

    cout << numberOfSwaps << endl;

    return 0;
}
