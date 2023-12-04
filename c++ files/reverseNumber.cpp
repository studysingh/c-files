#include<iostream>
using namespace std;
int main(){
  cout<<"Enter the number: ";
  int n;
  cin>>n;
  // Logic 
  int ans=0;
  while(n>0){
    ans=ans*10+n%10;
    n/=10;
  }
  cout<<ans;
  cin>>n;
  return 0;
}