#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
// swaping two numbers
void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
    return;
}
                           // sorting array of 0s and 1s
// method 1
void sort(vector<int> &v){
    // counting number of zeroes
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            count++;
        }
    }
    // substituting elements again as 0 and 1
    for(int i=0;i<count;i++){
        v[i]=0;
    }
    for(int i=count;i<v.size();i++){
        v[i]=1;
    }
    cout<<endl;
    return;
}
// method 2 two pointer approach
void sort2(vector<int> &v){
    int start=0;
    int end=v.size()-1;
    while(start<end){
        if(v[start]==0){
            start++;
        } 
        if(v[end]==1){
            end--;
        } else{
            swap(v[start], v[end]);

        }
    }
}
            // Sorting of element as even in starting and odd in ending
void sort_even(vector<int> &v){
    int left=0;
    int right=v.size()-1;
    while(left<right){
        if(v[left]%2==1 && v[right]%2==0){
            swap(v[left],v[right]);
            left++;
            right--;
        } else{
            left++;
            right--;
        }
    }
    return;
}
       // absolute value function
int abs(int a){
    if(a>0){
        return a;
    } else{
        return -a;
    }
}
        // given an integer array sorted in non decreasing order. Return an array of the squares of each number sorted in non decresing order
void square_array(vector<int> &v){
     int left=0;
     int right=v.size()-1;
     int a;
     vector<int> ans;
     while(left<=right){
        if(abs(v[left])>=abs(v[right])){
            a=v[left]*v[left];
            ans.push_back(a);
            left++;
        } else{
            a=v[right]*v[right];
            ans.push_back(a);
            right--; 
        }
     }
     reverse(ans.begin(),ans.end());
     for(int i=0;i<v.size();i++){
        cout<<ans[i]<<" ";
     }
     cout<<endl;
     return;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    square_array(v);
    return 0;
}