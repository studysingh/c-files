#include<bits/stdc++.h>
using namespace std;
// Question 1
// We have to find the connected parts in the graph

void dfs(vector<vector<int>> &g , vector<bool> &visited , int vertex){
    visited[vertex] = true;
    for(int child : g[vertex]){
        if(visited[child]) continue;
        dfs(g,visited,child);
    }
}
// checking the visited array to be true

int check(vector<bool> &visited , int n){
    for(int i=1;i<n+1;i++){
        if(visited[i] != true) return i;
    }
    return -1;
}

void solve(vector<vector<int>> &g , int n){
	vector<bool> visited(n+1,false);
    int count = 0;
    while(true){
        if(check(visited , n) == -1) break;
        dfs(g,visited,check(visited , n));
        count++;
    }
    cout<<count<<endl;
}

// Question 2 -> Detect the cycle in the graph
bool cycleDetect(int vertex , int parent , vector<vector<int>> &g , bool *visited){
    bool isLoopExist = false;
    visited[vertex] = true;
    for(int child : g[vertex]){
        if(visited[child] && child != parent) return true;
        if(visited[child]) continue;
        isLoopExist |= cycleDetect(child,vertex,g,visited); // if any loop exist in the graph then or will return the true means the loop exist
        
    }
    return isLoopExist;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n+1,vector<int>());
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    solve(graph,n);
}