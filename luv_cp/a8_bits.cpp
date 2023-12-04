#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// To check if ith bit is set or not
bool checkBitset(ll a , ll i){
    // We take the number whose ith bit is the onlu setbit
    ll x = 1<<i;
    return (x&a);
}
// Setting a bit
void setBit(ll &a , ll i){
    ll mask = 1<<i;
    a = a | mask;
}
// Unsetting a bit
void unSetBit(ll &a , ll i){
    ll mask = ~(1<<i);
    a = a & mask;
}
// Toggling the bit 
void toggleBit(ll &a , ll i){
    ll mask = 1<<i;
    a = a^mask;
}
// Counting setBits
/*
__builtin_popcount(x) for integers
__builtin_popcountll(x) for long long int
*/
int  countSetBit(ll a){
    int count = 0;
    for(int i=31;i>=0;--i){
        if((1<<i & a) != 0){
            count++;
        }
    }
    return count;
}
// Compliment of a number
ll compliment(ll a){
    // finding the largest 2 ki power
    if(a==0){
        return 1;
    }
    int powCount = 0;
    while(pow(2,powCount)<=a){
        powCount++;
    }
    if(pow(2,powCount) < a){
        powCount++;
    }
    ll mask = (1<<powCount) -1;
    return a^mask;
}
// Checking power of two
bool checkPowerOfTwo(ll &n){
    ll a = n&(n-1);
    if(a) return false;
    else return true;
}
// Swaping the two numbers
void swaping(ll &a , ll &b){
    a = a ^ b;
    b = a ^ b; // a
    a = a^b; //  b
}
int main(){
    ll a = 5;
    ll b = 6;
    swaping(a,b);
    cout<<a<<b;
}