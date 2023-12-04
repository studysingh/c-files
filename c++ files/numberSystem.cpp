#include<iostream>
using namespace std;
// function for converting from decimal to binary question 1
long binary(int n){
    long sum=0;
    int i=1;
    while(n>0){
        sum+=(n%2)*i;
        i*=10;
        n/=2;
    }
    return sum;
}
// converting from binary to decimal
int decimal(long n){
    int ans=0;
    int multiplier=1;
    while(n>0){
        ans+=(n%10)*multiplier;
        n/=10;
        multiplier*=2;
    }
    return ans;
}
// comparing two binary numbers question 3
int compare(long num1, long num2){
   if(decimal(num1)>decimal(num2)){
    return decimal(num1);
   } else{
    return decimal(num2);
   }
}
int main(){
    long a,b;
    cin>>a>>b;
    cout<<compare(a,b);
    return 0;
}