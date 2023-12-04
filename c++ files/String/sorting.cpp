#include<iostream>
#include<vector>
using namespace std;
string sort_str(string str){
    int n=str.size();
    vector<int> freq(26,0);
    // Making freqency table
    for(int i=0;i<n;i++){
        int idx=str[i]-'a';
        freq[idx]++;
    }
    // Filling the string
    int j=0;
    for(int i=0;i<26;i++){
        while(freq[i]--){
        str[j++]=i+'a';
        }
    }
    return str;
}
int main(){
    string str;
    getline(cin,str);
    cout<<str<<endl;
    cout<<sort_str(str);
    return 0;
}