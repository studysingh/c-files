#include<iostream>
#include<vector>
using namespace std;
// Question->
// Given an integer array arr, move all 0's to the end of it while maintaining the relative order of the non-zero elements
// Note that you must do this in - place without making a copy of the array.
// Input: 0 5 0 3 42
// Output: 5 3 42 0 0 
void using_insertion_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int j=i-1;
        int element=arr[i];
        while(j>=0 && arr[j]==0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=element;
    }
}
void using_bubble_sort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1-i;j++){
            if(v[j]==0 && v[j+1]!=0){
                swap(v[j],v[j+1]);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    using_bubble_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<"  ";
    }
    return 0;
}