#include<iostream>
using namespace std;
// taking input
void input(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    return;
}
// printing an array
void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
    return;
}
// finding largest element index in the array
int largest(int arr[], int n){
    int max=INT64_MIN;
    int idx=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
            idx=i;
        }
    }
    return idx;
}
int main(){
  int n;
  cout<<"Enter the length of the array: ";
  cin>>n;
  int arr[n];
  input(arr,n);
  print(arr,n);
  cout<<"Which largest element do you want to find: ";
  int k;
  cin>>k;
  // making k-1 element as -infinity;
  for(int i=1;i<k;i++){ 
    // making all largest element as -infinity
    for(int i=0;i<n;i++){
        if(arr[largest(arr,n)]==arr[i]){
            arr[i]=INT32_MIN;
        }
    }
  }
  cout<<arr[largest(arr,n)];
  return 0;
}