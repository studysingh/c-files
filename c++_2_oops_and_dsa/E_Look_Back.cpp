#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    // solution
    ll ans = 0;
    ll p = arr[0];
    ll c;
    for(ll i=0;i<n;i++){
        c = arr[i];
        if(c>=p){
            p = c;
            continue;
        }
        float nval = (log(float(p)) - log(float(c)))/log(2);
        ll x = nval;
        ll z = 0;
        if(x == nval) z = nval;
        else z = x+1;
        p = c*pow(2,z);
        ans += z;
    }
    cout<<ans<<endl;
}
int main(){
    ll t;
    cin>>t;
    // cout<<pow(t,1);
    while(t--){
        solve();
    }
}