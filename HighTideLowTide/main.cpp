#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, tide;

    cin >> n;
    int tides[n];
    for(int i = 0; i < n; i++){
        cin >> tide;
        tides[i] = tide;
    }

    sort(tides, tides + (sizeof(tides)/sizeof(tides[0])));

    int middle;
    if(n & 1){
        // if odd
        middle = n/2;
        cout << tides[middle] << " ";
        for(int i = 1; i < middle+1; i++){
            cout << tides[middle+i] << " ";
            cout << tides[middle-i] << " ";
        }

    } else {
        // if even
        middle = n/2-1;
        cout << tides[middle] << " ";
        if(n==2){
            cout << tides[1] << " ";
            return 0;
        }
        cout << tides[middle+1] << " ";
        for(int i = 1; i < middle+1; i++){
            cout << tides[middle-i] << " ";
            cout << tides[middle+i+1] << " ";
        }
    }
    return 0;
}
