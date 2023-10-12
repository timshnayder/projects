#include <iostream>

using namespace std;

//int minimumCost(int stoneArray[], int stonesMax, unsigned long long total, int curStone, int shortestToStone[]){
//    if(curStone == stonesMax-1){
//        return 0;
//    }
//    if(curStone+2<=stonesMax-1){
//        int diff = abs(stoneArray[curStone+2] - stoneArray[curStone]);
//        int totalDiff = total+diff;
//        if(totalDiff < shortestToStone[curStone+2]|| shortestToStone[curStone+2] == -1){
//            shortestToStone[curStone+2] = totalDiff;
//            minimumCost(stoneArray, stonesMax, totalDiff, curStone+2, shortestToStone);
//        }
//    }
//    int diff = abs(stoneArray[curStone+1] - stoneArray[curStone]);
//    int totalDiff = total+diff;
//    if(totalDiff < shortestToStone[curStone+1] || shortestToStone[curStone+1] == -1){
//        shortestToStone[curStone+1] = totalDiff;
//        minimumCost(stoneArray, stonesMax, totalDiff, curStone+1, shortestToStone);
//    }
//
//
//    return shortestToStone[stonesMax-1];
//}

int minimumCost(int stoneArray[], int stonesMax, unsigned long long total, int shortestToStone[]){
    for(int curStone = 0; curStone < stonesMax-1; curStone++){
        if(curStone+2<=stonesMax-1){
            int diff = abs(stoneArray[curStone+2] - stoneArray[curStone]);
            int totalDiff = shortestToStone[curStone]+diff;
            if(totalDiff < shortestToStone[curStone+2]|| shortestToStone[curStone+2] == -1){
                shortestToStone[curStone+2] = totalDiff;
            }
        }
        int diff = abs(stoneArray[curStone+1] - stoneArray[curStone]);
        int totalDiff = shortestToStone[curStone]+diff;
        if(totalDiff < shortestToStone[curStone+1] || shortestToStone[curStone+1] == -1){
            shortestToStone[curStone+1] = totalDiff;
        }
    }
//    for(int i = 0; i < stonesMax; i++){
//        cout << shortestToStone[i] << " ";
//    }
//    cout << endl;
    return shortestToStone[stonesMax-1];
}

int main() {
    int stonesMax = 0, stoneInput;
    cin >> stonesMax;
    int stoneArray[stonesMax];
    int shortestToStone[stonesMax];

    for(int i = 0; i < stonesMax; i++){
        cin >> stoneInput;
        stoneArray[i] = stoneInput;
        shortestToStone[i] = -1;
    }
    shortestToStone[0] = 0;
    cout << minimumCost(stoneArray, stonesMax, 0, shortestToStone) << endl;

    return 0;
}