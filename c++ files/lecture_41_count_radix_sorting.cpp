#include<iostream>
#include<vector>
using namespace std;
// This code will work only for positive element's array
void count_sort(vector<int> &v){
    int n=v.size();
    // Finding maximum element
    int max_ele=INT32_MIN;
    for(int i=0;i<n;i++){
        max_ele=max(max_ele,v[i]);
    }
    // Making frequency array of max_ele+1 length
    vector<int> freq(max_ele+1);
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }
    // Making cumulative frequency
    for(int i=1;i<freq.size();i++){
        freq[i]+=freq[i-1];
    }
    // Making answer array and filling
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[v[i]]]=v[i];
    }
    // Copying answer array to vector
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
}
// Count sort when element include in the array may be negative
void count_sort_negative(vector<int> &v){
    int n=v.size();
    // Finding minmimum element
    int min_ele=INT32_MAX;
    for(int i=0;i<n;i++){
        min_ele=min(min_ele,v[i]);
    }
    // Finding maximum element
    int max_ele=INT32_MIN;
    for(int i=0;i<n;i++){
        max_ele=max(max_ele,v[i]);
    }
    // Making frequency array of max_ele+1 length 
    vector<int> freq(max_ele+1-min_ele);
    for(int i=0;i<n;i++){
        freq[v[i]-min_ele]++; // if min_ele is -ve then we subtract the minimum to avoid out of bount error 
    }
    // Making cumulative frequency
    for(int i=1;i<freq.size();i++){
        freq[i]+=freq[i-1];
    }
    // Making answer array and filling
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[v[i]-min_ele]]=v[i];
    }
    // Copying answer array to vector
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    count_sort_negative(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}