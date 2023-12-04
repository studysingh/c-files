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
// Time Complexity -> O(a(n))
int main(){
    int n; // No. of elements
    cin>>n;
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        make(u);
    }
    // The elements to be connected
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    // To find the connected components
    int count = 0;
    for(int i=1;i<=n;i++){
        if(find(i) == i) count++;
    }
    cout<<count<<endl;
}