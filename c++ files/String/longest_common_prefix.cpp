// Find the longest common prefix among the array of strings
// For example, [ans, ant, and];
// Output: "an"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string longest_common_prefix(vector<string> v){
    // Logic->
    // If we sort the array we will get the maximum variance in first and last element. The common part of first and last element will
    // be the common part of the all strings


    // Sorting the array 
    sort(v.begin(), v.end());

    // Comparing last and first string
    string first=v[0];
    string last=v[v.size()-1];
    int i=0;
    int j=0;
    string ans="";
    while(i<first.length() && j<last.length()){
        if(first[i]==last[j]){
            ans+=first[i];
            i++;
            j++;
        } else{
            break;
        }
    }
    return ans;
}
// Method 2
// Logic-> Take first string constant and compare it with the other strings and find the common minimum length and take out substring 
// of minimum common length
string longest_common_prefix2(vector<string> v){
    string base_str=v[0];
    int ans_length=base_str.size();

    for(int i=1;i<v.size();i++){

        int j=0;
        while(j<base_str.length() && j<v[i].length() && base_str[j]==v[i][j]){
            j++;
        }

        ans_length=min(ans_length,j);
    }

    
    string ans=base_str.substr(0,ans_length);
    return ans;
}
int main(){
    cout<<"Hello INDIA!\n";
    int n;
    cin>>n;
    cout<<"Enter strings: ->\n";
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Longest common prefix: "<<longest_common_prefix2(arr);
}