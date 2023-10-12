#include <iostream>
#include <vector>
#include <map>
#define MAXROW 1000
#define MAXCOL 1000
#define MAXNUM 1000000
using namespace std;
// Print
//    for(int i = 0; i < rows; i++){
//        for(int j = 0; j < cols; j++){
//            cout << room[i][j] << " ";
//        }
//        cout << endl;
//    }

class Coordinate {
public:
    int row;
    int col;
};

int globalRoom[MAXROW][MAXCOL];
bool globalVisited[MAXROW][MAXCOL];
vector<Coordinate> globalValueToCoord[MAXNUM+1];

bool findEscape(int room[MAXROW][MAXCOL], bool visited[MAXROW][MAXCOL], size_t startRow, size_t startCol, vector<Coordinate> valueToCoord[MAXNUM+1]){
    if(visited[startRow][startCol]){
        return false;
    }
    if(startRow == 0 && startCol == 0){
        return true;
    }
    visited[startRow][startCol] = true;
    vector<Coordinate>& coord = valueToCoord[int((startRow+1)*(startCol+1))];
    for (Coordinate& cell: coord) {
        if(findEscape(room, visited, cell.row, cell.col, valueToCoord)){
            return true;
        }
    }
//    //Go through every number
//    for(size_t i = 0; i < room.size(); i++){
//        for(size_t j = 0; j < room[0].size(); j++){
//            //If coordinate multiplied = current number. and If not visited
//            if( int((startRow+1)*(startCol+1)) ==  room[i][j]) {
//                if(findEscape(room, visited, i, j, valueToCoord)){
//                    return true;
//                }
//            }
//        }
//    }
    return false;
}

int main() {
    int rows, cols, num;
    cin >> rows >> cols;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> num;
            globalRoom[i][j] = num;
            Coordinate coord{i, j};
            globalValueToCoord[num].push_back(coord);

            globalVisited[i][j] = false;
        }
    }

//    for(int i = 0; i < rows; i++){
//        for(int j = 0; j < cols; j++){
//            cout << visited[i][j] << " ";
//        }
//        cout << endl;
//    }

    if(findEscape(globalRoom, globalVisited, rows-1, cols-1, globalValueToCoord)){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}