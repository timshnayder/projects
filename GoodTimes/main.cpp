#include <iostream>
using namespace std;

int calculateTime(int time, int timeDifference){
    int result = time+timeDifference;
    if(result%100>59){
        result+=40;

    }
    if(result < 0){
        result+=2400;
    }
    if(result>=2400){
        result-=2400;
    }

    return result;
}

int main() {
    int timeInOttawa;
    cin >> timeInOttawa;

    cout << calculateTime(timeInOttawa, 0) << " in Ottawa" << endl;
    cout << calculateTime(timeInOttawa,-300) << " in Victoria" << endl;
    cout << calculateTime(timeInOttawa, -200) << " in Edmonton" << endl;
    cout << calculateTime(timeInOttawa, -100) << " in Winnipeg" << endl;
    cout << calculateTime(timeInOttawa, 0) << " in Toronto" << endl;
    cout << calculateTime(timeInOttawa, 100) << " in Halifax" << endl;
    cout << calculateTime(timeInOttawa, 130) << " in St. John's" << endl;
    return 0;
}
