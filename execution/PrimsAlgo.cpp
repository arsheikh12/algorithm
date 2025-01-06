#include <bits/stdc++.h>
using namespace std;
int Vertex=5;
 int Totalcost=0;
 int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < Vertex; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < Vertex; i++)
        {cout << parent[i] << " - " << i << " \t"
             << graph[parent[i]][i] << " \n";
          Totalcost=Totalcost+graph[parent[i]][i];
             }
        cout<<"Total MSTcost:"<<Totalcost<<endl;
}
void primMST(vector<vector<int>> &graph) {
    vector<int> parent(Vertex);
    vector<int> key(Vertex);
    vector<bool> mstSet(Vertex);
    for (int i = 0; i < Vertex; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < Vertex - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < Vertex; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}
int main() {
      vector<vector<int>>graph ={ { 0, 2, 0, 6, 0 },
                                  { 2, 0, 3, 8, 5 },
                                  { 0, 3, 0, 0, 7 },
                                  { 6, 8, 0, 0, 9 },
                                { 0, 5, 7, 9, 0 } };
   clock_t start=clock();
    primMST(graph);
   clock_t stop=clock();
   double time=double(stop- start)/CLOCKS_PER_SEC;
   cout<<"Total Execution Time:"<<time<<end;
    return 0;
}

