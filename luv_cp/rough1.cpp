#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> height(N),depth(N);
void dfs(vector<vector<int>> v , int vertex , int parent){
    if(vertex == parent) return;
    for(auto child : v[vertex]){
        height[vertex] = height[parent]+1;
        dfs(v,child,vertex);
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    dfs(graph,1,0);
    cout<<"Answer"<<endl;
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<depth[i]<<endl;
    }
}
/*
4
2 1
2 3
2 4
*/