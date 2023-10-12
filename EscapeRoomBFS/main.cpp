#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>

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

bool findEscape(vector<vector<int>>& room, vector<vector<bool>>& visited, int startRow, int startCol, unordered_map<int, vector<Coordinate>>& valueToCoord){
    queue<Coordinate> q;
    Coordinate end{ startRow, startCol};
    q.push(end);

    while (!q.empty()) {
        Coordinate& current = q.front();
        q.pop();
        if (current.row == 0 && current.col == 0) {
            return true;
        }
        if (visited[current.row][current.col]) {
            continue;
        }
        visited[current.row][current.col] = true;
        vector<Coordinate>& coord = valueToCoord[(current.row+1)*(current.col+1)];
        for (Coordinate& cell: coord) {
            q.push(cell);
        }
    }
    return false;
}

int main() {
    int rows, cols, num;
    cin >> rows >> cols;
    unordered_map<int, vector<Coordinate>> valueToCoord;
    vector<vector<int>> room;
    vector<vector<bool>> visited;
    for(int i = 0; i < rows; i++){
        room.emplace_back();
        for(int j = 0; j < cols; j++){
            cin >> num;
            room[i].push_back(num);
            Coordinate coord{i, j};
            valueToCoord[num].push_back(coord);
        }
    }

    for(int i = 0; i < rows; i++){
        visited.emplace_back();
        for(int j = 0; j < cols; j++){
            visited[i].push_back(false);
        }
    }

//    for(int i = 0; i < rows; i++){
//        for(int j = 0; j < cols; j++){
//            cout << visited[i][j] << " ";
//        }
//        cout << endl;
//    }

    if(findEscape(room, visited, room.size()-1, room[0].size()-1, valueToCoord)){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}

