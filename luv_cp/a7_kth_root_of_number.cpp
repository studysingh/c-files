#include<bits/stdc++.h>
using namespace std;
double precision = 1e-10;

double multiply(double n, int k){
    double pro = 1;
    for(int i=0;i<k;i++){
        pro*=n;
    }
    return pro;
}

int main(){
    cout<<"______________This program will give you the kth root of the number n using binary search__________________\n";
    double n;
    cout<<"Enter the number n of which you want to find the root ";
    cin>>n;
    cout<<"Enter the value of k  ";
    int k;
    cin>>k;
    double lo, hi;
    lo = 1;
    hi = n;
    while(hi-lo>precision){
        double mid = (lo+hi)/2;
        if(multiply(mid,k)<n){
            lo = mid;
        } else{
            hi = mid;
        }
    }
    cout<<lo<<" "<<hi<<" "<<pow(n,1.0/k)<<endl;
}