#include<iostream>
#include<vector>
using namespace std;
// A rotated sorted array is a sorted array on which rotations operation has been performed some number of times. Given a rotated sorted
// array , find the index of the minimum element in the array. Follow 0- based indexing. It is guaranteed that all the element in the 
// array are unique.
// Input: 3 4 5 1 2
// Output: 3
int rotated_arr_minimum(vector<int> v){
    int lo=0;
    int hi=v.size()-1;
    // checking if array is sorted
    if(v[lo]<v[hi]){
        return lo;
    } else{ // if array is not sorted we used binary search
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid-1]>v[mid]){ // Minimum element is mid
            return mid;
        } 
        if(v[mid]>v[mid+1]){ // Minimum element is mid+1
            return mid+1;
        }
        if(v[lo]<v[mid]){ // if mid element is bigger than lo element then it means we will find minimum in right side else left side
            lo=mid+1;
        } else{
            hi=mid-1;
        }
    }
    }
}
// A rotated sorted array is a sorted array on which rotations operation has been performed some number of times. Given a rotated sorted
// array , find the index of the target element in the array. Follow 0- based indexing. It is guaranteed that all the element in the 
// array are unique.
// Arr: 4 5 6 7 8 9 10 1 2 3 
// Target: 9
// Output: 5
int rotated_arr_target(vector<int> v, int target){
    int min_idx=rotated_arr_minimum(v);
    int n=v.size();
    int hi=n-1;
    int lo=0;
    if(v[hi]==target){
        return hi;
    } else if(target<v[hi]){
     int lo=min_idx;
     if(v[min_idx]==target){
        return min_idx;
     }
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
        if(v[mid]==target){
        return mid;
    } else if(v[mid]<target){
        lo=mid+1;
    } else{ hi=min_idx-1;
        }
     }
    } else{  hi=min_idx;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(v[mid]==target){
        return mid;
    } else if(v[mid]<target){
        lo=mid+1;
         } else{
        hi=mid-1;
    }
    }
 }
 return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    for(int i=0;i<10;i++){
    int target;
    cout<<"Enter";
    cin>>target;
    cout<<rotated_arr_target(input,target);
    }
    return 0;
}