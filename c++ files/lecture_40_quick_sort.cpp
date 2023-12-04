#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &v, int l, int r){
    // pivot element is considered as the last element of the vector
    int pivot=v[r];
    int j=l-1; // it traverse the elements smaller than the pivot elements only
    for(int i=l;i<r;i++){
        // if element is smaller than the pivot then, the element is swapped   
        if(v[i]<pivot){
            j++;  // increased j to swap the elements if element is less than the pivot
            swap(v[i],v[j]);
        }
    }
    // Now , after the loop all small elements than the pivot are in beginning and larger in the end
    // So, it is the time to pivot the element at its correct place
    j+=1;
    swap(v[j],v[r]); // pivot is pivoted at its correct place
    return j;
}
void quick_sort(vector<int> &v, int l, int r){ // Here l is the starting index and r is the ending index 
    // Base Case 
    // When array has only one element i.e., when l>=r
    if(l>=r){
        return;
    }
    int pivot_idx=partition(v,l,r); // gives the pivot element index 
    quick_sort(v,l,pivot_idx-1); // sort the element till the pivot element
    quick_sort(v,pivot_idx+1,r);  // sort the element after the pivot element
}
int main(){
    cout<<"Hello World!\n";
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    quick_sort(v,0,n-1);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}