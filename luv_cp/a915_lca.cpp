#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<vector<int>> g(N);
#define eb emplace_back
int parents[N]; //This array stores the parents of the tree nodes

// Find the lca of the two nodes
/*
Algorithm ->
1.First store the parents of all the nodes in the array 
2. Find the ancestor array of the node x and y
3. Find the element till we found the common parent . The last common parent of the elements is our answer
Note that we made the array from leaf to root So we reversed the arrays to get the array from root to leaf . So we found the last common ancestor
*/
// This function stores the ancestor of the nodes
void dfs(int vertex , int parent = -1){
    parents[vertex] = parent; // storing the parent of the vertex
    for(auto child : g[vertex]){
        if(parent == child ) continue;
        dfs(child,vertex);
    }
}
//Function
void func(){
    int x,y;
    cin>>x>>y; // Two elements
    dfs(1);
    vector<int> path_x,path_y; // Ancestor Path array of x and y 
    //Filling the ancestor arrays
    int el1 = x,el2 = y;
    while((el1 != -1 || el2 != -1)){
        if(el1 != -1){
            path_x.eb(el1);
            el1 = parents[el1];
        }
        if(el2 != -1){
            path_y.eb(el2);
            el2 = parents[el2];
        }
    }
    // Reversing the arrays to get the root to leaf side
    reverse(path_x.begin(),path_x.end());
    reverse(path_y.begin(),path_y.end());
    int min_length = min(path_x.size(),path_y.size());
    int ans = -1;
    // Finding the last common ancestor
    for(int i=0;i<min_length;i++){
        if(path_x[i] == path_y[i]) ans = path_x[i];
        else break;
    }
    cout<<ans<<endl;
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
    int q;
    cin>>q;
    while(q--){
        func();
    }
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