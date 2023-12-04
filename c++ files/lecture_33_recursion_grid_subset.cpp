#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
// Number of Occurence of a character
int occur(string str ,char ch,  int i=0){
    // base case 
    if(i==str.size()){
        return 0;
    }
    // self work 
    if(str[i]==ch){
        return 1+occur(str, ch, i+1);
    } else{
        return occur(str, ch, i+1);
    }
}
// Find a target value x in the given array arr of length n.
bool find(int arr[] , int n, int x){
    // base case
    if(n==0){
        return false;
    } 
    // self work 
    if(arr[n-1]==x){
        return true;
    } else{
        return find(arr, n-1, x);  // recursive work
    }
}
// Given an array of length n integers, print sums of all subsets in it. Output sums can be in any order.
// Input : arr[] ={ 2,3}
// Output : 0 2 3 5
// Input : arr[] = {2,5,4}
// Output : 0 2 4 5 6 7 9 11
void subset_sum(int arr[] , int n, int sum=0){
    // base case
    if(n==0){
        cout<<sum<<" ";
        return;
    }
    subset_sum(arr,n-1,sum+arr[n-1]); // when element is included in the sum
    subset_sum(arr, n-1, sum);  // when element is not included in the sum
}
// The problem is to count all the possible paths on an m * n grid from top left to bottom right grid.
// Having constraint that from each cell you can either move only to right or down direction.
// For example,  2 * 3 have output 3
//   3 * 3 have output 6
//  3*4 have output 10
long long int grid(int n, int m){
    // base case
    // when we reached the coordinate (1,1), we have only one way to go from (1,1) to (1,1)
    if(n==1 and m==1){
        return 1;
    }
    // if we are out of grid we have no other ways to go inside of grid
    if(n<1 or m<1){
        return 0;
    }
    // self work
    return grid(n-1, m)+ grid(n, m-1);
}
int main(){
    int n, m;
    cin>>n>>m;
    int j=grid(n,m);
    cout<<j;
    return 0;
}