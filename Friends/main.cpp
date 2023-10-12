#include <iostream>
#include <vector>
#include <queue>
#define MAXNODES 10000

using namespace std;



class Graph{
public:
    vector<int> adjacency[MAXNODES];
    [[nodiscard]] vector<int> getNeighbours(int index)const{
        return adjacency[index];
    }
    void addEdge(const int from, const int to){
        adjacency[from].push_back(to);
    }
};

void findSeparation(const Graph& graph, int from, int to, int numStudents){
    queue<int> q;
    int distance = -1;
    q.push(from);
    bool visited[numStudents+1];
    for(int i = 0; i < numStudents+1;i++){
        visited[i] = false;
    }
    visited[from] = true;
    while(!q.empty()){
        const int current = q.front();
        q.pop();
        for(int neighbour: graph.getNeighbours(current)){
            if(neighbour == to){
                distance++;
                cout << "Yes " << distance << endl;
                return;
            }
            if(visited[neighbour])continue;else{
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
        distance++;
    }
    cout << "No" << endl;
}

int main() {
    int numStudents, from, to;
    Graph graph;
    cin >> numStudents;
    for(int i = 0; i < numStudents; i++){
        cin >> from >> to;
        graph.addEdge(from, to);
    }
    cin >> from >> to;
    while(from != 0){
        findSeparation(graph, from, to, numStudents);
        cin >> from >> to;
    }
    return 0;
}
