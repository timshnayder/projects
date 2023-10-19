#include <iostream>
#include <vector>
using namespace std;

class Node{
    int weight;
    Node* left;
    Node* right;
    Node* parent;
};

class LinkCutTree{
    vector<Node> nodes;

    void link(int nodeOne, int nodeTwo){

    }

    void cut(int nodeOne, int nodeTwo){

    }

    int find_root(int node){

    }
};

void rotateRight(Node* node){

}

void rotateLeft(Node* node){

}

void splay(Node* node){

}

Node* access(Node* node){
    splay(node);

}

Node* lca(Node* firstNode, Node* secondNode){

}



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
            Node* lca = tree.LCA(x, y);
            cout << lca->index << endl;
        }
    }

    return 0;
}
