#include<iostream>
#include<vector>
using namespace std;
// Taking input vector
void inputVector(vector<int> &v, int n){
    // base condition 
    if(n==1){
        int element;
        cin>>element;
        v.push_back(element);
        return;
    }
    inputVector(v,n-1);  // recursive work
    // self work
    int element;
    cin>>element;
    v.push_back(element);
}
// Printing a vector
void printVector(vector<int> &v, int n){
    // base condition
    if(n==0){
        return;
    }
    printVector(v,n-1);  // recursive work
    // self work
    cout<<v[n-1]<<" ";
    if(n==v.size()){  // at the last element it will continue from next line
        cout<<endl;
    }
}
// Finding a number x in the vector
bool find(vector<int> v, int x, int i=0){
    // base condition
    if(i==v.size()){
        return false;
    } 
    // self work
    if(v[i]==x){
        return true;
    } else{
        return find(v,x,i+1); // it will tell that x is present in range[1,v.size()] or not
    }
}
// Print all the index where element x is present 
void printXindex(vector<int> v, int x, int i=0){
    // base condition
    if(i==v.size()){
        return;
    }
    // self work
    if(v[i]==x){
        cout<<i<<" ";
    }
    // recursive work
    printXindex(v,x,i+1);
    // it will print the next line when the function ends
    if(i==0){
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    inputVector(v,n);
    printVector(v,v.size());
    int x;
    cout<<"Enter x";
    cin>>x;
    printXindex(v,x);
    return 0;
}