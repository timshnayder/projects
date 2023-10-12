#include <iostream>
using namespace std;

int main() {
    int dice1Max;
    int dice2Max;
    int ways = 0;
    cin >> dice1Max >> dice2Max;

    if (dice1Max > 9){
        dice1Max = 9;
    }
    if (dice2Max > 9){
        dice2Max = 9;
    }

    ways = dice1Max + dice2Max - 9;

    if(ways < 0){
        ways = 0;
    }

    if(ways == 1){
        cout << "There is " << ways << " way to get the sum 10." << endl;
    } else {
        cout << "There are " << ways << " ways to get the sum 10." << endl;
    }

    return 0;
}
