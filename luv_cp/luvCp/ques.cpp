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
const int N = 1e5+10;
vector<bool> primes(N,true);
vector<int> hp(N,0),lp(N,0);


int highestDiv(int n){
    int a = lp[n];
    int b = hp[n];
    vector<pair<int,int>> div;
    while(n>1){
        int x = hp[n];
        int ct = 0;
        while(n%x == 0){
            ct++;
            n/=x;
        }
        div.eb(x,ct);
    }
    int ans = 1;
    for(int i=0;i<div.size();i++){
        auto ab = div[i];
        int base = ab.first;
        int ex = ab.second;
        ans = ans*pow(base,ex);
    }
    return ans/a;
}

void solve(){
    int n;
    cin>>n;
    vector<bool> per(n+1,true);
    vector<int> ans;
    ans.eb(1);
    for(int i=2;i<=n;i++){
        if(primes[i] == true && per[i] == true){
            ans.eb(i);
            per[i] = false;
            for(int j = 2*i;j<=n;j+=i){
                if(per[j] == true && hp[j] == i){
                    int a = j;
                    ans.eb(a);
                    per[j] = false;
                    int ax = j*lp[j];
                    if(ax>n) continue;
                    per[ax] = false;
                    ans.eb(ax);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    } cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    // sieve
    primes[0]=primes[1]=false;
    for(int i=2;i<=N;i++){
        if(primes[i] == true){
            hp[i] = lp[i] = i;
            for(int j=2*i;j<=N;j+=i){
                primes[j] = false;
                hp[j]=i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }


    int t;
    cin>>t;
    while(t--){
        solve();
    }


    return 0;
}