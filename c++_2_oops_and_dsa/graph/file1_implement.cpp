#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> g(N); // g.first stores the node and the g.second stores the weight of that node

void dijkstra(int source , vector<vector<pair<int,int>>> g){
    set<pair<int,int>> st; // st.first stores the minimum distance and st.second stores the node no
    st.insert({0,source});
    while(st.size()!=0){
        int curr_v = (*st.begin()).second;
        int curr_d = (*st.begin()).first;
        st.erase(st.begin());
        if(vis[curr_v]) continue;
        vis[curr_v] = 1;
        for(auto child : g[curr_v]){
            int child_d = curr_d + child.second;
            if(child_d<dist[child.first]){ // minimizing the distance
                dist[child.first] = child_d;
                st.insert({child_d,child.first});
            }
        }
    }
    // Time Complexity -> O(V + Elog(V))
}

void bfs(int n, vector<vector<int>> &adj){
    vector<bool> vis(n,false);

    queue<int> q;
    q.push(0);
    vis[0] = true;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        // pushing the element
        for(int i=0;i<adj[temp].size();i++){
            int x = adj[temp][i];
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
            }
        }
    } cout<<endl;
}
void dfs( vector<vector<int>> &adj , vector<bool> &vis , int startingPt){
    if(!vis[startingPt]){
        // jo bhi kam karna hai
        cout<<startingPt<<" ";
        vis[startingPt] = true;
        for(int i=0;i<adj[startingPt].size();i++){
            dfs(adj,vis,adj[startingPt][i]);
        }
    } else{
        return;
    }
}
int main(){
    int n; // no of nodes
    cin>>n;
    int m; // no of edges
    cin>>m;
    vector<vector<int>> adj(n,vector<int>());
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n,false);
    dfs(adj,vis,0);
}