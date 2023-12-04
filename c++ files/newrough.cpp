#include<iostream>
using namespace std;
bool func(int n, int k){
    long long int x;
    long long int y;
    bool ans=true;
       // Solution
       x=0;
       y=0;
        while(2*x+k*y<=n){
            while(2*x+k*y<=n){
                if(2*x+k*y==n){
                    return true;
                } else{
                    y++;
                }
            }
            y=0;
            if(2*x+k*y==n){
                return true;
            } else{
                x++;
            }
        }
        return false;
    }
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n;
        long long int k;
        cin>>n>>k;
        // solution
        if(func(n,k)==true){
            cout<<"Yes\n";
        } else{
            cout<<"No\n";
        }
    }
}