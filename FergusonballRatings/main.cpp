#include <iostream>
using namespace std;

int main() {
    int numberOfPlayers;
    int numberOfGoldPlayers = 0;
    int numberOfPoints;
    int numberOfFouls;
    bool isGoldTeam = true;
    cin >> numberOfPlayers;
    for(int i = 0; i < numberOfPlayers; i++){
        cin >> numberOfPoints >> numberOfFouls;
        if((numberOfPoints*5)-(numberOfFouls*3)>40){
            numberOfGoldPlayers++;
        } else {
            isGoldTeam = false;
        }
    }
    if(isGoldTeam){
        cout << numberOfGoldPlayers << "+" << endl;
    } else {
        cout << numberOfGoldPlayers << endl;
    }

    return 0;
}
