#include <iostream>
#include <vector>
#define MAXNODES 100001
using namespace std;


class Tree{
private:
    vector<int> adjacency[MAXNODES];
public:
    const vector<int>& getNeighbours(int node)const{
        return adjacency[node];
    }
    void addEdge(int node, int neighbour){
        adjacency[node].push_back(neighbour);
    }
};

int pathMin(const Tree& tree, int start, int end){

}

int pathMax(){

}

int pathSum(const Tree& tree, int cur, int end, int sum, const int vertexWeights[], int shortestDist[]){
    for(auto neighbour: tree.getNeighbours(cur)){
        shortestDist[neighbour] = shortestDist[cur]+ vertexWeights[neighbour];
        if(neighbour == end){
            return sum+vertexWeights[neighbour];
        }
        int res = pathSum(tree, neighbour, end, sum+=vertexWeights[neighbour], vertexWeights, shortestDist);
        if(res!=0){
            return res;
        }else{
            continue;
        }
    }
    return 0;
}

int main() {
    Tree tree;

    int nVertices;
    cin >> nVertices;

    int vertexWeights[nVertices];
    int vertexWeight;
    for(int i = 0; i < nVertices; i++){
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

    int shortestDist[nVertices+1];
    int nQueries;
    cin >> nQueries;
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
                shortestDist[x] = 0;
                cout << pathSum(tree, x, y, 0, vertexWeights, shortestDist) << endl;
                cout << shortestDist[y];
                continue;
            case 6:
                continue;
            default:
                continue;
        }
    }
    return 0;
}
