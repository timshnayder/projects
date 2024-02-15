#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestDist[100][100];
char grid[100][100];

void bfs(int startR, int startC){
    queue<pair<int,int>> q;
    int steps = -1;
    q.push({startR, startC});
    while(!q.empty()){
        steps++;
        q.pop();
        pair<int,int> v = q.front()
        //handle conveyors by moving to the next location regardless of walls and other conveyors
        //THEN checking if it is

        if(grid[v.first][v.second] == 'U'){
            q.push({v.first+1, v.second});
            continue;
        } else if(grid[v.first][v.second] == 'R'){
            q.push({v.first, v.second+1});
            continue;
        } else if(grid[v.first][v.second] == 'D'){
            q.push{v.first-1, v.second});
            continue;
        } else if(grid[v.first][v.second] == 'L'){
            q.push({v.first, v.second-1});
            continue;
        }
        //DIST ADDING AFTER CONVEYOR BECAUSE CONVEYOR DOESNT ADD STEP
        shortestDist[v.first][v.second]=steps;

        pair<int,int> vU = {v.first+1,v.second};
        pair<int,int> vD = {v.first-1,v.second};
        pair<int,int> vL = {v.first,v.second-1};
        pair<int,int> vR = {v.first,v.second+1};
        if(grid[vU.first][vU.second] != 'W' && grid[vU.first][vU.second] == -1){
            q.push(vU);
        }

        q.push(vD);
        q.push(vL);
        q.push(vR);

    }
}

int main() {
    int n,m;
    cin >> n >> m;
    char gridSpace;
    int startRow, startCol;
    vector<pair<int,int>> endLocations;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cin >> gridSpace;
            grid[i][j] = gridSpace;
            if(gridSpace == 'S'){
                startRow = i;
                startCol = j;
            }else if(gridSpace == '.'){
                endLocations.push_back({i,j});
            }
            shortestDist[i][j] = -1;
        }
    }

    //calculate for cameras
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'C') {
                //All the way up
                for (int k = 1;; k++) {
                    if (grid[i + k][j] == 'W') {
                        break;
                    } else if(grid[i+k][j] == '.'){
                        grid[i+k][j] = 'W';
                    }
                }
                //All the way down
                for (int k = 1;; k++) {
                    if (grid[i - k][j] == 'W') {
                        break;
                    } else if(grid[i-k][j] == '.'){
                        grid[i-k][j] = 'W';
                    }
                }
                //All the way left
                for (int k = 1;; k++) {
                    if (grid[i][j-k] == 'W') {
                        break;
                    } else if(grid[i][j-k] == '.'){
                        grid[i][j-k] = 'W';
                    }
                }
                //All the way right
                for (int k = 1;; k++) {
                    if (grid[i][j+k] == 'W') {
                        break;
                    } else if(grid[i][j+k] == '.'){
                        grid[i][j+k] = 'W';
                    }
                }
            }
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    //search
    bfs(startRow, startCol);


    //output
    for(auto location: endLocations){
        cout << shortestDist[location.first][location.second] << endl;
    }

    return 0;
}