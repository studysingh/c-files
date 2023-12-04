#include<bits/stdc++.h>
using namespace std;
int main(){
    // auto keyword determines the datatype itself
    auto a=5;
    cout<<a;
    auto b = "an umbrella";
    cout<<endl<<b<<endl;
    //auto in iterator and loops
    vector<int> v={4,2,6,6,7,9,5,1};
    for(auto &val : v){ // value passed by reference
        cout<<val<<" ";
        val++;
    } cout<<endl;
    for(auto it = v.begin() ; it!=v.end() ; it++){
        cout<<(*it)<<" ";
    } cout<<endl;
    // Defining iterator
    vector<int> :: iterator iit;
    for(iit=v.begin();iit!=v.end();iit++){
        cout<<(*iit)<<" ";
    } cout<<endl;
}