#include <iostream>
#include <set>
using namespace std;

int main() {
    int numGates, numPlanes, plane;
    int total = 0;
    cin >> numGates >> numPlanes;
    set<int> gates;
    for(int i = 1; i < numGates+1; i++){
        gates.insert(-i);
    }
    for(int i = 0; i < numPlanes; i++){
        cin >> plane;
        auto found = gates.lower_bound(-plane);
        if(found != gates.end()){
            total++;
            gates.erase(found);
        } else{
            break;
        }
    }

    cout << total << endl;
    return 0;
}

