#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> friends = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}};

int bfs(int start, int end){
    int shortestDistance[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    shortestDistance[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i = 0; i < friends[current].size(); i++){
            int fr = friends[current][i];
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
    int shortestDistance[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int total = 0;
    shortestDistance[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(unsigned int i = 0; i < friends[current].size(); i++){
            int fr = friends[current][i];
            if(shortestDistance[fr]!=-1){
                continue;
            }
            q.push(fr);
            shortestDistance[fr] = shortestDistance[current]+1;
        }

    }
    for(int i = 0; i < 19; i++){
        if(shortestDistance[i] == 2){
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
            friends[x].push_back(y);
            friends[y].push_back(x);
        } else if(command == 'd'){
            cin >> x >> y;
            for(int i = 0; i < friends[x].size(); i++){
                if(friends[x][i] == y){
                    friends[x].erase(friends[x].begin()+i);
                }
            }
            for(int i = 0; i < friends[y].size(); i++){
                if(friends[y][i] == x){
                    friends[y].erase(friends[y].begin()+i);
                }
            }
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
