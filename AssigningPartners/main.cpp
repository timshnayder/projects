#include <iostream>
#include <map>

using namespace std;

int main() {
    int peopleN;
    string person;
    cin >> peopleN;
    string top[peopleN], bot[peopleN];
    bool final = true;

    for(int i = 0; i < peopleN; i++){
        cin >> person;
        top[i] = person;
    }
    for(int i = 0; i < peopleN; i++){
        cin >> person;
        bot[i] = person;
    }



    for(int i = 0; i < peopleN; i++){
        string topPerson = top[i];
        string botPerson = bot[i];
        if(topPerson == botPerson){
            final = false;
            break;
        }
        for(int j = 0; j < peopleN; j++){
            if(top[j] == topPerson){
                if(bot[j] != botPerson){
                    final = false;
                    break;
                }
            } else if(bot[j] == botPerson){
                if(top[j] != topPerson){
                    final = false;
                    break;
                }
            } else if(top[j] == botPerson){
                if(bot[j] != topPerson){
                    final = false;
                    break;
                }
            } else if(bot[j] == topPerson){
                if(top[j] != botPerson){
                    final = false;
                    break;
                }
            }
        }
    }
    if(final){
        cout << "good" << endl;
    } else {
        cout << "bad" << endl;
    }
    return 0;
}
