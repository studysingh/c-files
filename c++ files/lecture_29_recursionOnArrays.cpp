#include<iostream> 
#include<vector>
#include<cmath>
using namespace std;
// Given an array, Print all the elements of the array recursively.
void print(vector<int> v, int idx){
    // base condition
    if(idx==v.size()){
        cout<<endl;
        return;
    }
    cout<<v[idx]<<" "; // self work
    print(v, idx+1);  // recursive work
    // Time Complexity -> O(v.size()) and Space Complexity -> O(v.size())
}
// Print the maximum value of the array
int maximum(vector<int> v, int idx=1){
    // base condition
    if(idx==v.size()-1){
        return max(v[idx],v[idx-1]);
    }
    int ans=max(v[idx],v[idx-1]);  // self work
    return max(ans,maximum(v,idx+1)); // recursion work
    // Time Complexity -> O(v.size()) || Space Complexity -> O(v.size()-1)
}
// Find the sum of the elements of the array
int arraySum(vector<int> v, int i=0){
    // base condition
    if(i==v.size()-1){
        return v[i];
    }
    // self work
    return v[i]+arraySum(v,i+1);  // calculating arraySum(v,i+1) is the recursive work
    // Time Complexity -> O(v.size()-1) || Space Complexity -> O(v.size()-1)
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    cout<<arraySum(v);
    return 0;
}