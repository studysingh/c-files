#include<bits/stdc++.h>
using namespace std;
void solve(){
    // input
    int n,m;
    cin>>n>>m;
    vector<int> arr(m,0);
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    sort(arr.begin() , arr.end());
    // solution
    vector<int> gap;
    for(int i=0;i<m-1;i++){
        int gp = arr[i+1] - arr[i]-1;
        gap.push_back(gp);
    }
    int gp = n-arr[m-1] + arr[0] - 1; // last element
    gap.push_back(gp);
    sort(gap.begin() , gap.end() , greater<int>());
    // creating blockage
    int ans = 0;
    //finding ans
    int diff = 1;
    for(int i=0;i<gap.size();i++){
        int a = gap[i]-diff;
        if(a<0) break;
        if(a==0) ans+=1;
        ans += a;
        diff += 4;
    }
    cout<<n-ans<<endl;



    // while(gap[0]>0){
    //     if(gap[0] == 1){
    //         ans += gap[0];
    //         break;
    //     }
    //     // going for two days
    //     gap[0] -= 1;
    //     ans += gap[0];
    //     for(int i=1;i<gap.size();i++){
    //         if(gap[i]<0) break;
    //         gap[i] -= 4;
    //     }
    //     gap[0] = INT_MIN;
    //     sort(gap.begin() , gap.end() , greater<int>());
    //     // removing unwanted elements
    //     while(gap[gap.size()-1] <= 0) gap.pop_back();
    // }
    // cout<<n-ans<<endl;
}
int main(){
    int t;
    cin>>t;
    // t=1;
    while(t--) solve();
}