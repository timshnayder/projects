#include <iostream>
#include <vector>
using namespace std;

bool isYearDistinct(int year){
    vector<int> numberOfDigits = {0,0,0,0,0,0,0,0,0,0};
    while(year>0){
        int digit=year%10;
        year/=10;

        if(numberOfDigits[digit]>0){
            return false;
        }
        numberOfDigits[digit]++;
    }

    return true;
}

int main() {
    int startingYear;
    cin >> startingYear;

    for(int year = startingYear+1; ; year++){
        if(isYearDistinct(year)){
            cout << year << endl;
            break;
        }
    }

    return 0;
}
