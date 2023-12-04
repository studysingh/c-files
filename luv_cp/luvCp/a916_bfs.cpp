#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define pb push_back
const int N = 1e5+10;
vector<vector<int>> g(N);
bool vis[N];
int level[N];
/*
Algorithm -> 
1.First push the element in the queue and mark the visited array
2. while q is not empty we should process each and every element of the queue and then store the childs of the current node and mark the visited also
*/
/*
One important application is to find the shortest path between the two points of the graph
*/
void bfs(int source){
    queue<int> q; // queue to store the level wise elements
    q.push(source);
    vis[source] = true;
    level[source] = 0;

    while(!q.empty()){
        int curr_v = q.front();
        q.pop();

        for(int child : g[curr_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[curr_v]+1; // calculating the level
            }
        }

    }
    // Time complexity -> O(V+E)
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    bfs(1);
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<level[i]<<endl;
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