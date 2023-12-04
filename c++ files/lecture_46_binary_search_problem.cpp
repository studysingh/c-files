#include<iostream>
#include<vector>
using namespace std;
// Given a mountain array of length n>=3. Return the index i such that
//  arr[0]<arr[1]<arr[2]<........<arr[i-1]<arr[i]>arr[i+1]>.....arr[n-1]
// Input: 0 4 1 -1
// Output: 1
int peak_in_mountain(vector<int> v){
    int n=v.size();
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
            return mid;
        } else if(v[mid]>v[mid-1] && v[mid]<v[mid+1]){
            lo=mid+1;
        } else if(v[mid]<v[mid-1] && v[mid]>v[mid+1]){
            hi=mid-1;
        }
    }
    return -1;
}
// Find an element in 2D Array
bool binary_search_2D(vector<vector<int>> v, int target){
    int n=v.size();
    int m=v[0].size();
    int hi=n*m-1;
    int lo=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int x=mid/m; // Gives row no.
        int y=mid%m; // Gives col no.
        if(v[x][y]==target){
            cout<<"Index of the element is ("<<x<<","<<y<<")"<<endl;
            return true;
        } else if(v[x][y]>target){
            hi=mid-1;
        } else{
            lo=mid+1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> v;
    v={{1,2,4,6},{12,34,56,78},{79,80,81,90}};
    for(int i=0;i<14;i++){
        int target;
        cout<<"Target: ";
        cin>>target;
        cout<<binary_search_2D(v,target)<<endl;
    }
    return 0;
}