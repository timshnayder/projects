#include <iostream>
#include <string>
using namespace std;
int main() {
    int total = 0;
    string numPep1;
    getline(cin, numPep1);
    int numPep2 = stoi(numPep1);
    for(int i = 0; i < numPep2; i++){
        string pepper;
        getline(cin, pepper);
        if(pepper == "Poblano"){
            total+=1500;
        }
        if(pepper == "Mirasol"){
            total+=6000;
        }
        if(pepper == "Serrano"){
            total+=15500;
        }
        if(pepper == "Cayenne"){
            total+=40000;
        }
        if(pepper == "Thai"){
            total+=75000;
        }
        if(pepper == "Habanero"){
            total+=125000;
        }
    }
    cout << total << endl;
    return 0;
}
