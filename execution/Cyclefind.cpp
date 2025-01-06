#include<bits/stdc++.h>
using namespace std;
int number;
vector<string>color;vector<int>decendent;vector<int >parent;vector<int>Final;
int TIME;
unordered_set<int>cycle;
void DFS(vector<vector<int>>&graph, int u){
    color[u]= "g";
    TIME=TIME+1;
    decendent[u]= TIME;
    for(int v:graph[u]){
        if(color[v]=="w"){
            parent[v]=u;
            DFS(graph, v);
        }else if( color[v]== "g" ){
            int node= u;
            while(node !=v){
                cycle.insert(node);
                node=parent[node];}
        cycle.insert(v);
        }
    }
color[u]= "b";TIME++;Final[u]= TIME;
}
int main(){
int edge,u,v;
cout<<"Number of nodes:";
cin>>number>>edge;
vector<vector<int>>graph(number+1);
for(int i=0; i<=number+1; i++){
        color.push_back("w");
        decendent.push_back(0);
        Final.push_back(0);
        parent.push_back(-1);
}
for(int i=0;i <edge; i++){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);}
TIME=0;
for(int i=0; i<number; i++){
    if(color[i]=="w")DFS(graph,i);
}
for(auto a:cycle){
    cout<<a<<" ";}
return 0;
}
