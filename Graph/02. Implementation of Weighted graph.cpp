/*
Implemantaion of weighted graph (directed)
Image of graph
https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-2-weighted-graph/


Output :
Neighbours of vertex 0 is --> vertex 1 and their weight is 10, vertex 2 and their weight is 3, vertex 3 and their weight is 2,
Neighbours of vertex 1 is --> vertex 3 and their weight is 7,
Neighbours of vertex 2 is --> vertex 3 and their weight is 6,

*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int vertices; // Number of vertices
    map<int, vector<pair<int, int>>> adjacencyList; // Adjacency list to store graph
    
public:
    // Constructor to initialize number of vertices
    Graph(int vertices) {
        this->vertices = vertices;
    }

    // Function to add an edge with a weight to the graph
    void addEdge(int u, int v, int weight) {
        adjacencyList[u].push_back(make_pair(v, weight)); // Add v and weight to u's adjacency list
        adjacencyList[v].push_back(make_pair(u, weight)); // Since this is an undirected graph
    }

    // Function to print the adjacency list representation of the graph
    void displayGraph() const {
        for (const auto& vertex : adjacencyList) {
            cout << "Vertex " << vertex.first << " has neighbors: ";
            for (const auto& neighbor : vertex.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4); // Create a graph with 4 vertices
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 3, 6);

    // Display the graph
    g.displayGraph();

    return 0;
}

// Method 2

/*
5
6
0 1 10
0 4 20
1 2 30
3 4 40
1 3 50
2 3 60
*/

#include <iostream>
#include <vector>

using namespace std;

struct Graph {
    int vertex;   // renamed to avoid confusion
    int weight;
};

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<Graph> adj[vertices];

    while (edges--) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph node{v, w};
        adj[u].push_back(node); 
    }

    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (const auto& nb : adj[i]) {
            cout << "(" << nb.vertex << ", " << nb.weight << ") ";
        }
        cout << endl;
    }

    return 0;
}

