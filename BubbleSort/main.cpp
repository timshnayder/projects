#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int list[], int listLength){
    for(int k = 0; k < listLength; k++){
        cout << list[k];
        if(k < listLength-1){
            cout << " ";
        }else {
            cout << endl;
        }
    }
    for(int i = 0; i < listLength; i++){
        for(int j = 0; j < listLength - i - 1; j++){
            if(list[j] > list[j+1]){
                swap(list[j], list[j+1]);
                for(int k = 0; k < listLength; k++){
                    cout << list[k];
                    if(k < listLength-1){
                        cout << " ";
                    } else {
                        cout << endl;
                    }

                }
            }
        }
    }
}

int main() {
    int listLength , value;
    cin >> listLength;
    int list[listLength];
    for(int i = 0; i < listLength; i++){
        cin >> value;
        list[i] = value;
    }
    bubbleSort(list, listLength);
    return 0;
}
