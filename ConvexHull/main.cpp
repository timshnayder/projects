#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXNODES 10010
#define ull long long

using namespace std;

class Node{
public:
    ull weight;
    ull neighbour;
    ull hullDamage;
};

class Graph{
private:
    vector<Node> adjacency[MAXNODES];
public:
    [[nodiscard]] const vector<Node>& getNeighbours(ull node)const{
        return adjacency[node];
    }
    void addEdge(ull node, ull neighbour, ull weight, ull hullDamage){
        Node n{weight, neighbour, hullDamage};
        adjacency[node].push_back(n);
    }
};

void convexHull(const Graph& graph, ull currentNode, ull shortestDist[][210], ull curHull){
    //loop through all neighbours of current island
    for(const auto& neighbour: graph.getNeighbours(currentNode)) {

        // Check to make sure hull is not broken
        if(curHull>neighbour.hullDamage){

            //Check if traversal to new island is fastest yet OR traversal to new island has most hull armour so far
            if (shortestDist[neighbour.neighbour][curHull-neighbour.hullDamage] > shortestDist[currentNode][curHull] + neighbour.weight /*|| curHull-neighbour.hullDamage > findHighestHull(shortestDist, neighbour.neighbour)*/) {

                    // Update shortest dist
                    shortestDist[neighbour.neighbour][curHull-neighbour.hullDamage] = shortestDist[currentNode][curHull]+neighbour.weight;
                    convexHull(graph, neighbour.neighbour, shortestDist, curHull - neighbour.hullDamage);

            }
        }
    }
}

class QueueElement{
public:
    ull node;
    ull hull;
};

class Compare
{
public:
    bool operator() (const QueueElement& l, const QueueElement& r) const { return l.node > r.node; }
};

void convexHullBFS(const Graph& graph, ull firstNode, ull shortestDist[][210], ull firstHull){
    priority_queue<QueueElement, vector<QueueElement>, Compare> q;
    QueueElement first{firstNode, firstHull};
    q.push(first);
    while(!q.empty()){
        const QueueElement currentNodeElement = q.top();
        q.pop();
        for(const auto& neighbour: graph.getNeighbours(currentNodeElement.node)) {
            // Check to make sure hull is not broken
            if(currentNodeElement.hull>neighbour.hullDamage){

                //Check if traversal to new island is fastest yet OR traversal to new island has most hull armour so far
                if (shortestDist[neighbour.neighbour][currentNodeElement.hull-neighbour.hullDamage] > shortestDist[currentNodeElement.node][currentNodeElement.hull] + neighbour.weight /*|| curHull-neighbour.hullDamage > findHighestHull(shortestDist, neighbour.neighbour)*/) {

                    // Update shortest dist
                    shortestDist[neighbour.neighbour][currentNodeElement.hull-neighbour.hullDamage] = shortestDist[currentNodeElement.node][currentNodeElement.hull]+neighbour.weight;
                    QueueElement next{neighbour.neighbour, currentNodeElement.hull - neighbour.hullDamage};
                    q.push(next);
                }
            }
        }

    }

}

int main() {
    Graph graph;
    ull hullHealth, islands, routes;
    ull from, to, time, hullDamage;
    ull start, end;

    cin >> hullHealth >> islands >> routes;
//    cout << hullHealth << " " << islands << " " << routes << endl;
    ull shortestDist[islands+1][210];
    // Input all routes between islands and make them bidirectional
    for(ull i = 1; i <= routes; i++){
        cin >> from >> to >> time >> hullDamage;
//        cout << from << " " << to << " " << time << " " << hullDamage << endl;
        graph.addEdge(from, to, time, hullDamage);
        graph.addEdge(to, from, time, hullDamage);
    }
    cin >> start >> end;
    for(ull i = 0; i < islands+1; i++){
        for(ull j = 0; j < 210; j++){
            shortestDist[i][j] = INT64_MAX;
        }
    }
    shortestDist[start][hullHealth] = 0;

    convexHullBFS(graph, start, shortestDist, hullHealth);
//    sort(shortestDist[end], shortestDist[end]+ sizeof(shortestDist[end]) / sizeof(shortestDist[end][0]));
    ull shortestDistance = INT64_MAX;
    for(int i =  0; i < sizeof(shortestDist[end])/sizeof(shortestDist[end][0]); i++){
        if(shortestDist[end][i] != INT64_MAX){
            if(shortestDist[end][i] < shortestDistance){
                shortestDistance = shortestDist[end][i];
            }
        }
    }
    if(shortestDistance == INT64_MAX){
        cout << "-1" << endl;
    } else {
        cout << shortestDistance << endl;
    }

    return 0;
}
