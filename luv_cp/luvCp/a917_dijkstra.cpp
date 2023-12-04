#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
const int N = 1e5+10;
const int INF = 1e8+10;
vector<int> dist(N,INF);
vector<int> vis(N,0);
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

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].emplace_back(v,wt);
    }
    dijkstra(2);
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}
/*
6 8
1 2 7
2 4 9
4 6 1
1 3 12 
3 5 10
5 6 5
2 3 2
5 4 4
*/