#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 20;
int n =7 ;  // The number of nodes (preset to 7 for the adjacency matrix below)
int m;      // Number of colors
int G[MAX_NODES][MAX_NODES] = {
    {0, 1, 0, 0, 1, 1, 1},
    {1, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 1},
    {0, 1, 1, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0}
};
int x[MAX_NODES] = {0};

void NextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1);  // Increment color
        if (x[k] == 0) return;        // All colors tried, backtrack

        int j;
        for (j = 0; j < n; j++) {     // Loop through all nodes
            if (G[k][j] && x[k] == x[j]) break;  // Check adjacent colors
        }

        if (j == n) return;  // Valid color found, exit the loop
    } while (true);
}

void mColoring(int k) {
    do {
        NextValue(k);
        if (x[k] == 0) return;  // Backtrack if no color is valid

        if (k == n - 1) {       // Solution found
            for (int i = 0; i < n; i++) {
               // cout << x[i] << " ";
            }
            //cout << endl;
        } else {
            mColoring(k + 1);   // Recur for next vertex
        }
    } while (true);
}

int main() {
    do {
        cout << "Enter the number of colors: ";
        cin >> m;
        if (m <= 0) break;  // Exit condition for the loop

        fill(x, x + n, 0);  // Initialize color array to 0

        clock_t start = clock();
        mColoring(0);  // Start coloring from the first vertex
        clock_t finish  =clock();
        double time  = double(finish- start)/CLOCKS_PER_SEC;
        cout << "Total Time in seconds: " << time << endl;

    } while (true);

    return 0;
}
