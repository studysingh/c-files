#include<iostream>
using namespace std;
// sum of the digits of a number
int digitSum(int n){
    // base condition
    if(n==0){
        return 0;
    }
    // self work
    int ans=n%10 + digitSum(n/10); // finding digitSum(n/10) is the recursive work
    return ans;
    // time complexity O(digit) || space complexity O(digit)
}
// finding power of p^q
// Approach 1
int power(int p, int q){
    // base condition
    if(q==0){
        return 1;
    }
    // self work
    int ans=p*power(p,q-1);   // calculating power(p,q-1) is the recursive work
    return ans;
    // time complexity -> O(q) and space complexity -> O(q)
}
// Approach 2
int Power(int p, int q){
    // base condition
    if(p==0 && q==0){
        return -2456947;  // returned any garbage value
    }
    if(q==0){
        return 1;
    }
    int halfPow=Power(p,q/2); // recursive work
    // self work
    if(q%2==0){
        return halfPow*halfPow;
    } else{
        return p*halfPow*halfPow;
    }
    // Time complexity -> O(log(q)) || Space Complexity -> O(log(q))
}
int main(){
    int n,m;
    cin>>n>>m;
    return 0;
}