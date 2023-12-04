#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string> m;
    m[4]="sandeep";
    m[3]="sfs";
    m[6]="eifj";
    m.insert({1,"sjdfk"});
    // for(auto a : m){
    //     cout<<a.first<<" "<<a.second<<endl;
    // }
    // map<int,string> :: iterator ab = m.begin();
    // while(ab!=m.end()){
    //     cout<<ab->first<<" "<<ab->second<<endl;
    //     ab++;
    // }
    for(auto i : m){
        cout<<i.first<<" "<<i.second <<endl;
    }
    // map<int,string> :: iterator it;
    // it = m.find(4)
    m.erase(m.begin());
    for(auto i : m){
        cout<<i.first<<" "<<i.second <<endl;
    }
}