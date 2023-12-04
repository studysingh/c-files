#include<iostream>
#include<vector>
using namespace std;
// Find the first occurence of the element x, given that the array is sorted. If no occurence is found then return -1
// Input: 2 5 5 5 6 6 8 9 9 9 
// Target: 5
// Output: 1
int firstOccurence(vector<int> v, int target, int low, int high){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(target==v[mid]){
        if(v[mid-1]!=target){ // If previous element is not target then we return the index else we discard the right array and search 
        // again in left side
            return mid;
        } else{
            return firstOccurence(v, target, low, mid-1);
        }
    } else if(v[mid]>target){
        return firstOccurence(v, target, low, mid-1);
    } else{
        return firstOccurence(v, target, mid+1,high);
    }
}
// Find the square root of the non negative value n. Return its integral part
// Example: 11->3  15->3 16->4  27->5  111->10
int root(int n){
    // Here search space is [0,n] so low =0 and high = n;
    int low=0;
    int high=n;
    int ans=-1;
    // if mid^2 <=high we update the answer and check for highest integer else we check the left array and leave discarded array
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Input: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<5;i++){
        int target;
        cin>>target;
    cout<<firstOccurence(v,target,0,n-1);
    }
}