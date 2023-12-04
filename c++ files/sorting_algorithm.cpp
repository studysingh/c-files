#include<iostream>
#include<vector>
using namespace std;
void bubble(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        bool check=false;
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                check=true;
            }
        }
        if(check==false){
            break;
        }
    }
    return;
}
void selection(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        int j=i+1;
        int min_idx=i;
        for(;j<n;j++){
            if(v[min_idx]>v[j]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            swap(v[i],v[min_idx]);
        }
    }
    return;
}
void insertion(vector<int> &v){
    int n=v.size();
    for(int i=1;i<n;i++){
        int current=v[i];
        int j=i-1;
        while(j>=0 and v[j]>current){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=current;
    }
    return;
}
void merge(vector<int> &v, int l, int mid, int r){
    int an=mid+1-l;
    int bn=r-mid;
    int a[an];
    int b[bn];
    for(int i=0;i<an;i++){
        a[i]=v[l+i];
    }
    for(int j=0;j<bn;j++){
        b[j]=v[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=l;
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
void mergeSort(vector<int> &v, int l, int r){
    if(l>=r){
        return;
    }
    int mid=(l+r)/2;
    mergeSort(v,l,mid);
    mergeSort(v,mid+1,r);
    merge(v,l,mid,r);
}
int partition(vector<int> &v, int l, int r){
    int pivot=v[r];
    int j=l-1;
    for(int i=l;i<r;i++){
        if(v[i]<pivot){
            j++;
            swap(v[j],v[i]);
        }
    }
    j++;
    swap(v[j],v[r]);
    return j;
}
void quickSort(vector<int> &v, int l, int r){
    if(l>=r){
        return;
    }
    int pivot_idx=partition(v,l,r);
    quickSort(v,l,pivot_idx-1);
    quickSort(v,pivot_idx+1,r);
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    quickSort(v,0,n-1);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    } cout<<endl;
    return 0;
}