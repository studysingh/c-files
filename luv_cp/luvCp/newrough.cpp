#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.emplace_back(x);
        }
        // solution
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            int el = v[i];
            int ct = 1;
            for(int j=i-1;j>=0;j--){
                if(v[j]<el){
                    ct--;
                    el = v[j];
                }
            }
            if(ct == 0) ans++;
        }
        cout<<ans<<endl;
    }
}