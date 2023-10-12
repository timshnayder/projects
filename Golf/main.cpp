#include <iostream>

using namespace std;

int main() {
    int distFromTeeToHole;
    int numClubs;
    int clubs[numClubs];
    int clubDist;
    int clubsNeeded = 0;
    cin >> distFromTeeToHole;
    for(int i = 0; i < numClubs; i++){
        cin >> clubDist;
        clubs[i] = clubDist;
    }
    int n = sizeof(clubs) / sizeof(clubs[0]);
    sort(clubs, clubs+n, greater<int>);

    return 0;
}
