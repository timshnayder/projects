#include <iostream>
#include <vector>
using namespace std;

//7
//0 0 1 0 1 0 0
//0 0 1 1 0 1 0

int findEdgeSize(int triT){
    if(triT == 3){
        return 0;
    } else if(triT == 2){
        return 1;
    } else if(triT == 1){
        return 2;
    } else if(triT == 0){
        return 3;
    }
}

int main() {
    int columns;
    int tile;
    cin >> columns;
    int tape = 0;
    vector<int> top;
    vector<int> bottom;
    for(int i = 0; i < columns; i++){
        cin >> tile;
        top.push_back(tile);
    }
    for(int i = 0; i < columns; i++){
        cin >> tile;
        bottom.push_back(tile);
    }

    //Find edges of top
    for(int i = 0; i < top.size(); i++){
        int tri = top[i];
        if(tri == 1){
            int triT = 0;
            int triB = bottom[i];
            if(i > 0){
                //Not left side
                int triL = top[i-1];
                if(i < top.size()-1){
                    //In the middle
                    int triR = top[i+1];
                    if(i%2 == 1){
                        triT = triR+triL;
                    }else{
                        triT = triR+triB+triL;
                    }
                    tape+=findEdgeSize(triT);
                } else {
                    //Right side
                    if(i%2 == 1){
                        triT = triL;
                    }else{
                        triT = triB+triL;
                    }
                    tape+=findEdgeSize(triT);
                }
            } else {
                //Left side
                int triR = top[i+1];
                triT = triR+triB;
                tape+=findEdgeSize(triT);
            }
        }
    }

    for(int i = 0; i < bottom.size(); i++){
        int tri = bottom[i];
        if(tri == 1){
            int triT = 0;
            int triB = top[i];
            if(i > 0){
                //Not left side
                int triL = bottom[i-1];
                if(i < bottom.size()-1){
                    //In the middle
                    int triR = bottom[i+1];
                    if(i%2 == 1){
                        triT = triR+triL;
                    }else{
                        triT = triR+triB+triL;
                    }
                    tape+=findEdgeSize(triT);
                } else {
                    //Right side
                    if(i%2 == 1){
                        triT = triL;
                    }else{
                        triT = triB+triL;
                    }
                    tape+=findEdgeSize(triT);
                }
            } else {
                //Left side
                int triR = bottom[i+1];
                triT = triR+triB;
                tape+=findEdgeSize(triT);
            }
        }
    }
    //Find edges of bottom
//    for(int i = 0; i < bottom.size(); i++){
//        int tri = bottom[i];
//        if(tri == 1) {
//            int triT = 0;
//            int triA = top[i];
//            if (i > 0) {
//                //Not left side
//                int triL = bottom[i - 1];
//                if (i < bottom.size() - 1) {
//                    //In the middle
//                    int triR = bottom[i + 1];
//                    triT = triR + triA + triL;
//                    tape += findEdgeSize(triT);
//                } else {
//                    //Right side
//                    triT = triL + triA;
//                    tape += findEdgeSize(triT);
//                }
//            } else {
//                //Left side
//                int triR = bottom[i + 1];
//                triT = triR + triA;
//                tape += findEdgeSize(triT);
//            }
//        }
//    }

    cout << tape << endl;
    return 0;
}
