#include <iostream>
using namespace std;

int main() {
    int delivered = 0;
    int colisions = 0;
    cin >> delivered >> colisions;
    int score = delivered * 50 + colisions * -10;
    if (delivered > colisions){
        score+=500;
    }
    cout << score << endl;
    return 0;
}
