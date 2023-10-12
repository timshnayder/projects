#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cases;
    int max = 10;
    string phoneNumber;
    string phoneClean;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        max=10;
        phoneClean.clear();
        cin >> phoneNumber;
        for(int i = 0; i < max; i++){
            if(phoneNumber[i]== '-'){
                max++;
                continue;
            }
            phoneClean.push_back(phoneNumber[i]);
        }
        for(int i = 0; i < 10; i++){
            if(i == 3 || i ==  6){
                cout << "-";
            }
            if(phoneClean[i] >= '0' && phoneClean[i] <= '9'){
                cout << phoneClean[i];
                continue;
            }
            if(phoneClean[i] == 'A' || phoneClean[i] == 'B' || phoneClean[i] == 'C'){
                cout << "2";
            }
            if(phoneClean[i] == 'D' || phoneClean[i] == 'E' || phoneClean[i] == 'F'){
                cout << "3";
            }
            if(phoneClean[i] == 'G' || phoneClean[i] == 'H' || phoneClean[i] == 'I'){
                cout << "4";
            }
            if(phoneClean[i] == 'J' || phoneClean[i] == 'K' || phoneClean[i] == 'L'){
                cout << "5";
            }
            if(phoneClean[i] == 'M' || phoneClean[i] == 'N' || phoneClean[i] == 'O'){
                cout << "6";
            }
            if(phoneClean[i] == 'P' || phoneClean[i] == 'Q' || phoneClean[i] == 'R' || phoneClean[i] == 'S'){
                cout << "7";
            }
            if(phoneClean[i] == 'T' || phoneClean[i] == 'U' || phoneClean[i] == 'V'){
                cout << "8";
            }
            if(phoneClean[i] == 'W' || phoneClean[i] == 'X' || phoneClean[i] == 'Y'|| phoneClean[i] == 'Z'){
                cout << "9";
            }
        }
        cout << endl;
    }
    return 0;
}
