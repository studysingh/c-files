#include<bits/stdc++.h>
using namespace std;
const int N =  1e3+10;
const int INF = 1e7;
int dist[N][N];
// Time complexity -> O(N^3)
int main(){
    // Initializing the distance as infinity for different vertices and 0 for same
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    // Taking the input
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        dist[u][v] = wt;
    }
    // taking the element k in the account
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){ // here we are starting with 1 because the graph is assumed to be started with the vertex 1
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }
    // Printing the output
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a = dist[i][j];
            if(a == INF) cout<<i<<" "<<j<<" "<<"INF"<<endl;
                else cout<<i<<" "<<j<<" "<<a<<endl;
        }
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