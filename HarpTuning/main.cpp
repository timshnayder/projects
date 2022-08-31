#include <iostream>
#include <string>

using namespace std;

int main() {
    string harpTuning;
    cin >> harpTuning;

    for(unsigned i = 0; i < harpTuning.length(); i++){
        if(harpTuning[i] >= 65 && harpTuning[i] <= 122){
            if(i>0 && harpTuning[i-1] > 47 && harpTuning[i-1] < 58){
                cout << endl;
            }
            cout << harpTuning[i];
        } else if(harpTuning[i] == '+'){
            cout << " tighten ";
        } else if(harpTuning[i] == '-'){
            cout << " loosen ";
        } else if (harpTuning[i] > 47 && harpTuning[i] < 58){
            cout << harpTuning[i];
        }
    }

    return 0;
}
