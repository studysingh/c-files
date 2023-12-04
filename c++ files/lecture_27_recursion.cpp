#include<iostream>
using namespace std;
// finding factorial of a number
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial(n-1);
}
// finding nth fibonacci number
int fib(int a, int b, int n){
    if(n==1){
        return a;
    }
    if(n==2){
        return b;
    }
    int prev=fib(a,b,n-1);
    int prevOfPrev=fib(a,b,n-2);
    return prev+prevOfPrev;
}
int main(){
    int n;
    // cin>>n;
    int a=1;
    int b=2;
    int d=factorial(6);
    cout<<d;
    return 0;
}
