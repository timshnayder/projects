#include <iostream>
#include <vector>
#define WALL 0
#define UNVISITED 1
#define VISITED 2

using namespace std;

void printRoom(int room[20][20]){
    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 20; x++){
            cout << room[x][y] << "  ";
        }
        cout << endl;
    }
}

int main() {
    int rectangleWidth;
    int rectangleHeight;
    int cutOutWidth;
    int cutOutHeight;
    int steps;
    int locationX;
    int locationY;
    char direction;

    cin >> rectangleWidth >> rectangleHeight >> cutOutWidth >> cutOutHeight >> steps;

    int room[20][20] = {WALL};

    for(int x = cutOutWidth; x < rectangleWidth - cutOutWidth; x++){
        for(int y = 0; y < rectangleHeight; y++){
            room[x][y] = UNVISITED;
        }
    }

    for(int y = cutOutHeight; y < rectangleHeight - cutOutHeight; y++){
        for(int x = 0; x < rectangleWidth; x++){
            room[x][y] = UNVISITED;
        }
    }

    locationX = cutOutWidth;
    locationY = 0;
    direction = 'E';

    while(steps > 0){
        room[locationX][locationY] = VISITED;
        if(direction == 'N'){
            //Can we go left?
            if(locationX > 0 && room[locationX-1][locationY] == UNVISITED){
                direction = 'W';
                locationX--;
                steps--;
                continue;
            }
            //Can we go straight?
            if(locationY > 0 && room[locationX][locationY-1] == UNVISITED){
                locationY--;
                steps--;
                continue;
            }
            //Can we go right?
            if(locationX < rectangleWidth-1 && room[locationX+1][locationY] == UNVISITED){
                direction = 'E';
                locationX++;
                steps--;
                continue;
            }
            break;
        }

        if(direction == 'E'){
            //Can we go left?
            if(locationY > 0 && room[locationX][locationY-1] == UNVISITED){
                direction = 'N';
                locationY--;
                steps--;
                continue;
            }
            //Can we go straight?
            if(locationX < rectangleWidth-1 && room[locationX+1][locationY] == UNVISITED){
                locationX++;
                steps--;
                continue;
            }
            //Can we go right?
            if(locationY < rectangleHeight-1 && room[locationX][locationY+1] == UNVISITED){
                direction = 'S';
                locationY++;
                steps--;
                continue;
            }
            break;
        }

        if(direction == 'S'){
            //Can we go left?
            if(locationX < rectangleWidth-1 && room[locationX+1][locationY] == UNVISITED){
                direction = 'E';
                locationX++;
                steps--;
                continue;
            }
            //Can we go straight?
            if(locationY < rectangleHeight-1 && room[locationX][locationY+1] == UNVISITED){
                locationY++;
                steps--;
                continue;
            }
            //Can we go right?
            if(locationX > 0 && room[locationX-1][locationY] == UNVISITED){
                direction = 'W';
                locationX--;
                steps--;
                continue;
            }
            break;
        }

        if(direction == 'W'){
            //Can we go left?
            if(locationY < rectangleHeight-1 && room[locationX][locationY+1] == UNVISITED){
                direction = 'S';
                locationY++;
                steps--;
                continue;
            }
            //Can we go straight?
            if(locationX > 0 && room[locationX-1][locationY] == UNVISITED){
                direction = 'W';
                locationX--;
                steps--;
                continue;
            }
            //Can we go right?
            if(locationY > 0 && room[locationX][locationY-1] == UNVISITED){
                direction = 'N';
                locationY--;
                steps--;
                continue;
            }
            break;
        }
    }

    cout << locationX + 1 << endl;
    cout << locationY + 1 << endl;

    return 0;
}
