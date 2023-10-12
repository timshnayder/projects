#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> garden){
    for(auto row: garden){
        for(auto col: row){
            cout << col << " ";
        }
        cout << "\n";
    }
}

bool check(vector<vector<int>> garden){
    bool state = true;

    for(auto row : garden){
        for(auto col: row){

        }
    }

    return state;
}

void rotate(vector<vector<int>>& garden, int rows){
    vector<vector<int>> tempVec = garden;
    for(int i = 0; i < garden.size(); i++){
        for(int j = 0; j < garden[0].size(); j++){
            garden[i][j] = tempVec[j][rows-1-i];
        }
    }
}
int main() {
    vector<vector<int>> garden;
    int rows, flowerHeight;
    cin >> rows;
    for(int i = 0; i < rows; i++){
        garden.emplace_back();
        for(int j = 0; j < rows; j++){
            cin >> flowerHeight;
            garden[i].push_back(flowerHeight);
        }
    }
    print(garden);
    rotate(garden, rows);
    print(garden);
    return 0;
}


