#include <iostream>
#include <string>
using namespace std;

int main() {
    int numberOfInputs;
    int lowestCoordinate = 101, highestCoordinate = 0, leftestCoordinate = 101, rightestCoordinate = 0;
    int xCoordinate, yCoordinate;
    char comma;
    string xCoordinateStr, yCoordinateStr;
    string coordinate;
    cin >> numberOfInputs;
    for(int i = 0; i < numberOfInputs; i++){
        cin >> xCoordinate >> comma >> yCoordinate;
//        cin >> coordinate;
//        size_t commaPosition = coordinate.find(",");
//        xCoordinateStr = coordinate.substr(0, commaPosition);
//        yCoordinateStr = coordinate.substr(commaPosition+1);
//        xCoordinate = stoi(xCoordinateStr);
//        yCoordinate = stoi(yCoordinateStr);
        if (xCoordinate < leftestCoordinate){
            leftestCoordinate = xCoordinate;
        }
        if (xCoordinate > rightestCoordinate){
            rightestCoordinate = xCoordinate;
        }
        if (yCoordinate < lowestCoordinate){
            lowestCoordinate = yCoordinate;
        }
        if (yCoordinate > highestCoordinate){
            highestCoordinate = yCoordinate;
        }
    }
    cout << leftestCoordinate-1 << "," << lowestCoordinate-1 << endl;
    cout << rightestCoordinate+1 << "," << highestCoordinate+1 << endl;
    return 0;
}
