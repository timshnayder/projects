#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

//WIP DOESN'T WORK

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

bool can_escape(int M, int N, vector<std::vector<int>> v){
    queue<Coordinate> q;
    map<int, vector<Coordinate>> valueToCoord;
    vector<vector<bool>> visited;
    for(int i = 1; i < M+1; i++){
        for(int j = 1; j < N+1; j++){
            Coordinate coord{i, j};
            valueToCoord[v[i][j]].push_back(coord);
        }
    }
    for(int i = 0; i < M+1; i++){
        visited.emplace_back();
        for(int j = 0; j < N+1; j++){
            visited[i].push_back(false);
        }
    }
    Coordinate end{M, N};
    q.push(end);

    while (!q.empty()) {
        Coordinate& current = q.front();
        q.pop();
        if (current.row == 1 && current.col == 1) {
            return true;
        }
        if (visited[current.row][current.col]) {
            continue;
        }
        visited[current.row][current.col] = true;
        vector<Coordinate>& coord = valueToCoord[(current.row)*(current.col)];
        for (Coordinate& cell: coord) {
            q.push(cell);
        }
    }
    return false;
}

int main() {
    int rows, cols, num;
    cin >> rows >> cols;
    vector<vector<int>> v;
    for(int i = 0; i < rows+1; i++){
        v.emplace_back();
        for(int j = 0; j < cols+1; j++){
            cin >> num;
            v[i].push_back(num);
        }
    }

    if(can_escape(rows, cols, v)){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}


/*
 * #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

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

bool can_escape(int M, int N, vector<std::vector<int>> v){
    queue<Coordinate> q;
    int num;
    map<int, vector<Coordinate>> valueToCoord;
    vector<vector<int>> room;
    vector<vector<bool>> visited;
    for(int i = 0; i < M; i++){
        room.emplace_back();
        for(int j = 0; j < N; j++){
            cin >> num;
            room[i].push_back(num);
            Coordinate coord{i, j};
            valueToCoord[num].push_back(coord);
        }
    }

    for(int i = 0; i < M; i++){
        visited.emplace_back();
        for(int j = 0; j < N; j++){
            visited[i].push_back(false);
        }
    }
    Coordinate end{static_cast<int>(room.size()-1), static_cast<int>(room[0].size()-1)};
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
    vector<vector<int>> v;


//    for(int i = 0; i < rows; i++){
//        for(int j = 0; j < cols; j++){
//            cout << visited[i][j] << " ";
//        }
//        cout << endl;
//    }

    if(can_escape(rows, cols, v)){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
 */