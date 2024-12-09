#include<bits/stdc++.h>
using namespace std;
int main()
{
int P[5] = {0, 1, 2, 5, 6};
int wt[5] = {0, 2, 3, 4, 5};
int m = 8, n = 4;
int K[5][9];

for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= m; w++) {
        if (i == 0 || w == 0) {
            K[i][w] = 0;
        } else if (wt[i] <= w) {
            K[i][w] = max(P[i] + K[i - 1][w - wt[i]], K[i - 1][w]);
        } else {
            K[i][w] = K[i - 1][w];
        }
    }
}

cout <<"Maximum Profit:"<<K[n][m] << endl;

int i=n, j=m;
while (i > 0 && j > 0) {
    if (K[i][j] == K[i-1][j]) {
        cout << i << " = 0" << endl;
        i--;
    } else {
        cout << i << " = 1" << endl;
        i--;
        j = j - wt[i];
    }
}

}
