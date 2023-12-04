#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// This code is valid for the float entries which lies between 0 and 1 only
void bucket_sort(vector<float> &v){
    int n=v.size();
    // Making bucket array to store the floating values
    vector<vector<float>> bucket(n,vector<float>());
    for(int i=0;i<n;i++){
        int index=n*v[i];
        bucket[index].push_back(v[i]);
    }
    // Sorting every bucket
    for(int i=0;i<n;i++){
        if(bucket[i].empty()!=1){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }
    // Filling the vector v after sorting
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
        v[k++]=bucket[i][j];
        }
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<float> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    bucket_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    } cout<<endl;
    return 0;
}