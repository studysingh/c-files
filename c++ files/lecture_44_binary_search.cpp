#include<iostream>
#include<vector>
using namespace std;
// Binary Search Looping
// Time: O(log(n))
// Space: O(1)
int binary_search(vector<int> v, int target){
    int n=v.size();
    int low=0; // it is the starting point
    int high=n-1; // it is the ending point
    while(low<=high){
        // If we have value of low and high  very large nearly INT_MAX then the integer mid will overflow so we use modified formula of m
        //mid which is mid=low+(high-low)/2 in place of mid=(high-low)/2
        int mid=low+(high-low)/2;
        if(v[mid]==target){ // element found
            return mid;
        } else if(v[mid]<target){ // left side of the array is discarded
            low=mid+1;
        } else{ // right side of the array is discarded
            high=mid-1;
        }
    }
    return -1; // if not found return -1;
}
// Binary search recursively
/*
Time : O(log(n))
Space : O(log(n))
*/
int binarySearch(vector<int> v, int target, int low, int high){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(target==v[mid]){
        return mid;
    } else if(v[mid]<target){
        return binarySearch(v, target, mid+1, high);
    } else{
        return binarySearch(v, target, low, mid-1);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<=n;i++){
        int target;
        cin>>target;
        cout<<binarySearch(v,target,0,n-1);
    }
    return 0;
}