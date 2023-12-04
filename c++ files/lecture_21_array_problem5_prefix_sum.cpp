#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Given a matrix of order n*m and queries q. In each query,  two coordinates (r1,c1) and (r2,c2) are given . Return the sum of the rectangle made by the coordinates
//Approach 1:-> calculate the prefix sum over rows and add this prefix sum of rows over columns
void approach1(vector<vector<int>> v, int q){
    // prefix sum over rows
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            v[i][j]+=v[i][j-1];
        }
    }
    for(int i=0;i<q;i++){
        // taking coordinates input
        int r1,c1,r2,c2;
        cout<<"Enter the coordinates of starting point: ";
        cin>>r1>>c1;
        cout<<"Enter the coordinates of ending point: ";
        cin>>r2>>c2;
        // sum calculation
        if(r1<=r2 && c1<=c2){
        int ans=0;
        for(int i=r1;i<=r2;i++){
            if(c1!=0){
                ans+=v[i][c2]-v[i][c1-1]; // formula deduced
            } else{
                ans+=v[i][c2]-0;
            }
        }
        cout<<ans<<endl;
        }
    }
    return;
}
void approach2(vector<vector<int>> v, int q){
    // prefix sum over rows
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            v[i][j]+=v[i][j-1];
        }
    }
    // prefix sum over columns
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            v[i][j]+=v[i-1][j];
        }
    }
    // queries answered
    for(int i=0;i<q;i++){
        // defining variable
        int r1,c1,r2,c2;
        cout<<"Enter the starting coordinate: ";
        cin>>r1>>c1;
        cout<<"Enter the ending coordinate: ";
        cin>>r2>>c2;
        int ans=0;
        // formula deduced by observation
        if(r1!=0 && c1!=0){
            ans=v[r2][c2]-v[r2][c1-1]-v[r1-1][c2]+v[r1-1][c1-1];
        } else if(r1==0 && c1!=0){
            ans=v[r2][c2]-v[r2][c1-1];
        } else if(r1!=0 && c1==0){
            ans=v[r2][c2]-v[r1-1][c2];
        } else if(r1==0 && c1==0){
            ans=v[r2][c2];
        }
        cout<<ans<<endl;
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    int q;
    cout<<"Queries";
    cin>>q;
    approach2(v,q);
    
    return 0;
}