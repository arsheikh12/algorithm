#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

// Global variables for DFS
vector<int> color;
vector<int> parent;
vector<int> discovery_time;
vector<int> finish_time;
vector<list<int> > adjacency_list;  // Original graph
vector<list<int> > transpose_list;  // Transpose of the graph
list<int> topological_order;       // Stack for storing topological order
int dfs_time;

// Function to initialize the graph
void initializeGraph(int numVertices) {
    color.resize(numVertices + 1, WHITE);
    parent.resize(numVertices + 1, -1);
    discovery_time.resize(numVertices + 1, 0);
    finish_time.resize(numVertices + 1, 0);
    adjacency_list.resize(numVertices + 1);
    transpose_list.resize(numVertices + 1);  // Initialize transpose graph
}

// Function to add edges to the graph
void addEdge(int u, int v) {
    adjacency_list[u].push_back(v);
    transpose_list[v].push_back(u);  // For the transpose, reverse the direction
    cout << "Edge added: " << u << " -> " << v << endl;
}

// DFS visit function to explore a vertex
void DFS_VISIT(int u) {
    dfs_time++;
    discovery_time[u] = dfs_time;
    color[u] = GRAY;
    cout << "Visiting vertex " << u << ", discovery time: " << dfs_time << endl;

    for (int v : adjacency_list[u]) {
        if (color[v] == WHITE) {
            parent[v] = u;
            DFS_VISIT(v);
        }
    }

    color[u] = BLACK;
    finish_time[u] = ++dfs_time;  // Increment dfs_time when finishing the vertex
    topological_order.push_front(u); // Store in topological order
    cout << "Finished vertex " << u << ", finish time: " << finish_time[u] << endl;
}

// Function for DFS to compute finish times
void DFS(int numVertices) {
    for (int i = 1; i <= numVertices; i++) {
        color[i] = WHITE;
        parent[i] = -1;
    }
    dfs_time = 0;

    for (int i = 1; i <= numVertices; i++) {
        if (color[i] == WHITE) {
            cout << "Starting DFS from vertex " << i << endl;
            DFS_VISIT(i);
        }
    }
}

// DFS for the transpose graph, to find SCCs
void DFS_VISIT_Transpose(int u, vector<bool>& visited, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : transpose_list[u]) {
        if (!visited[v]) {
            DFS_VISIT_Transpose(v, visited, component);
        }
    }
}

// Function to print strongly connected components
void printSCCs(int numVertices) {
    // Step 1: Perform DFS on the original graph to compute finish times
    DFS(numVertices);

    // Step 2: Create the transpose of the graph (already created in addEdge function)
    // Step 3: Perform DFS on the transposed graph in the order of finish times

    // Vector to track visited vertices in the transpose graph
    vector<bool> visited(numVertices + 1, false);

    // Process vertices in the order of decreasing finish times
    cout << "\nStrongly Connected Components (SCCs):\n";
    while (!topological_order.empty()) {
        int u = topological_order.front();
        topological_order.pop_front();

        // If not visited, it's a new SCC
        if (!visited[u]) {
            vector<int> component;
            DFS_VISIT_Transpose(u, visited, component);
            cout << "SCC: ";
            for (int v : component) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int numVertices = 6;  // Number of vertices
    initializeGraph(numVertices);

    // Add edges to the graph (directed acyclic graph example)
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    // Find and print the strongly connected components
    printSCCs(numVertices);

    return 0;
}

