#include <iostream>
#include <vector>
#include <memory>
#include <list>
#define MAXNODES 100001
using namespace std;

class Node{
public:
    Node():weight(0), index(0), parent(nullptr){

    }
    int weight;
    int index;
    Node* parent;
    list<Node*> neighbours;
};

class Tree{
private:
    Node* root;
    Node* nodes;
    void setParent(Node* node, Node* parent);
    void getPathToRoot(int startIndex, vector<Node*>& path);
public:
    Tree(int nVertices):root(nullptr), nodes(new Node[nVertices]){

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
        firstNode.neighbours.push_back(&secondNode);
        secondNode.neighbours.push_back(&firstNode);
    }

    void changeParent(int nodeIndex, int newParentIndex){
        //Remove this child from old parent and remove parent from child
        Node* node = &nodes[nodeIndex-1];
        if(node->parent!= nullptr){
            list<Node*> &parentNeighbours = node->parent->neighbours;
            for(auto neighbour = parentNeighbours.begin(); neighbour != parentNeighbours.end(); neighbour++){
                if(*neighbour==node){
                    parentNeighbours.erase(neighbour);
                    break;
                }
            }
            for(auto neighbour = node->neighbours.begin(); neighbour != node->neighbours.end(); neighbour++){
                if(*neighbour==node->parent){
                    node->neighbours.erase(neighbour);
                    break;
                }
            }
        }

        //Connect node and new parent
        addEdge(nodeIndex, newParentIndex);


        //Change nodes parent to new parent
        Node* newParent = &nodes[newParentIndex-1];
        node->parent = newParent;

    }

    void setRoot(int rootIndex);
    void findPath(int start, int end, vector<Node*> &path);
    Node* LCA(int start, int end);
};

void Tree::getPathToRoot(int startIndex, vector<Node*> &path) {
    Node* node = &nodes[startIndex-1];
    while(node!= nullptr){
        path.push_back(node);
        node = node->parent;
    }
}

void Tree::setParent(Node* node, Node *parent) {
    node->parent = parent;
    for(auto neighbour: node->neighbours){
        if(neighbour!=parent){
            setParent(neighbour, node);
        }
    }
}

void Tree::setRoot(int rootIndex) {
    root = &nodes[rootIndex-1];
    setParent(root, nullptr);
}

void Tree::findPath(int start, int end, vector<Node*> &path){
    vector<Node*> firstPath;
    getPathToRoot(start, firstPath);
    vector<Node*> secondPath;
    getPathToRoot(end, secondPath);
    int length = min(firstPath.size(), secondPath.size());

    path.reserve(firstPath.size()+secondPath.size());
    for(int i = 0; i < length; i++){
        int firstIndex = firstPath.size()-i-1;
        int secondIndex = secondPath.size()-i-1;
        if(firstPath[firstIndex]!=secondPath[secondIndex]){
            path.insert(path.end(), firstPath.begin(), firstPath.begin()+firstIndex+2);
            path.insert(path.end(), secondPath.rbegin()+i, secondPath.rend());
            break;
        }
    }

    if(path.empty()){
        //The shorter path is subset of longer path, so they never diverge and previous loop never finds the difference
        if(firstPath.size() > secondPath.size()){
            path.insert(path.end(), firstPath.begin(), firstPath.end()-secondPath.size()+1);
        } else {
            path.insert(path.end(), secondPath.rbegin()+firstPath.size()-1, secondPath.rend());
        }
    }
}

Node* Tree::LCA(int start, int end){
    vector<Node*> firstPath;
    getPathToRoot(start, firstPath);
    vector<Node*> secondPath;
    getPathToRoot(end, secondPath);
    int length = min(firstPath.size(), secondPath.size());
    for(int i = 0; i < length; i++){
        int firstIndex = firstPath.size()-i-1;
        int secondIndex = secondPath.size()-i-1;
        if(firstPath[firstIndex]!=secondPath[secondIndex]){
            return firstPath[firstIndex]->parent;
        }
    }
    if(firstPath.size() > secondPath.size()){
        return *(firstPath.rbegin()+(secondPath.size()-1));
    }else{
        return *(secondPath.rbegin()+(firstPath.size()-1));
    }
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
            vector<Node*> path;
            tree.findPath(x,y, path);
            for(Node* node: path){
                node->weight=z;
            }
        } else if(query == 2){
            cin >> x >> y >> z;
            vector<Node*> path;
            tree.findPath(x,y, path);
            for(Node* node: path){
                node->weight+=z;
            }
        } else if(query == 3){
            cin >> x >> y;
            vector<Node*> path;
            tree.findPath(x,y, path);
            int min = path[0]->weight;
            for(Node* node: path){
                if(node->weight<min){
                    min = node->weight;
                }
            }
            cout << min << endl;
        } else if(query == 4){
            cin >> x >> y;
            vector<Node*> path;
            tree.findPath(x,y, path);
            int max = path[0]->weight;
            for(Node* node: path){
                if(node->weight>max){
                    max = node->weight;
                }
            }
            cout << max << endl;
        } else if(query == 5){
            cin >> x >> y;
            vector<Node*> path;
            tree.findPath(x,y, path);
            int sum = 0;
            for(Node* node: path){
                sum+=node->weight;
            }
            cout << sum << endl;
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
