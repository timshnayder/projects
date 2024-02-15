#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
    ll n, m, k;
    // n = number of notes
    // m = max pitch
    // k = number of good samples

    cin >> n >> m >> k;
    ll music[n];
    for(ll i = 0; i < n; i++){
        //plan
        /*
         * Build up music until only putting distinct numbers
         * 1 2 3 1 1 1 1
         */
        // 1 2 3: GOOD SAMPLES = SUM OF NUMBERS = 6
        ll remaining = n-i-1; // Number of remaining notes
        ll current = min(m,k-remaining);
        if(current<=0){
            break;
        }
        ll val;
        if(current>i){
            val = min(m, i+1);
            current = val;
        }else{
            val = music[i-current];
        }
        music[i] = val;
        k-=current;
    }
    if(k==0 && music[n-1]!=-1){
        for(int i = 0; i < n; i++){
            cout << music[i] << " ";
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}