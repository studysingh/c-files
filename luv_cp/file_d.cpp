#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long long > vl;
typedef vector<vector<long long>> vll;
#define pi 3.14
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define iseven %2==0
#define isodd %2==1
void solve(){
    ll n,m,d;
    cin>>n>>m>>d;
    vector<ll> s,diff;
    ll x;
    bool flag = true;
    for(int i=0;i<m;i++){
        cin>>x;
        s.eb(x);
    }
    bool to_delete = false;
    for(int i=1;i<m;i++){
        if(s[i]-s[i-1]>d){
            flag = true;
            break;
        }
        diff.eb(s[i]-s[i-1]);
    }
    ll k=1,ct=1;
    int j=0;
    while(k<=n){
        while(j<s.size() && k<=s[j]){
            if(k==s[j]){
                ct++;
                
            }
            k+=d;
            ct++;
        } j++;
        if(j>=s.size()) break;
    }
    while(k<=n){
        k+=d;
        ct++;
    }
    if(flag == true) cout<<ct-1<<endl;
    else cout<<ct<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }


    return 0;
}