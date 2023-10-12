#include <iostream>
#include <stack>
using namespace std;


int main() {
    int tests, nCars, car;

    cin >> tests;
    for(int i = 0; i < tests; i++){
        stack<int> mountain;
        stack<int> branch;
        int lake = 0;
        cin >> nCars;
        for(int j = 0; j < nCars; j++){
            cin >> car;
            mountain.push(car);
        }
        while(true){
            if(branch.empty() && mountain.empty()){
                cout << "Y" << endl;
                break;
            }
            if(!branch.empty()){
                if(lake+1 == branch.top()){
                    lake++;
                    branch.pop();
                    continue;
                }
            }
            if(!mountain.empty()){
                if(lake+1 == mountain.top()){
                    lake++;
                    mountain.pop();
                    continue;
                } else {
                    branch.push(mountain.top());
                    mountain.pop();
                    continue;
                }
            }

            cout << "N" << endl;
            break;
        }
    }
    return 0;
}
