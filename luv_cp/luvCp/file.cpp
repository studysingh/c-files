#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void print(multimap<ll,ll> m){
    cout<<"Modified multimap\n";
    auto it = m.begin();
    while(it != m.end()){
        cout<<(*it).first<<" "<<(*it).second<<endl;
        it++;
    }
}
int main(){
    // int t;
    // cin>>t;
    // while(t--){
    //     multimap<ll,ll> m;
    //     ll n,k;
    //     cin>>n>>k;
    //     for(ll i=0;i<n;i++){
    //         ll x;
    //         cin>>x;
    //         m.insert({x,i+1});
    //     }
    //     // print(m);
    //     // logic
    //     vector<ll> ans;
    //     while(!m.empty()){
    //         auto it = --m.end();
    //         ll val = (*it).first;
    //         auto newIt = m.find(val);
    //         val -= k;
    //         if(val>0){
    //             ll idx = (*newIt).second;
    //             // cout<<"    Loop 1   "<<endl<<"idx : "<<idx<<endl<<"val "<<val<<endl;
    //             m.insert({val,idx});
    //             m.erase(newIt);
    //             // print(m);
    //         } else{
    //             // cout<<"    Loop 2   "<<endl<<"idx : "<<(*newIt).second<<endl<<"val "<<val<<endl;
    //             ans.push_back((*newIt).second);
    //             m.erase(newIt);
    //             // print(m);
    //         }
    //     }
    //     // Printing the vector
    //     for(ll i=0;i<ans.size();i++){
    //         cout<<ans[i]<<" ";
    //     } cout<<endl;
    // }
    multimap<ll,ll> m;
    m.insert({3,2});
    m.insert({2,0});
    m.insert({2,4});
    m.insert({1,3});
    m.insert({2,3});
    m.insert({2,2});
    print(m);
}