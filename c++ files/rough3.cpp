#include<iostream>
#include<vector>
using namespace std;
int binary(vector<int> v, int target, int lo, int hi){
    if(lo>hi){
        return -1;
    }
    int mid=lo+(hi-lo)/2;
    if(v[mid]==target){
        return mid;
    } else if(v[mid]<target){
        return binary(v, target, mid+1,hi);
    } else{
        return binary(v,target, lo, mid-1);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Target: ";
    int target;
    cin>> target;
    cout<<binary(v,target,0,n-1);

    return 0;
}