#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v,int l, int mid, int r){
    // size of temperory array an and bn
    int an=mid+1-l;
    int bn=r-mid;
    int a[an], b[bn]; // created two temperory array
    // filling the element in the array a till the middle index
    for(int i=0;i<an;i++){
        a[i]=v[l+i];
    }
    // filling the element in the array b after the middle index
    for(int i=0;i<bn;i++){
        b[i]=v[mid+1+i];
    }
    int i=0; // i traverse the array a
    int j=0; // j traverse the array b
    int k=l; // k traverse the vector v to fill the array
    // filling the element in sorted order
    while(i<an && j<bn){
        if(a[i]<b[j]){
            v[k++]=a[i++];
        } else{
            v[k++]=b[j++];
        }
    }
    while(i<an){
        v[k++]=a[i++];
    }
    while(j<bn){
        v[k++]=b[j++];
    }
    return;
}
// Note : -> 
//           in function merge_sort l stands for left index from where we start the sorting and r is the index until where we want to sort the array
void merge_sort(vector<int> &v, int l, int r){
    // Base Case
    // when array has only one element l>=r
    if(l>=r){
        return;
    }
    int mid=(l+r)/2; // finding mid index
    merge_sort(v,l,mid); // sorting the array till the middle index
    merge_sort(v,mid+1,r); // sorting the array after the middle index
    merge(v,l,mid,r); // merging the two sorted array 
}
int main(){
    cout<<"Hello World!\n";
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    merge_sort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}