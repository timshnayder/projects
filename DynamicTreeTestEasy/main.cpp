#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <unordered_map>

using namespace std;

class Node{
public:
    Node():weight(0), index(0), eulerTourIndex(0), firstEulerAppearance(-1), parent(nullptr){

    }
    int weight;
    int index;
    int eulerTourIndex;
    int firstEulerAppearance;
    Node* parent;
    unordered_map<int, Node*> neighbours;
};

class Tree{
private:
    Node* root;
    Node* nodes;
    int numberOfVertices;
    vector<int> eulerTour;
    vector<int> eulerIndexToNodeIndex;
    int eulerTourIndex;
    void setParent(Node* node, Node* parent);
    void buildRMQTables();
    vector<int> logTable;
    vector<vector<int>> sparseTable;
public:
    Tree(int nVertices):root(nullptr), nodes(new Node[nVertices]), numberOfVertices(nVertices), eulerTourIndex(0){

    }
    ~Tree(){
        delete[] nodes;
    }

    void addNode(int nodeIndex, int weight){
        Node& n = nodes[nodeIndex-1];
        n.weight = weight;
        n.index = nodeIndex;
    }
    void addEdge(int firstIndex, int secondIndex){
        Node& firstNode = nodes[firstIndex - 1];
        Node& secondNode = nodes[secondIndex - 1];
        firstNode.neighbours[secondIndex] = &secondNode;
        secondNode.neighbours[firstIndex] = &firstNode;
    }

    void changeParent(int nodeIndex, int newParentIndex){
        //Remove this child from old parent and remove parent from child
        Node* node = &nodes[nodeIndex-1];
        if(node->parent!= nullptr){
            node->parent->neighbours.erase(nodeIndex);
            node->neighbours.erase(node->parent->index);
        }

        //Connect node and new parent
        addEdge(nodeIndex, newParentIndex);

        //Change nodes parent to new parent
        Node* newParent = &nodes[newParentIndex-1];
        node->parent = newParent;
        setRoot(root->index);
    }

    void setRoot(int rootIndex);
    Node* LCA(int start, int end);

    void updatePath(int start, int end, int weight);
    void incrementPath(int start, int end, int weight);
    int minPath(int start, int end);
    int maxPath(int start, int end);
    int sumPath(int start, int end);
};
//Query = 1
void Tree::updatePath(int start, int end, int weight) {
    Node* lca = LCA(start, end);
    Node* node = &nodes[start-1];
    while(node!=lca){
        node->weight = weight;
        node = node->parent;
    }
    node = &nodes[end-1];
    while(node!=lca){
        node->weight = weight;
        node = node->parent;
    }
    lca->weight=weight;
}

//Query = 2
void Tree::incrementPath(int start, int end, int weight) {
    Node* lca = LCA(start, end);
    Node* node = &nodes[start-1];
    while(node!=lca){
        node->weight += weight;
        node = node->parent;
    }
    node = &nodes[end-1];
    while(node!=lca){
        node->weight += weight;
        node = node->parent;
    }
    lca->weight+=weight;
}

//Query = 3
int Tree::minPath(int start, int end) {
    Node* lca = LCA(start, end);
    int min = lca->weight;
    Node* node = &nodes[start-1];
    while(node!=lca){
        if(node->weight<min){
            min = node->weight;
        }
        node = node->parent;
    }
    node = &nodes[end-1];
    while(node!=lca){
        if(node->weight<min){
            min = node->weight;
        }
        node = node->parent;
    }
    return min;
}

//Query = 4
int Tree::maxPath(int start, int end) {
    Node* lca = LCA(start, end);
    int max = lca->weight;
    Node* node = &nodes[start-1];
    while(node!=lca){
        if(node->weight>max){
            max = node->weight;
        }
        node = node->parent;
    }
    node = &nodes[end-1];
    while(node!=lca){
        if(node->weight>max){
            max = node->weight;
        }
        node = node->parent;
    }
    return max;
}

