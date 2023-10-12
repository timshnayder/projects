#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int>& arr, int len){
    for(int j = 1; j < len; j++){
        for(int i = 1; i < len-j+1; i++){
            if(arr[i]<arr[i-1]){
                swap(arr[i], arr[i-1]);
            }
        }
    }
}

int main() {
    vector<int> chores;
    int minAvail, choresN, chore;
    int total = 0;
    cin >> minAvail >> choresN;
    for(int i = 0; i < choresN; i++){
        cin >> chore;
        chores.push_back(chore);
    }
    bubbleSort(chores, choresN);
//    for(auto x: chores){
//        cout << x << " ";
//    }
    for(int i = 0; i < choresN; i++){
        if(minAvail - chores[i] >= 0){
            minAvail-=chores[i];
            total++;
        } else {
            break;
        }
    }
    cout << total << endl;
    return 0;
}
