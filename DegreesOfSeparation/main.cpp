#include <iostream>
#include <queue>
#include <set>

using namespace std;

set<int> friends[50] = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}};

int bfs(int start, int end){
    int shortestDistance[50];
    for(int & i : shortestDistance){
        i = -1;
    }
    shortestDistance[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto fr: friends[current]){
            if(shortestDistance[fr]!=-1){
                continue;
            }
            q.push(fr);
            shortestDistance[fr] = shortestDistance[current]+1;
            if(fr == end){
                return shortestDistance[end];
            }
        }

    }
    return -1;
}

int friendsOfFriends(int start){
    int shortestDistance[50];
    for(int & i : shortestDistance){
        i = -1;
    }
    int total = 0;
    shortestDistance[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto fr: friends[current]){
            if(shortestDistance[fr]!=-1){
                continue;
            }
            q.push(fr);
            shortestDistance[fr] = shortestDistance[current]+1;
        }

    }
    for(int i : shortestDistance){
        if(i == 2){
            total++;
        }
    }
    return total;
}

int main() {
    char command;
    int x, y;

    cin >> command;
    while(command!='q'){
        if(command == 'i'){
            cin >> x >> y;
            friends[x].insert(y);
            friends[y].insert(x);
        } else if(command == 'd'){
            cin >> x >> y;
            friends[x].erase(y);
            friends[y].erase(x);
        } else if(command == 'n'){
            cin >> x;
            cout << friends[x].size() << endl;
        } else if(command == 'f'){
            cin >> x;
            cout << friendsOfFriends(x) << endl;
        } else if(command == 's'){
            cin >> x >> y;
            int distance = bfs(x, y);
            if(distance != -1){
                cout << distance << endl;
            } else {
                cout << "Not connected" << endl;
            }
        }
        cin >> command;
    }
    return 0;
}