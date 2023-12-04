#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>> v(n,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }
        // solution
        int ans = 0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                vector<char> temp = {v[i][j] , v[j][n-1-i],v[n-1-i][n-1-j] , v[n-1-j][i]};
                sort(temp.begin() , temp.end());
                char big = temp[3];
                for(int k=0;k<temp.size();k++){
                    ans+=(big-temp[k]);
                }
            }
        }
        cout<<ans<<endl;
    }
}