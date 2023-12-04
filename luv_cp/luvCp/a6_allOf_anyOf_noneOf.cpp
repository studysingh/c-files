#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={3,5,30,0,5,-5,78};
    cout<<all_of(v.begin(),v.end(),[](int x){return x>0;}); // return true if all the element follow the given condition
    cout<<endl;
    cout<<any_of(v.begin(),v.end(),[](int x){return x==0;}); // return true if any of the given element satisfies the condition
    cout<<endl;
    cout<<none_of(v.begin(),v.end(),[](int x){
        return (x%2==25);
    }); // Returns true if none of the element satisfies the condition
}