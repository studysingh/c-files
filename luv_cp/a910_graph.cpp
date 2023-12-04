#include "bits/stdc++.h"
using namespace std;
const int N = 1e5;
bool visited[N];
// Print 2D vectors
void print(vector<vector<int>> v){
    cout<<"Graph\n";
    for(int i=0;i<v.size();i++){
        cout<<i<<": ";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        } cout<<endl;
    }
}
// Taking the input of the graph of n vertices and m edges and edge description in adjacency matrix
// To store the weight in the matrix we will store the weight in place of 1
void inputAdjacencyMatrix(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(n,0)); // make 2D matrix
    for(int i=0;i<m;i++){
        int v1,v2; // connected vertices
        cin>>v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}
// Taking the input of the graph of n vertices and m edges and edge description in adjacency list
// To store the weight in the adjacency list we will make the vector of pairs where first will store the joining vertex and second 
// will store the weight
void inputAdjacencyList(){
    int n,m;
    cin>>n>>m;
    // make an adjacency list
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].emplace_back(v2);
        graph[v2].emplace_back(v1);
    }
    print(graph);
}
// DFS -> Depth First Search Algorithm
// time complexiy -> O(E+V)
void dfs(int vertex , vector<vector<int>> graph){
    // The code to be executed after entering the vertex
    visited[vertex] = true; // during entry we will tick the vertex
    for(int child : graph[vertex]){
        // The code to be executed before entering to the child node
        if(visited[child]) continue; // if vertex is visited then leave the vertex and try another
        dfs(child , graph);
        // The code to be executed before exiting the child node
    }
    // The code to be executed before exiting the vertex
}
int main(){
    inputAdjacencyList();
}