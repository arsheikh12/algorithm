#include <iostream>
#include <limits>

using namespace std;

const int INF = 9999; // Representing infinity

void ShortestPaths(int v, int cost[100][100], int dist[100], int n) {
    bool S[100]; // Boolean array to track vertices included in S

    // Step 1: Initialize
    for (int i = 1; i <= n; i++) {
        S[i] = false;
        dist[i] = cost[v][i];
    }

    S[v] = true; // Include the source vertex in S
    dist[v] = 0; // Distance to itself is 0

    // Step 2: Find n-1 shortest paths
    for (int num = 2; num <= n; num++) {
        // Find the vertex u not in S such that dist[u] is minimum
        int u = -1;
        int minDist = INF;
        for (int i = 1; i <= n; i++) {
            if (!S[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // No more vertices can be added
        S[u] = true; // Include u in S

        // Update distances for adjacent vertices of u
        for (int w = 1; w <= n; w++) {
            if (!S[w] && cost[u][w] != INF && dist[w] > dist[u] + cost[u][w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    const int n = 4; // Number of vertices
    int cost[100][100] = {
        {0, 0, 0, 0, 0},    // Row 0 (not used)
        {0, 0, 2, INF, 1},  // Row 1: edges from vertex 1
        {0, INF, 0, 3, INF},// Row 2: edges from vertex 2
        {0, INF, INF, 0, 4},// Row 3: edges from vertex 3
        {0, INF, INF, INF, 0} // Row 4: edges from vertex 4
    };
    int dist[100]; // Distance array

    int v; // Source vertex
    cout << "Enter the source vertex (1 to " << n << "): ";
    cin >> v;

    ShortestPaths(v, cost, dist, n);

    cout << "Shortest distances from vertex " << v << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "Vertex " << i << ": INF\n";
        } else {
            cout <<"From "<<v<< "Vertex To" << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}
