#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Graph{
private:
    vector<int> adjacency[10001];

public:
    bool endingPages[10001];
    [[nodiscard]] const vector<int>& getNeighbours(int index)const{
        return adjacency[index];
    }
    void addEdge(const int from, const int to){
        adjacency[from].push_back(to);
    }
};

void bfs(const Graph& graph, int pages){
    queue<int> q;
    int steps[pages+1];
    for(int i = 0 ; i < pages+1; i++){
        steps[i] = 0;
    }
    q.push(1);
    steps[1] = 1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int neighbour: graph.getNeighbours(current)){
            if(steps[current]+1 < steps[neighbour] || steps[neighbour] == 0){
                q.push(neighbour);
                steps[neighbour] = steps[current]+1;
            }
        }
    }
    long long fastestEnd = INT64_MAX;
    bool allVisitable = true;
    for(int i = 1; i <= pages; i++){
        if(steps[i] == 0){
            allVisitable = false;
        }
        if(graph.endingPages[i] && steps[i] < fastestEnd && steps[i] != 0){
            fastestEnd = steps[i];
        }
    }
    if(allVisitable){
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }

    cout << fastestEnd << endl;
}

int main() {
    int numPages, numOptions, option;
    Graph graph;
    cin >> numPages;
    for(int i = 1; i <= numPages; i++){
        cin >> numOptions;
        if(numOptions == 0){
            graph.endingPages[i] = true;
        }
        for(int j = 0; j < numOptions; j++){
            cin >> option;
            graph.addEdge(i, option);
        }

    }
    bfs(graph, numPages);
    return 0;
}
