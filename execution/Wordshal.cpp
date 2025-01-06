#include <bits/stdc++.h>
using namespace std;

const double INF = numeric_limits<double>::infinity();

void AllPaths(double A[100][100], int n) {

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
      double A[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    AllPaths(A, n);
    cout << "The shortest path matrix is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << A[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
