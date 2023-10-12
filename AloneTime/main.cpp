#include <iostream>
#include <utility>

using namespace std;

void calculateLongestTime(const int classList[], int classes, int stayMin, int classDelayMin, pair<int, int> locationLongest, int longestAlone){
    int newLongest = longestAlone;
    int classSec = classList[locationLongest.second];
    int classFir = classList[locationLongest.first];
    if (classSec + classDelayMin > stayMin) {
        if (stayMin - classFir > longestAlone) {
            newLongest = stayMin - classFir;
        }

    } else if (classSec-1 + classDelayMin - classFir > longestAlone) {
        newLongest = classSec-1 + classDelayMin - classFir;
    }

    if (classFir - classDelayMin < 0) {
        if (classSec-1 > longestAlone && classSec > newLongest) {
            newLongest = classSec-1;
        }
    } else if (classSec-1 -(classFir - classDelayMin) > longestAlone && classSec-1 - (classFir - classDelayMin) > newLongest) {
        newLongest = classSec-1 - (classFir - classDelayMin);
    }

    cout << newLongest << endl;
}

int main() {
    int classes, stayMin, classDelayMin;

    cin >> classes >> stayMin >> classDelayMin;
    pair<int, int> locationLongest;

    int longestAlone = 0;
    int classList[classes];
    int classWalkTime;
    for(int i = 0; i < classes; i++){
        cin >> classWalkTime;
        classList[i] = classWalkTime;
        if(classList[i] - classList[i-1] > longestAlone){
            longestAlone = classList[i] - classList[i-1]-1;
            locationLongest.first = i-1;
            locationLongest.second = i;
        }
    }
    if(stayMin-classList[classes-1] > longestAlone){
        longestAlone = stayMin-classList[classes-1];
        locationLongest.first = stayMin;
        locationLongest.second = classes-1;
    }

    if(classList[0] > longestAlone){
        longestAlone = classList[0]-1;
        locationLongest.first = stayMin;
        locationLongest.second = classes-1;
    }

    calculateLongestTime(classList, classes, stayMin, classDelayMin, locationLongest, longestAlone);


    return 0;
}