#include<bits/stdc++.h>
using namespace std;
int main(){
    // vector of vectors
    vector<vector<int>> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m = i+1;
        vector<int> temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    cout<<"ans\n";
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        } cout<<endl;
    }
}