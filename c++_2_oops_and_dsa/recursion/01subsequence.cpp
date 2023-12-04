#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void fun(string &str , vector<string> &v , string s = "" , int i=0){
    if(i == str.size()){
        v.push_back(s);
        return;
    }
    // taking
    s += str[i];
    fun(str , v , s , i+1);
    s.pop_back(); // backtrack
    fun(str ,v,s,i+1);
}
int main(){
    string str;
    cin>>str;
    vector<string> v;
    fun(str , v);
    for(int i=0;i<v.size();i++){
        if(v[i] == "") v[i] = "empty";
        cout<<"("<<v[i]<<")";
    }
}