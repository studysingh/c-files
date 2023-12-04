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


void solve(){
    /*
    Divide the number k starting from the end by its lowest prime and do it till k>1 it will give us the highest no. of hcf till n which are possible
    */
    int n;
    cin>>n;
    vector<bool> per(n+1,true);
    vector<int> ans;
    for(int i=n;i>1;i--){
        if(per[i] == true){
            int k = i;
            int ld = lp[i];
            while(k>1 && per[k] == true && k%ld == 0){
                ans.eb(k);
                per[k] = false;
                k/=ld; // it will give us the distinct hcfs as many as possible
                ld = lp[k]; // computing the new lowest prime of the new k
            }
            }
        }
    ans.eb(1);
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