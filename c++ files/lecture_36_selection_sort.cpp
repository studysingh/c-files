#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void selection_sort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        // Finding Minimum Element of the unsorted array
        int min_idx=i; // we assume that minimum element is in starting and then compare it with the next element of the unsorted array
        for(int j=i+1;j<n;j++){
            if(v[min_idx]>v[j]){
                min_idx=j;
            }
        }
        // Placing the minimum element of the unsorted array in the beginning of the unsorted array by swaping it.
        // Here sorted array is from 0 to i and unsorted array is from i to n
        if(min_idx!=i){
            swap(v[min_idx], v[i]);
        }
    }
    return;
}
int main(){
    int n;
    cout<<"Enter the length of the vector: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    selection_sort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}