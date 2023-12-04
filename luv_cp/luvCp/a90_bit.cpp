#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long M = (1e9);
int hcf(int a, int b){
    if(a==0) return b;
    return hcf(b%a,a);
}
// Recursive power function
int power(int a ,int b){
    if(a==0 && b==0) return INT32_MIN;
    if(b==0) return 1;
    int x = power(a,b/2);
    if(b%2==0) return (x%M * x%M)%M; // x*x
    else return ((x%M * x%M)%M * (a%M))%M; // x*x*a
}
// Iterative power function using binary exponentiation
ll powIt(ll a , ll b){
    if(a==0 && b==0) return INT32_MIN;
    ll ans = 1;
    while(b>0){
        if(1&b){
            ans = (ans%M * a%M)%M; // ans *= a
        };
        a = (a%M * a%M)%M; // a *= a
        b = b>>1;
    }
    return ans;
}
// if value of a and M are very large
// binary multiplication
ll binMultiply(ll x , ll y){
    ll ans = 0;
    while(y>0){
        if(1&y){
            ans = (ans+x)%M;
        }
        x = (x+x)%M;
        y>>=1;
    }
    return ans;
}
ll powItt(ll a , ll b){
    if(a==0 && b==0) return INT32_MIN;
    ll ans = 1;
    while(b>0){
        if(1&b){
            ans = binMultiply(a,ans)%M; // ans *= a
        };
        a = binMultiply(a,a); // a *= a
        b = b>>1;
    }
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<powItt(a,b)<<endl;
    cout<<powIt(a,b)<<endl;
    cout<<binMultiply(a,b)<<endl;
}