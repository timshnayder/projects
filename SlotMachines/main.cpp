#include <iostream>
#include <vector>

using namespace std;

int main() {
    int balance;
    int timesPlayed = 0;
    int currentMachine = 0;
    vector<int> machinePosition;
    vector<int> payPoint {35, 100, 10};
    vector<int> payAmount{30, 60, 9};

    cin >> balance;
    for(int i = 0; i < 3; i++){
        int machinePos;
        cin >> machinePos;
        machinePosition.push_back(machinePos);
    }

    while(balance > 0){
        balance--;
        machinePosition[currentMachine]++;
        if (machinePosition[currentMachine] >= payPoint[currentMachine]){
            balance += payAmount[currentMachine];
            machinePosition[currentMachine] = 0;
        }
        timesPlayed++;
        currentMachine++;
        if(currentMachine > 2){
            currentMachine = 0;
        }
    }

    cout << "Martha plays " << timesPlayed << " times before going broke." << endl;

    return 0;
}
