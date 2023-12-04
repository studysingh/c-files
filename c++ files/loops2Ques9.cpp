// checking that a number can be expressed as sum of two prime numbers or not
#include<iostream>
using namespace std;
// function for checking prime number
bool prime(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
        count++;
        }
    }
    if(count==2){
        return true;
    } else{
        return false;
    }
}
int main(){
    cout<<"Enter the number: ";
    int n;
    cin>>n;
    // n is odd
    if(n%2==1){
        if(prime(n-2)==true){  // for odd number check n-2 is a prime number or not
            cout<<2<<'+'<<n-2<<endl;
            cout<<"Yes";
        } else{
            cout<<"No";
        }
    }
    // n is even
    bool check=true;
    if(n%2==0){
        for(int i=2;i<n;i++){
            if(prime(n-i)==true&&prime(i)==true){ // using loop for checking both numbers are prime or not
                check=false;
                cout<<i<<'+'<<n-i<<endl;
                cout<<"Yes";
                return 0;
            } else{
                check=true; // condition if no combination is found for the number n then check is always true
                continue;
            }
        }
         if(check==true){
        cout<<"no";
    }
    return 0;
    }
}