#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<int> color;
vector<int> parent;
vector<int> discovery_time;
vector<int> finish_time;
vector<list<int> > adjacency_list;
list<int> topological_order;
int dfs_time;
void initializeGraph(int numVertices) {
    color.resize(numVertices + 1, WHITE);
    parent.resize(numVertices + 1, -1);
    discovery_time.resize(numVertices + 1, 0);
    finish_time.resize(numVertices + 1, 0);
    adjacency_list.resize(numVertices + 1);
}
void addEdge(int u, int v) {
    if (u < adjacency_list.size() && v < adjacency_list.size()) {
        adjacency_list[u].push_back(v);
        cout << "Edge added: " << u << " -> " << v << endl;
    }
    else {
        cout << "Invalid edge (" << u << " -> " << v << ")" << endl;
    }
}
void DFS_VISIT(int u) {
    discovery_time[u] =+dfs_time;
    color[u] = GRAY;
    for (int v : adjacency_list[u]) {
        if (color[v] == WHITE) {
            parent[v] = u;
            DFS_VISIT(v);
        }
    }
    color[u] = BLACK;
    finish_time[u] = ++dfs_time;
    topological_order.push_front(u);
    //cout << "Finished vertex " << u << ", finish time: " << finish_time[u] << endl;
}
void DFS(int numVertices) {
    for (int i = 0; i <=numVertices; i++) {
        color[i] = WHITE;
        parent[i] = -1;
    }
    dfs_time = 0;
    for (int i = 0; i <= numVertices; i++) {
        if (color[i] == WHITE) {
           // cout << "Starting DFS from vertex " << i << endl;
            DFS_VISIT(i);
        }
    }
}
void printTopologicalOrder() {
    cout << "\nTopological Sort Order:\n";
    for (int vertex : topological_order) {
        cout << vertex << " ";
    }
    cout << endl;
}
int main() {
    int numVertices = 6;
    initializeGraph(numVertices);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(5, 3);
    addEdge(5, 4);
    addEdge(6, 5);
    addEdge(6, 1);
    DFS(numVertices);
    printTopologicalOrder();
    return 0;
}
