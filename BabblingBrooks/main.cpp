#include <iostream>
#include <vector>

using namespace std;

int main() {
    //first input variable
    int numInitialStreams;
    vector<double> stream;
    double streamFlow;

    //joins and splits input variable
    int streamSplit;
    int streamJoined;
    double flowPercent;

    cin >> numInitialStreams;

    //initial streams
    for(int i = 0; i < numInitialStreams; i++){
        cin >> streamFlow;
        stream.push_back(streamFlow);
    }

    //joins and splits
    int action = 0;
    while(action != 77){
        cin >> action;
        if(action == 99){
            cin >> streamSplit >> flowPercent;
            stream.insert(stream.begin()+streamSplit, stream[streamSplit-1]*(1-(flowPercent/100)));
            stream[streamSplit-1] = stream[streamSplit-1]*(flowPercent/100);

        } else if(action == 88){
            cin >> streamJoined;
            stream[streamJoined-1] = stream[streamJoined-1] + stream[streamJoined];
            stream.erase(stream.begin() + streamJoined);
        }
    }

    //print
    for(unsigned int i = 0; i < stream.size(); i++){
        cout << stream[i];
        if(i!= stream.size()-1){
            cout << " ";
        }
    }
}