//Query = 5
int Tree::sumPath(int start, int end) {
    Node* lca = LCA(start, end);
    int sum = lca->weight;
    Node* node = &nodes[start-1];
    while(node!=lca){
        sum += node->weight;
        node = node->parent;
    }
    node = &nodes[end-1];
    while(node!=lca){
        sum += node->weight;
        node = node->parent;
    }
    return sum;
}

void Tree::setParent(Node* node, Node *parent) {
    if(node->firstEulerAppearance == -1){
        node->firstEulerAppearance = eulerTour.size();
        node->eulerTourIndex = eulerTourIndex++;
        eulerIndexToNodeIndex.push_back(node->index);
    }
    eulerTour.push_back(node->eulerTourIndex);
    node->parent = parent;
    for(auto neighbour: node->neighbours){
        if(neighbour.second!=parent){
            setParent(neighbour.second, node);
            eulerTour.push_back(node->eulerTourIndex);
        }
    }
}

void Tree::setRoot(int rootIndex) {
    eulerTour.clear();
    eulerIndexToNodeIndex.clear();
    for(int i = 0; i < numberOfVertices; i++){
        nodes[i].firstEulerAppearance = -1;
    }
    eulerTourIndex = 0;
    root = &nodes[rootIndex-1];
    setParent(root, nullptr);
    buildRMQTables();
}

void Tree::buildRMQTables(){
    logTable.assign(eulerTour.size() + 1, 0);
    for (int i = 2; i < logTable.size(); i++) {
        logTable[i] = logTable[i / 2] + 1;
    }
    sparseTable.assign(logTable.back() + 1, vector<int>(eulerTour.size()));
    sparseTable[0] = eulerTour;
    for(int row = 1; row < sparseTable.size(); row++) {
        for (int i = 0; i + (1 << row) <= eulerTour.size(); i++) {
            sparseTable[row][i] = min(sparseTable[row - 1][i], sparseTable[row - 1][i + (1 << (row - 1))]);
        }
    }
}

Node* Tree::LCA(int start, int end){
    if(start==end){
        return &nodes[start-1];
    }
    start=nodes[start-1].firstEulerAppearance;
    end=nodes[end-1].firstEulerAppearance;
    int left = min(start, end);
    int right = max(start, end);
    int log = logTable[right - left];
    int eulerIndex = min(sparseTable[log][left], sparseTable[log][right - (1 << log)]);
    int nodeIndex = eulerIndexToNodeIndex[eulerIndex];
    return &nodes[nodeIndex-1];
}

int main() {
    int nVertices;
    cin >> nVertices;
    int nQueries;
    cin >> nQueries;

    Tree tree(nVertices);

    int vertexWeight;
    for(int i = 1; i < nVertices+1; i++){
        cin >> vertexWeight;
        tree.addNode(i, vertexWeight);
    }

    int x, y, z;
    for(int i = 0; i < nVertices-1; i++){
        cin >> x >> y;
        tree.addEdge(x,y);
    }

    int root;
    cin >> root;
    tree.setRoot(root);

    int query;
    for(int i = 0; i < nQueries; i++){
        cin >> query;
        if(query == 0){
            cin >> root;
            tree.setRoot(root);
        } else if(query == 1){
            cin >> x >> y >> z;
            tree.updatePath(x,y, z);
        } else if(query == 2){
            cin >> x >> y >> z;
            tree.incrementPath(x, y, z);
        } else if(query == 3){
            cin >> x >> y;
            cout << tree.minPath(x,y) << endl;
        } else if(query == 4){
            cin >> x >> y;
            cout << tree.maxPath(x,y) << endl;
        } else if(query == 5){
            cin >> x >> y;
            cout << tree.sumPath(x,y) << endl;
        } else if(query == 6){
            cin >> x >> y;
            tree.changeParent(x,y);
        } else if(query == 7){
            cin >> x >> y;
            Node* lca = tree.LCA(x, y);
            cout << lca->index << endl;
        }
    }
    return 0;
}
