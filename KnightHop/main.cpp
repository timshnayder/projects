#include <iostream>
using namespace std;

int board[8][8] = {0};

bool outOfBoundaries(int coord){
    if(coord < 0 or coord >= 8){
        return true;
    }
    return false;
}

int getShortestDistance(int startX, int startY, int endX, int endY, int steps){
    if(startX == endX and startY == endY){
        return 0;
    }
    if(outOfBoundaries(startX)||outOfBoundaries(startY)||outOfBoundaries(endX)||outOfBoundaries(endY)){
        return -1;
    }
    if(board[startX][startY] != 0 && board[startX][startY] < steps){
        return -1;
    }
    board[startX][startY] = steps;

    int nextDistances[8] = {
            getShortestDistance(startX+1, startY+2, endX, endY, steps + 1),
            getShortestDistance(startX+2, startY+1, endX, endY, steps + 1),
            getShortestDistance(startX+2, startY-1, endX, endY, steps + 1),
            getShortestDistance(startX+1, startY-2, endX, endY, steps + 1),
            getShortestDistance(startX-1, startY-2, endX, endY, steps + 1),
            getShortestDistance(startX-2, startY-1, endX, endY, steps + 1),
            getShortestDistance(startX-2, startY+1, endX, endY, steps + 1),
            getShortestDistance(startX-1, startY+2, endX, endY, steps + 1)
    };
    int shortestDistance = -1;

    for(auto distance: nextDistances){
        if(distance == -1){
            continue;
        }
        if(shortestDistance == -1 || shortestDistance > distance){
            shortestDistance = distance;
        }
    }
    if(shortestDistance == -1){
        return -1;
    }
    return shortestDistance+1;
}

int main() {
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    cout << getShortestDistance(startX-1, startY-1, endX-1, endY-1, 1) << endl;
    return 0;
}
