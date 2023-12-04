#include<iostream>
#include<cmath>
using namespace std;
// hcf of two numbers
int hcf(int a, int b){
    // base condition 
    if(b%a==0){
        return a;  // returning a is our self work
    }
    // recursive work
    return hcf(b%a , a);
}
// Given a number n. Print if it is an armstrong number of not
bool armstrong(int n, int temp, int d,  int reverse=0){
    // bases case as well as self work
    if(n==0){
        if(temp==reverse){
            return true;
        } else{
            return false;
        }
    }
    reverse+=pow(n%10,d);
    armstrong(n/10,temp,d,reverse); // recursive work
}
// There are N stones , numbered form 1,2,......N. For each i(1<=i<=N) , the height of stone is hi. There is a frog who 
// is initially at stone 1. He will repeat the following actions some number of times to reach stone N.
//    If the frog is currently on stone i, jump to stone i+1 or i+2 . Here , a cost of |hi-hj| is incurred, where j is the 
// stone to land on.
// Find the minimum possible cost incurred before the frog reaches stone N.
// Example: 
// INPUT : 4
// Hi[]= {10,30, 40, 20}
// OUTPUT: 30
int question(int arr[] , int n){
    int add=0;
    for(int i=0;i<n-2;i++){
        add+=min(abs(arr[i+2]-arr[i]),abs(arr[i+1]-arr[i]));
    }
    return add;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<question(arr,n);
    return 0;
}