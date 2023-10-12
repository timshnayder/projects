#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {
    string interested1;
    array<int, 5> dayAvai = {0,0,0,0,0};
    getline(cin, interested1);
    int interested = stoi(interested1);
    for(int i = 0; i < interested; i++){
        string avai;
        getline(cin, avai);
        for(int i = 0; i < 5; i++){
            char day = avai[i];
            if(day == 'Y'){
                dayAvai[i]++;
            }
        }
    }
    int bestDay = 0;
    int mostAttend = dayAvai[0];
    for(int i = 0; i < 5; i++){
        if(dayAvai[i] > mostAttend){
            bestDay = i;
            mostAttend = dayAvai[i];
        }
    }
    bestDay++;
    cout << bestDay;
    for(int i = 0; i < 5; i++){
        if(i != bestDay-1 && dayAvai[i]==mostAttend){
            cout << "," << i+1;
        }
    }

    return 0;
}
