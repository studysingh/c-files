#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
const int N = 1e5+10;
int depth[N];
vector<vector<int>> g(N);
// Diameter of tree -> This is the maximum distance b/w any two nodes of a tree
/*
Logic ->
1 . Find the maximum depth leaf node . 
2 . Using this leaf node find the maximum depth of the tree
*/
void dfs(int vertex , int parent = -1){
    for(auto child : g[vertex]){
        if(child == parent ) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child , vertex);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    // solution
    dfs(1); // first time running dfs for any node
    int mx_node = -1; // maximum depth node no
    int mx_depth = -1; // maximum depth from the node
    for(int i=1;i<=n;i++){
        if(mx_depth<depth[i]){ // finding the maximum depth
            mx_depth = depth[i];
            mx_node = i;
        }
        depth[i] = 0; // making the depth of the nodes again to be zero
    }
    dfs(mx_node); // again called the dfs for the mx_depth_node to find the maximum depth from this node
    int ans = -1;
    for(int i=1;i<=n;i++){
        if(ans<depth[i]){ // finding the diamete
            ans = depth[i];
        }
        depth[i] = 0;
    }
    cout<<ans<<endl;
}
/*
13
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