#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Graph {
public: 
    unordered_map<int, vector<int>> adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void printGraph() {
        for(auto i : adj) {
            cout << i.first << "->";
            for(auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of Nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of Edges: ";
    cin >> m;

    Graph graph;

    cout << "Enter the edges(u, v)" << endl;
    for(int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "Directed Graph" <<endl;
    graph.printGraph();

    return 0;
}