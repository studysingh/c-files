#include<bits/stdc++.h>
using namespace std;
// check if even or odd
void evenOdd(int n){
    if(1&n) cout<<"Odd\n";
    else cout<<"even\n";
}
// unsetting bit
void unSetBit(int &a , int i){
    int mask = ~(1<<i);
    a = a & mask;
}
//finding subset of an array using bitmasking 
// We store the numbers using bits in method bitmasking
vector<vector<int>> subsets(vector<int> &v){
    int n = v.size();
    int nSet = 1<<n;
    vector<vector<int> > ans;
    for(int i=0;i<nSet;i++){
        vector<int> set;
        for(int j=0;j<n;j++){
            if((1<<j)&i) set.emplace_back(v[j]);
        }
        ans.emplace_back(set);
    }
    return ans;
    // Time Complexity -> O(2^n * n)
}
void print(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        cout<<i+1<<"          [";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        } cout<<"]"<<endl;
    }
}
// converting decimal to binary
int dtob(int x){
    int factor = 1;
    int ans = 0;
    while(x>0){
        ans += factor*(x%2);
        factor*=10;
        x/=2;
    }
    return ans;
}
// Uppercase to Lowercase
char utol(char ch){
    // both the methods can be used
    // return (1<<5)|ch;
    return ch | ' ';
}
char ltou(char ch){
    // return ~(1<<5) & ch;
    return ch & '_';
}
int main(){
    vector<int> v = {1,2,3};
    vector<vector<int>> ans = subsets(v);
    print(ans);
}