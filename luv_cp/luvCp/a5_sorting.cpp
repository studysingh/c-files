#include<bits/stdc++.h>
using namespace std;
bool cmp(int a , int b){
    return a>b;
}
bool comp(pair<int,int> a , pair<int,int> b){
    if(a.first!=b.first){
        return a.first<b.first;
    } else{
        return a.second>b.second;
    }
}
int main(){
    // vector<int> v;
    // for(int i=0;i<6;i++){
    //     int x;
    //     cin>>x;
    //     v.push_back(x);
    // }
    // sort(v.begin(), v.end() , cmp);
    // for(int i=0;i<6;i++){
    //     cout<<v[i]<<" ";
    // }
    vector<pair<int,int>> v={{1,2},{34,34},{2,4},{5,6},{5,8}};
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}