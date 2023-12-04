#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int a = 1e7+10;
vector<ll> lp(a+1),hp(a+1);
vector<bool> primes(int n){
    vector<bool> ans(a,true);
    ans[0]=ans[1]=false;
    for(int i=2;i<=n;i++){
        if(ans[i] == true){
            for(int j=2*i;j<=n;j+=i){
                ans[j] = false;
            }
        }
    }
    return ans;
}
// Precomputation of highest and lowest primes till the number n
pair<vector<ll>,vector<ll>> highLowPrime(){
    ll first = 1;
    ll last = 1;
    lp[1] = hp[1] = 1;
    vector<bool> v(a,true);
    for(ll i = 2;i<=a;i++){
        if(v[i]){
            lp[i] = i; hp[i] = i;
            for(ll j = 2*i;j<=a;j+=i){
                v[j] = false;
                hp[j] = i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
    return {lp,hp};
}
// finding the prime factorisation
vector<pair<ll,ll>> prime(ll n){
    highLowPrime();
    vector<pair<ll,ll>> ans;
    while(n>1){
        ll ct = 0;
        ll prime = hp[n];
        while(n%prime == 0){
            ct++;
            n/=prime;
        }
        ans.push_back({prime,ct});
    }
    return ans;
}
int main(){
    ll n=100;
    cin>>n;
    highLowPrime();
    vector<pair<ll,ll>> ans = prime(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}