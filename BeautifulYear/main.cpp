#include <iostream>
using namespace std;

int main() {
    int year;
    int nums[10] = {0,0,0,0,0,0,0,0,0,0};
    cin >> year;
    bool badYear = false;

    int curYear = year+1;
    while(true){
        fill(nums,nums+10,0);
        badYear=false;
        nums[curYear/1000]++;
        nums[(curYear/100)%10]++;
        nums[(curYear/10)%10]++;
        nums[curYear%10]++;
        for(int i = 0; i < 10; i++){
            if(nums[i]>=2){
                curYear++;
                badYear=true;
            }
        }

        if(badYear){
            continue;
        }
        cout << curYear << endl;
        break;
    }
    return 0;
}
