#include <iostream>

using namespace std;

int main() {
    int instruction;
    string lastDirection;
    cin >> instruction;
    while(instruction != 99999){
        int direction1 = instruction / 10000;
        int direction2 = (instruction / 1000) % 10;
        int steps = instruction % 1000;
        if((direction1 + direction2) % 2 == 0 && (direction1 + direction2) != 0){
            cout << "right" << " " << steps << endl;
            lastDirection = "right";
        } else if((direction1 + direction2) % 2 == 1){
            cout << "left" << " " << steps << endl;
            lastDirection = "left";
        } else {
            cout << lastDirection << " " << steps << endl;
        }
        cin >> instruction;
    }
    return 0;
}
