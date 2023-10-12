#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CoordinateShift {
public:
    CoordinateShift(int _x, int _y) : x(_x), y(_y) {}
    int x, y;
};

int dfs(bool turned, vector<vector<char>>& board, string& word, int curRow, int curCol, int direction, int steps){

    CoordinateShift shifts[] = {
            CoordinateShift(-1, 0),
            CoordinateShift(-1, 1),
            CoordinateShift(0, 1),
            CoordinateShift(1, 1),
            CoordinateShift(1, 0),
            CoordinateShift(1, -1),
            CoordinateShift(0, -1),
            CoordinateShift(-1, -1)
    };
    //DIRECTION:
    // 0 = NORTH
    // 1 = NORTH EAST
    // 2 = EAST
    // 3 = SOUTH EAST
    // 4 = SOUTH
    // 5 = SOUTH WEST
    // 6 = WEST
    // 7 = NORTH WEST

    if(curRow < 0) return 0;
    if(curRow >= board.size()) return 0;
    if(curCol < 0) return 0;
    if(curCol >= board[0].size()) return 0;

    // Check if word was found
    if(board[curRow][curCol] != word[steps]){
        return 0;
    }

    if(steps == word.size()-1){
        return 1;
    }

    int nextSteps = 0;
    // Check if it's the first search and branch out into every possible direction
    if(steps == 0){
        for (int newDirection = 0; newDirection < 8; newDirection++) {
            auto& shift = shifts[newDirection];
            int nextRow = curRow+shift.x;
            int nextCol = curCol+shift.y;


            nextSteps += dfs(false, board, word, nextRow, nextCol, newDirection, 1);
        }
//        //NORTH
//        if(curRow != 0){
//            nextSteps += dfs(false, board, word, curRow-1, curCol, 1, 2);
//        }
//        //NORTH EAST
//        if(curRow != 0 || curCol != board[0].size()-1){
//            nextSteps += dfs(false, board, word, curRow-1, curCol+1, 2, 2);
//        }
//        //EAST
//        if(curCol != board[0].size()-1){
//            nextSteps += dfs(false, board, word, curRow, curCol+1, 3, 2);
//        }
//        //SOUTH EAST
//        if(curRow != board.size()-1 || curCol != board[0].size()-1){
//            nextSteps += dfs(false, board, word, curRow+1, curCol+1, 4, 2);
//        }
//        //SOUTH
//        if(curRow != board.size()-1){
//            nextSteps += dfs(false, board, word, curRow+1, curCol, 5, 2);
//        }
//        //SOUTH WEST
//        if(curRow != board.size()-1 || curCol != 0){
//            nextSteps += dfs(false, board, word, curRow+1, curCol-1, 6, 2);
//        }
//        //WEST
//        if(curCol != 0){
//            nextSteps += dfs(false, board, word, curRow, curCol-1, 7, 2);
//        }
//        //NORTH WEST
//        if(curRow != 0 || curCol != 0){
//            nextSteps += dfs(false, board, word, curRow-1, curCol-1, 8, 2);
//        }
    }

    //If it's not the first step,
    if(steps != 0){
        nextSteps += dfs(turned, board, word, curRow+shifts[direction].x, curCol+shifts[direction].y, direction, steps+1);
        if(!turned){
            nextSteps += dfs(true, board, word, curRow+shifts[(direction+2)%8].x, curCol+shifts[(direction+2)%8].y, (direction+2)%8, steps+1);
            nextSteps += dfs(true, board, word, curRow+shifts[(direction+6)%8].x, curCol+shifts[(direction+6)%8].y, (direction+6)%8, steps+1);
        }

    }
    return nextSteps;
}

int wordSearch(string word, vector<vector<char>>board){
    int total = 0;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == word[0]){
                total += dfs(false, board, word, i, j, 0, 0);
            }
        }
    }
    return total;
}

int main() {
    string word;
    cin >> word;
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> board;
    char letter;

    for(int i = 0; i < rows; i++){
        board.emplace_back();
        for(int j = 0; j < cols; j++){
            cin >> letter;
            board[i].emplace_back(letter);
        }
    }

    cout << wordSearch(word, board) << endl;

    return 0;
}
