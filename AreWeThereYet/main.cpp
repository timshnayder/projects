#include <iostream>
using namespace std;

int main() {
    int dist;
    int dists[5] = {0};
    for(int i = 0; i < 4; i++){
        cin >> dist;
        dists[i+1] = dist;
        dists[i+1]+=dists[i];
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << abs(dists[j] - dists[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}
