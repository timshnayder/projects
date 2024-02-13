#include <iostream>
using namespace std;

int main() {
    int nWood;
    int wood;
    cin >> nWood;
    int lengths[2001];
    int pairsAtLength[4001];
    for(int i = 0; i <= 4000; i++){
        pairsAtLength[i] = 0;
    }
    for(int i = 0; i <= 2000; i++){
        lengths[i] = 0;
    }
    for(int i = 0; i < nWood; i++){
        cin >> wood;
        lengths[wood]++;
    }


    //count
    for(int i = 1; i <= 2000; i++){
        for(int j = i; j <= 2000; j++){
            if(i==j){
                pairsAtLength[i+j]+=lengths[i]/2;
            } else{
                pairsAtLength[i+j]+=min(lengths[i], lengths[j]);
            }
        }
    }


    int maxLength = 1;
    int maxHeights = 0;
    for(int i = 1; i <= 4000; i++){
        if(maxLength < pairsAtLength[i]){
            maxLength = pairsAtLength[i];
            maxHeights = 1;
        }
        else if(maxLength == pairsAtLength[i]){
            maxHeights++;
        }
    }
    cout << maxLength << " " << maxHeights << endl;
    return 0;
}