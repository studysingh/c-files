#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
    return;
}
void bubblesort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){  // No. of Passes
        for(int j=0;j<n-1-i;j++){ // No. of checking in each Pass
// Note that the code is written for increasing order. For decreasing order , we can just change the sign of comparison
            if(v[j]>v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
    return;
}
void bubblesort_optimize(vector<int> &v){ // This code can be said optimized if and only if elements are very near to their right 
//place . We have used flag in the fourth line to check if any swap happened or not happened. If not happened we will break the loop
    int n=v.size();
    for(int i=0;i<n-1;i++){  // No. of Passes
      bool flag=false;  
        for(int j=0;j<n-1-i;j++){ // No. of checking in each Pass
// Note that the code is written for increasing order. For decreasing order , we can just change the sign of comparison
            if(v[j]>v[j+1]){
                swap(v[j], v[j+1]);
                flag=true;
            }
        }
        if(flag==false){
            break;
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
    bubblesort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}