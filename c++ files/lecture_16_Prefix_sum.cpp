#include<iostream>
#include<vector>
using namespace std;
// Storing prefix sum of a vector
void prefix_sum(vector<int> &v){
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
    }
    return;
}
                // check if an array can be broken into two subarrays where sum of both the subarrays is equal
bool arr_break(vector<int> v){
    vector<int> prefix;
    bool check=true;
    // prefix sum vector
    prefix.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        int element=prefix[i-1]+v[i];
        prefix.push_back(element);
    }
    // suffix sum vector
    vector<int> suffix;
    suffix.push_back(v[v.size()-1]);
    int a=v.size()-2;
    for(int i=1;i<v.size();i++){
        int element=suffix[i-1]+v[a--];
        suffix.push_back(element);
    }
    // checking condition
    for(int i=0;i<v.size();i++){
        if(prefix[i]==suffix[v.size()-2-i]){ // condition
            cout<<"The sum is "<<prefix[i]<<endl;
         check=false;
         return !(check);
        }
    }
    return !(check);
}
                    // Answer q queries of Printing sum of the numbers between the given indices(answering according to 1 based indexing)
void sum_idx(vector<int> v, int q){
    // finding prefix sum
    vector<int> prefix_sum;
    prefix_sum.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        int element=prefix_sum[i-1]+v[i];
        prefix_sum.push_back(element);
    }
    // queries answered
    for(int i=0;i<q;i++){
        // taking input as index
        int start, end;
        cout<<"Enter the starting index: ";
        cin>>start;
        cout<<"Enter the last index: ";
        cin>>end;
        //  sum for start>1
        if(start>1 && start<=v.size() && end<=v.size() && end>1){
        int ans=prefix_sum[end-1]-prefix_sum[start-2];
        cout<<ans;
        } else if(start==1 && end<=v.size() && end>1){ // sum for start == 1
            cout<<prefix_sum[end-1];
        } else{
            cout<<"Invalid Input!";
        }
        cout<<endl;
    }
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
    cout<<"Enter the number of queries: ";
    int q;
    cin>>q;
    sum_idx(v,q);
    return 0;
}