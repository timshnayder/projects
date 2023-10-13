#include <iostream>
#include <vector>
#define MAXNODES 100001
using namespace std;

class Node{
    int weight;
    vector<int> children;
};

class Tree{
private:
    vector<int> adjacency[10000];
public:
    vector<int> getNeighbours(int node){
        return adjacency[node];
    }
    void addEdge(int start, int end){
        adjacency[start].push_back(end);
    }
};

int pathMin(const Tree& tree, int start, int end){
    return 0;
}

int pathMax(){
    return 0;
}

int pathSum(Tree tree, int cur, int end, int sum, const int vertexWeights[]){
    for(auto neighbour: tree.getNeighbours(cur)){
        if(neighbour == end){
            return sum+vertexWeights[neighbour];
        }
        int res = pathSum(tree, neighbour, end, sum+vertexWeights[neighbour], vertexWeights);
        if(res!=0){
            return res;
        }else{
            continue;
        }
    }
    return 0;
}

int LCA(Tree tree, int x, int y){
    if(x == y){
        return x;
    }
}

int main() {
    Tree tree;

    int nVertices;
    cin >> nVertices;
    int nQueries;
    cin >> nQueries;

    int vertexWeights[nVertices+1];
    int vertexWeight;
    for(int i = 1; i < nVertices+1; i++){
        cin >> vertexWeight;
        vertexWeights[i] = vertexWeight;
    }

    int x, y;
    for(int i = 0; i < nVertices-1; i++){
        cin >> x >> y;
        tree.addEdge(x,y);
    }

    int root;
    cin >> root;

    int query;
    for(int i = 0; i < nQueries; i++){
        cin >> query;
        switch(query){
            case 0:
                cin >> root;
                continue;
            case 1:
                continue;
            case 2:
                continue;
            case 3:
                cin >> x >> y;
                cout << pathMin(tree, x, y) << endl;
                continue;
            case 4:
                cin >> x >> y;
                pathMax();
                continue;
            case 5:
                cin >> x >> y;
                cout << pathSum(tree, x, y, 0, vertexWeights) << endl;
                continue;
            case 6:
                continue;
            default:
                continue;
        }
    }
    return 0;
}
