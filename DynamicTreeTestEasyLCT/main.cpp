#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int weight;
    int index;


    Node* left;
    Node* right;
    Node* parent;
    Node* pathParent;
};

class LinkCutTree{
public:
    vector<Node> nodes;



    void cut(int nodeOne, int nodeTwo){

    }

    int find_root(int node){


    }

    void rotateRight(Node* node){
        Node *nParent = node->parent;
        Node *nGParent = nParent->parent;



    }

    void rotateLeft(Node* node){
        Node *nParent = node->parent;
        Node *nGParent = nParent->parent;
    }

    void splay(Node* node){
        while(node->parent!= nullptr){

        }
    }

    void update(Node* node){

    }

    void link(Node* nodeOne, Node* nodeTwo){
        access(nodeOne);
        access(nodeTwo);
        nodeOne->left = nodeTwo;
        nodeTwo->parent = nodeOne;
    }

    Node* access(Node* node){
        splay(node);
        if(node->right){
            node->right->pathParent = node;
            node->right->parent = nullptr;
            node->right = nullptr;
            update(node);
        }

    }

    Node* lca(int firstNode, int secondNode){
        access(&nodes[firstNode]);
        return access(&nodes[secondNode]);
    }
};



int main() {
    int nVertices, nQueries;
    cin >> nVertices >> nQueries;

    int weight;
    for(int i = 0; i < nVertices; i++){
        cin >> weight;

    }

    int x, y, z;
    for(int i = 0; i < nVertices-1; i++){
        cin >> x >> y;

    }

    int root;
    cin >> root;

    LinkCutTree tree;

    int query;

    for(int i = 0 ; i < nQueries; i++){
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
            cout << tree.lca(x, y) << endl;
        }
    }

    return 0;
}
