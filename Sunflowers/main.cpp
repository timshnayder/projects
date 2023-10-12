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
   int curHeight;

   for(auto row : garden){
       curHeight = row[0];
       for(auto col: row){
           if(curHeight > col){
               return false;
           }
          curHeight = col;
       }
   }

   for(int i = 1; i < garden.size(); i++){
       if(garden[i][0] < garden[i-1][0]){
           return false;
       }
   }
   return true;
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
   if(check(garden)){
       print(garden);
       return 0;
   }
   for(int i = 0; i < 3; i++){
       rotate(garden, rows);
       if(check(garden)){
           print(garden);
           return 0;
       }
   }

   return 0;
}


