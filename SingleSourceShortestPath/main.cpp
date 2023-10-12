#include <iostream>
#include <vector>
#include <queue>
#define MAXNODES 1001

using namespace std;

class Node{
public:
    int weight;
    int neighbour;
};

class Graph{
private:
    vector<Node> adjacency[MAXNODES];
public:
    const vector<Node>& getNeighbours(int node)const{
        return adjacency[node];
    }
    void addEdge(int node, int neighbour, int weight){
        Node n{weight, neighbour};
        adjacency[node].push_back(n);
    }
};

void findShortestPathDFS(const Graph& graph, int currentNode, int shortestDist[]){
    for(const auto& neighbour: graph.getNeighbours(currentNode)){
        if(shortestDist[neighbour.neighbour] == -1 || shortestDist[neighbour.neighbour] > shortestDist[currentNode]+neighbour.weight){
            shortestDist[neighbour.neighbour] = shortestDist[currentNode]+neighbour.weight;
            findShortestPathDFS(graph, neighbour.neighbour,  shortestDist);
        }
    }
}

void findShortestPathBFS(const Graph& graph, int shortestDist[]){
    priority_queue<int> q;
    q.push(1);

    while(!q.empty()){
        int currentNode = q.top();
        q.pop();
        for(const auto& neighbour: graph.getNeighbours(currentNode)){
            if(shortestDist[neighbour.neighbour] == -1 || shortestDist[neighbour.neighbour] > shortestDist[currentNode]+neighbour.weight){
                shortestDist[neighbour.neighbour] = shortestDist[currentNode]+neighbour.weight;
                q.push(neighbour.neighbour);
            }
        }
    }
}

int main() {
    int vertices, edges, from, to, weight;

    Graph graph;
    cin >> vertices >> edges;
    int shortestDist[vertices+1];

    for(int i = 1; i <= edges; i++){
        cin >> from >> to >> weight;
        graph.addEdge(from, to, weight);
        graph.addEdge(to, from, weight);
    }

    for(int i = 1; i <= vertices; i++){
        shortestDist[i] = -1;
    }
    shortestDist[1] = 0;

    findShortestPathBFS(graph, shortestDist);

    for(int i = 1; i <= vertices; i++){
        cout << shortestDist[i] << endl;
    }

    return 0;
}
