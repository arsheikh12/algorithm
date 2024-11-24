#include <iostream>
#include <vector>
using namespace std;

vector<int> x;
vector<int> w;
int m;

void SumOfSub(int s, int k, int r) {
    x[k] = 1; // Include the current element
    if (s + w[k] == m) {
        // If the current subset adds up to the target, print it
        for (int i = 1; i <= k; i++) {
            if (x[i] == 1) {
                cout << w[i] << " ";
            }
        }
        cout << endl;
    } 
    else if (k + 1 < w.size()) {
        // Explore including the next element
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }

    x[k] = 0; // Exclude the current element
    if (k + 1 < w.size()) {
        // Explore excluding the next element
        SumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    w.resize(n + 1);
    x.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        w[i]=rand()%15;
    }

    cout << "Enter the target sum (m): ";
    cin >> m;

    int total_sum = 0;
    for (int i = 1; i <= n; i++) {
        total_sum += w[i];
    }
    SumOfSub(0, 1, total_sum);
    return 0;
}
