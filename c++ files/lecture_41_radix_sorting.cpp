#include<iostream>
#include<vector>
using namespace std;
void count_sort(vector<int> &v, int pos){
    // Making frequecy table for size 10 i.e., [0,9]
    vector<int> freq(10);
    int n=v.size();
    for(int i=0;i<n;i++){
        freq[(v[i]/pos)%10]++; // (v[i]/pos)%10 gives the digit at the pos
    }
    // Cumulative frequency
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }
    // filling the answer array
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[(v[i]/pos)%10]]=v[i];
    }
    // copying the ans array to vector v
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
    return;
}
void radix_sort(vector<int> &v){
    int n=v.size();
    // Finding the maximum element of the array so that we can find the maximum digit's position .
    int max_ele=INT32_MIN;
    for(int i=0;i<n;i++){
        max_ele=max(max_ele,v[i]);
    }
    // Sorting the elements on the basis of position of digit
    for(int pos=1;(max_ele/pos)>0;pos*=10){
        count_sort(v,pos);
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    radix_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}