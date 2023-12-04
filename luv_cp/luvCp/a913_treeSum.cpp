#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int even_ct[N],subTree_sum[N];
#define pb push_back
vector<vector<int>> graph(N);
// Function to precompute the sum of the subtrees and finding the count of the even numbers in the subtree
/*
Concept :- We generally do the operation in the tree moving from leaf node to the root node , We calculated the sum and 
found the even count from leaf to the root node
*/
void dfs(int vertex , int parent = -1){
    // after entry to the vertex
    if(vertex%2 == 0) even_ct[vertex]++;
    subTree_sum[vertex] += vertex;
    for(auto child : graph[vertex]){
        // before entry to the child
        if(parent == child ) continue;
        dfs(child,vertex);
        // after entry in child node
        subTree_sum[vertex] += subTree_sum[child];
        even_ct[vertex] += even_ct[child];
    }
}
int main(){
    // input
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<subTree_sum[i]<<" "<<even_ct[i]<<endl;
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