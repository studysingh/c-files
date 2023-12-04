#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int a=0;a<t;a++){long long int n;// No. of sectors
    long long int x;// Pointing sector digit
    long long int p; // Maximum force applied
    cin>>n>>x>>p;
    bool check=true;
    for(int i=1;i<=p;i++){
        long long int l=0;
        // Checking if any l exist for the condition to be true
        while(l<=(p*(p+1))/(2*n)-(n-x)/n){
            if(((n-x)+l*n)==(i*(i+1))/2){
                check=false;
                break;
            } else{
                check=true;
            }
            l++;
        }
        if(check==false){
            break;
        }
    }
    if(check==true){
        cout<<"No\n";
    } else{
        cout<<"Yes\n";
    }
    }
}