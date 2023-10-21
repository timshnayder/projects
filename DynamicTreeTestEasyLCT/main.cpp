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





    int find_root(int node){


    }


    //done
    void cut(Node* n){
        access(n);
        if(n->left != nullptr){
            n->left->pathParent = n->pathParent;
            n->left = nullptr;
        }
        n->pathParent = nullptr;
    }

    //done
    void link(Node* nodeOne, Node* nodeTwo){
        access(nodeOne);
        access(nodeTwo);
        nodeOne->left = nodeTwo;
        nodeTwo->parent = nodeOne;
    }

    void rotateRight(Node* n){
        Node *nParent = n->parent;
        Node *nGParent = nParent->parent;
        nParent = n->parent, nGParent = nParent->parent;
        if((nParent->left = n->right)) nParent->left->parent = nParent;
        n->right = nParent, nParent->parent = n;
        if((n->parent = nGParent))
        {   if(nParent == nGParent->left) nGParent->left = n;
            else nGParent->right = n;
        }
        n->pathParent = nParent->pathParent;
        nParent->pathParent = 0;
    }

    void rotateLeft(Node* n){
        Node *nParent = n->parent;
        Node *nGParent = nParent->parent;

        if(nParent->right = n->left){
            nParent->right->parent = nParent;
        }
        n->left = nParent;
        nParent->parent = n;
        if(n->parent = nGParent){
            if(nParent == nGParent->left){
                nGParent->left = n;
            }
        }
        n->pathParent = nParent->pathParent;
        nParent->pathParent = 0;
    }

    void splay(Node* node){
        while(node->parent!=nullptr){

        }
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
