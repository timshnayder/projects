#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll music[n];
    music[n-1] = -1;

    for(int i = 0; i < n; i++){
        //plan
        /*
         * Build up music until only putting distinct numbers
         * 1 2 3 1 1 1 1
         */
        // 1 2 3: GOOD SAMPLES = SUM OF NUMBERS
        ll remaining = n-i-1;
        ll current = min(m,k-remaining);
        ll val;
        if(current>i){
            val = min(m, (ll)i+1);
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