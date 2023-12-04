#include<iostream>
#include<vector>
using namespace std;
// Arranging the elements in lexicographical (dictionary wise) order using selection sort
void dictionary(vector<string> &v){
    int n=v.size();
    for(int i=0;i<n;i++){
        int min_idx=i; // taking ith string as the smallest
        for(int j=i+1;j<n;j++){
            if(v[j].compare(v[min_idx])<0){ // if min_idx is greater than any elment in the unsorted vector then we update the min_idx
                min_idx=j;
            }
        }
        if(min_idx!=i){
            swap(v[min_idx], v[i]); // swaping element
        }
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dictionary(v);
    cout<<"Output-> \n";
    for(int i=0;i<n;i++){
        cout<<v[i]<<endl;
    }

    return 0;
}