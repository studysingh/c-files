#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> max_window(vector<int> &v , int k){
    vector<int> ans;
    deque<int> dq;
    int n = v.size();
    dq.push_back(v[0]);
    int idx = 0;
    int i = 1;
    while(i<n){
        int j = 0;
        while(j<k && i<n){
            if(v[idx] < v[i]){
                dq.pop_front();
                dq.push_front(i);
                idx++;
            } else if(v[i]>=dq.front()){
                dq.push_front(i);
            } else{
                dq.push_back(i);
            }
            i++;
            j++;
        }
        j--;
        ans.push_back(v[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int> v;
    for(int i = 0;i<8;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter the value of k";
    int k;
    cin>>k;
    vector<int> ans = max_window(v,k);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}