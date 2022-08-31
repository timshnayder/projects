#include <iostream>
using namespace std;

int main() {
    int startX, startY, endX, endY, energyUnits, distanceBetweenPoints;

    cin >> startX >> startY >> endX >> endY >> energyUnits;

    distanceBetweenPoints = abs(startX - endX) + abs(startY - endY);
    
    if(energyUnits>=distanceBetweenPoints){
        if((energyUnits-distanceBetweenPoints)%2==0){
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    } else {
        cout << "N" << endl;
    }
    return 0;
}
