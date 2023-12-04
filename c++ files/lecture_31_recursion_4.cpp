#include<iostream>
using namespace std;
// print the number from 1 to n using recursion in increasing order
void printNum(int n){
    // base condition
    if(n==1){
        cout<<n<<" ";
        return;
    }
    if(n<1){
        return;
    }
    // recursive work
    printNum(n-1);
    // self work
    cout<<n<<" ";
}
// Print the first k multiples of the number n in increasing order
void printMultiple(int num, int k){
    // base condition
    if(k==1){
        cout<<num<<" ";
        return;
    } 
    // recursive work
    printMultiple(num, k-1);
    // self work
    cout<<k*num<<" ";

}
// Given a number n. Find the sum of the natural numbers till n but with alternate signs.
// 1-2+3-4+5-6.......n
int alternateSum(int n){
    if(n==1){
        return 1;
    }
    if(n%2==0){
        return alternateSum(n-1)-n;
    } else{
        return alternateSum(n-1)+n;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<alternateSum(n);
    return 0;
}