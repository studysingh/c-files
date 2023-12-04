#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
// taking input
void input(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    return;
}
// printing an array
void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}
                        // total number of pairs in the array whose sum is equal to the target sum
int sumPair(int arr[],int n, int target){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                count++;
            }
        }
    }
    return count;
}
            // finding unique number in a given array where all elements are being repeated twice with one value being unique
void unique(int arr[], int n){
    // making repeating element as -1
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                arr[i]=arr[j]=-1;
            }
        }
    }
    // printing the element which is not -1
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
            cout<<arr[i];
        }
    }
    cout<<endl;
    return;
}
                            // find the second largest element in the given array
void secLar(int arr[], int n){
    int max=INT32_MIN;
    // finding largest element
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    // making all largest element to -infinity
    for(int i=0;i<n;i++){
        if(arr[i]==max){
            arr[i]=INT32_MIN;
        }
    }
    // finding second largest element
    max=INT32_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"The second largest element in the array is "<<max;
    return;
}
                        // rotating array by k steps using ans array
void rotate(int arr[], int n, int k){
    int ans[n];
    int idx=0;
    int a=k%n;
    // last n-a elements
    for(int i=a;i<n;i++){
        ans[idx++]=arr[i];
    }
    // first a element 
    for(int i=0;i<a;i++){
        ans[idx++]=arr[i];
    }
    print(ans,n);
    return;
}
             // rotating array by k steps in place using vector
void rotate1(vector<int> v, int k){
    int a=k%v.size();
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin()+(v.size()-a));
    reverse(v.begin()+(v.size()-a),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    } cout<<endl;
    return;
}
int main(){
    // int n;
    // cout<<"Enter the size of the array: ";
    // cin>>n;
    // int arr[n];
    // input(arr,n);
    // print(arr,n);
    // for(int i=0;i<5;i++){
    //     int k;
    //     cout<<"enter rotation: ";
    //     cin>>k;
    // rotate(arr,n,k);
    // }
    int k;
    cin>>k;
    vector<int> v;
    v={1,2,3,4,5};
    rotate1(v,k);
    cout<<endl;
    int arr[5]={1,2,3,4,5};
    rotate(arr,5,k);
    return 0;
}