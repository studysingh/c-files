#include<iostream>
#include<vector>
using namespace std;
#define pb push_back
const int N = 1e5+10;
int depth[N] , height[N];
// finding the height and depth in the tree
void dfs(vector<vector<int>> &g , int vertex , int parent = 0){
    // after entering  the vertex 
    for(int child : g[vertex]){
        // before entering  to the child
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1; // depth of the child of the vertex is +1 of it
        dfs(g,child,vertex);
        // before exiting the child
        height[vertex] = max(height[vertex] , height[child] + 1); // height of the vertex is the maxima of the childrens of it + 1 
    }
    // after exiting the vertex
}
int main(){
    int n,m; // n vertices and m edged
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(graph,1);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
    }
}
/*
13
12
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/