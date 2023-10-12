#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> cities;
    string city;
    int tempe;
    string coldest = city;
    while(city != "Waterloo"){
        cin >> city >> tempe;
        cities.insert(pair<string, int>(city, tempe));
        if(tempe < cities[coldest]){
            coldest = city;
        }
    }
    cout << coldest << endl;
    return 0;
}
