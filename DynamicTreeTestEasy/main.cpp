#include <iostream>
#include <vector>
#define MAXNODES 100001
using namespace std;

class Node{
public:
    int weight;
};

class Graph{
public:
    vector<Node> adjacency[MAXNODES];
    const vector<Node>& getNeighbours(int node)const{
        return adjacency[node];
    }
    void addEdge(int node, int neighbour, int weight){
        Node n{weight, neighbour};
        adjacency[node].push_back(n);
    }
};

int pathMin(const Graph& graph, Node curNode, Node end, int shortestDist[]){

}

int pathMax(){

}

int pathSum(){

}

int main() {
    int nVertices,  nQueries, query, vertexWeight;
    Graph graph;

    for(int i = 0; i < nVertices; i++){
        cin >> vertexWeight;
        Node n{vertexWeight};
        graph.adjacency[i] = n;
    }
    int x, y;
    for(int i = 0; i < nVertices-1; i++){
        cin >> x >> y;
        graph.addEdge(x,y)
    }
    int root;
    cin >> root;
    int shortestDist[nVertices+1];
    for(int i = 0; i < nQueries; i++){
        cin >> query;
        switch(query){
            case 0:
                continue;
            case 1:
                continue;
            case 2:
                continue;
            case 3:
                cin >> x >> y;
                pathMin(graph);
                continue;
            case 4:
                cin >> x >> y;
                pathMax();
                continue;
            case 5:
                cin >> x >> y;
                pathSum();
                continue;
            case 6:
                continue;
            default:
                continue;
        }
    }
    return 0;
}
