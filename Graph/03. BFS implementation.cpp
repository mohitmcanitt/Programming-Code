/*

BFS------> Breadth First 

Steps:
1. Take queue and a set
2. Queue will store the vertex
3. set will store visited vertex
4. put source vertex in set and queue
5. Pop from queue
6. Print top element
7. Push its child which is not visited in queue and set
7. repeat 5-7 untill queue is not empty

Input:
Graph example taken from below link
https://www.youtube.com/watch?v=QRq6p9s8NVg

Output:
A-->B,S,
B-->A,
C-->S,D,E,F,
D-->C,
E-->C,H,
F-->G,C,
G-->S,F,H,
H-->E,G,
S-->A,C,G,
BFS, If source is C
C S D E F A G H B 

*/


#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>  // Include the queue header for BFS
using namespace std;

template <typename T>
class Graph {
    int v;  // Number of vertices
    unordered_map<T, vector<T>> m;  // Adjacency list with unordered_map

public:
    // Constructor to initialize the number of vertices
    Graph(int v) {
        this->v = v;
    }

    // Function to add an edge between two vertices
    void addEdge(T src, T dest) {
        m[src].push_back(dest);
        m[dest].push_back(src);  // Since it's an undirected graph
    }

    // Function to print the edges of the graph
    void printEdge() {
        for (auto& vertex : m) {
            cout << vertex.first << "-->";
            for (auto& nbhr : vertex.second)
                cout << nbhr << ",";
            cout << endl;
        }
    }

    // BFS function to traverse the graph from a source vertex
    void bfs(T src) {
        unordered_set<T> visited;  // Use unordered_set for average O(1) complexity
        queue<T> q;      // Queue for BFS
        q.push(src);     // Start with the source vertex
        visited.insert(src);  // Mark the source as visited

        while (!q.empty()) {
            T temp = q.front();
            q.pop();
            cout << temp << " ";  // Print the current vertex

            // Process all the neighbors of the current vertex
            for (auto& nbhr : m[temp]) {
                if (visited.count(nbhr) == 0) {
                    q.push(nbhr);       // Add unvisited neighbor to the queue
                    visited.insert(nbhr);  // Mark neighbor as visited
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph<char> g(10);  // Create a graph with 10 vertices (max vertices will be determined by input)
    g.addEdge('A', 'B');
    g.addEdge('A', 'S');
    g.addEdge('S', 'C');
    g.addEdge('C', 'D');
    g.addEdge('S', 'G');
    g.addEdge('G', 'F');
    g.addEdge('C', 'E');
    g.addEdge('C', 'F');
    g.addEdge('E', 'H');
    g.addEdge('G', 'H');

    cout << "Graph edges:" << endl;
    g.printEdge();  // Print the graph's adjacency list

    cout << "BFS traversal starting from node C:" << endl;
    g.bfs('C');  // Perform BFS starting from node 'C'

    return 0;
}

