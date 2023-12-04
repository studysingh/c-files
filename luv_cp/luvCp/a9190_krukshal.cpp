#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N];
int size[N];
void make(int a){ // making the node
    parent[a] = a;
}
int find(int x){ // finding the parent of x
    if(parent[x] == x) return x;
    // Path compression
    return parent[x] = find(parent[x]);
}
void Union(int a , int b){ // joining the group a and b
    a = find(a);
    b = find(b);
    if(a != b){
        // union by size
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}
// We are given with a graph . We have to find the minimum spannning tree . There are n nodes and m edges in the graph
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> g;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g.push_back({wt,{u,v}}); // storing the edges wrt to the edge weight
    }
    sort(g.begin(),g.end()); // sorting the graph on the basis of the weight of the edges
    for(int i=1;i<=n;i++) make(i); // making the dsu of every node
    int total_cost = 0;
    vector<pair<int,int>> tree; // stores the edges of the graph for minimum spanning tree
    for(int i=0;i<m;i++){
        auto edge = g[i];
        int weight = edge.first;
        int start = edge.second.first;
        int end = edge.second.second;
        if(find(start) == find(end)) continue; // if the starting and end point of the edge lies in the same group then we will not consider it
        Union(start , end); // making the group(say connecting the nodes)
        tree.emplace_back(start,end);
        total_cost += weight;
    }
    for(int i=0;i<tree.size();i++){
        cout<<tree[i].first<<" "<<tree[i].second<<endl;
    }
    cout<<"Total Cost "<<total_cost;
}