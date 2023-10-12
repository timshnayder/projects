#include <iostream>
using namespace std;

int main() {
    int numGates;
    cin >> numGates;
    int numPlanes;
    cin >> numPlanes;
    int planeGates[numPlanes];

    int planeGate;
    for(int i = 0; i < numPlanes; i++){
        cin >> planeGate;
        planeGates[i] = planeGate;
    }
    int n = sizeof(planeGates)/ sizeof(planeGates[0]);
    sort(planeGates, planeGates+n);
    
    return 0;
}
