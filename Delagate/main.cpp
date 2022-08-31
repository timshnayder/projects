#include <iostream>
#include <string>

using namespace std;

class Player{
    public:
        string name;
        Player(string name_val) : Player(){
            cout << "one aregs called" << endl;
        }

        Player() : Player("fred"){
            cout << "no args called" << endl;
        }
};

int main() {
    Player fred;
    return 0;
}
