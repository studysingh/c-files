#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void insertion_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){ // starting from 1 because we are assuming that the first element is sorted
        int current=arr[i];
        // finding the correct position for the current in the sorted array
        int j=i-1; // we will traverse the sorted array and insert the current
        while(j>=0 && arr[j]>current){
            arr[j+1]=arr[j]; // shifting the sorted array elements by 1 position
            j--;
        }
        arr[j+1]=current; // insert the current element at the j+1 position 
    }
    return;
}
void bubble_sort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j+1], v[j]);
                flag=true;
            }
        } 
        if(flag=false){
            break;
        }
    }
    return;
}
void selection_sort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[min_idx]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            swap(v[min_idx], v[i]);
        }
    }
    return;
}
int main(){
    int n;
    cout<<"Enter length: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    insertion_sort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    } cout<<endl;
    return 0;
}