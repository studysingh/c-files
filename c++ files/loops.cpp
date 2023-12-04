#include<iostream>
using namespace std;
// counting number of digits in  a number
int count(int n){
    int count=0;
    while(n>0){
        n/=10;
        count++;
    }
    return count;
}
// sum of digits of a number
int sumOfDigit(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
// reversing the number
int reverse(int n){
    int ans=0;
    while(n>0){
        ans*=10;
        ans+=n%10;
        n/=10;
    }
    return ans;
}
// sum of alternate series 1-2+3-4+5.......n
int alternateSum(int noOfTerms){
    int sum=0;
    for(int i=1;i<=noOfTerms;i++){
        if(i%2==1){
            sum+=i;
        } else{
            sum-+i;
        }
    }
    return sum;
}
// power function
int pow(int base, int exponent){
    int power=1;
    for(int i=1;i<=exponent;i++){
        power*=base;
    }
    return power;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<pow(n,m);
}