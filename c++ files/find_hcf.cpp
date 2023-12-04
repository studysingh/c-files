#include<iostream>
#include<vector>
using namespace std;
// hcf using euclid's algorithm
int hcf(int a, int b){
    if(a==0){
        return b;
    }
    return hcf(b%a, a);
}
// Finding hcf of the full array
int hcf_arr(vector<int> v, int i=1){

    // Base Condition
    // because hcf(0,a)=a so at the last index we assume the element to be zero
    if(i==v.size()){
        return 0;
    }

    // Recursive Work
    // hcf2 is the hcf of two elements i and its previous element
    int hcf2=hcf(v[i],v[i-1]);

    // we got the hcf2 of two numbers by recursion. we find the hcf of hcf2 and the next element
    return hcf(hcf2,hcf_arr(v,i+1)); 

}
// finding hcf of the range of elements in the array where left index is included and right index is not included
// Note that we used 1-based indexing
// Example: vector is {2,18,12,15}
// given l=2 and r=4
// Output: 6
// given l=2 and r=5
//Output: 3
int hcf_arr_range(vector<int> v, int l , int r){

    // Base Case 
    // When we encounter the right most element we return zero because hcf(0,a)=a
    if(l==r-1){
        return 0;
    }

    // Recursive Work
    // hcf2 is the hcf of the leftmost and leftmost+1 element 
    int hcf2=hcf(v[l],v[l-1]);

    // we got the hcf2 of two numbers by recursion. we find the hcf of hcf2 and the next element
    return hcf(hcf2,hcf_arr_range(v,l+1,r));
}
int main(){
    int n;
    cin>>n;
    cout<<"Input: ->\n";
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Enter left and right index:->";
    int l, r;
    cin>>l>>r;
    cout<<"Hcf-> "<<hcf_arr_range(v, l, r);
    return 0;
}