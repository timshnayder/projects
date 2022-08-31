#include <iostream>
using namespace std;

int main() {
    int numOfLargeBoxes;
    int numOfSmallBoxes;
    cin >> numOfLargeBoxes >> numOfSmallBoxes;
    cout << (numOfLargeBoxes*8+numOfSmallBoxes*3)-28 << endl;
    return 0;
}
