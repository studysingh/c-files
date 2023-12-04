// Two words are said to be anagram of each other if on rearranging the letters of one string we get another word
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Hello India\n";
    string s,t;
    cout<<"String 1: ";
    getline(cin,s);
    cout<<"String 2: ";
    getline(cin,t);
    vector<int> freq(26,0);
    if(s.length()==t.length()){
    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++; // for character of string 1 we increase the frequency
        freq[t[i]-'a']--; // for character of string 2 we decrease the frequency
    }
    bool check=true;
    // If final frequency of each element is 0 then they occured same no. of time
    for(int i=0;i<26;i++){
        if(freq[i]==0){
            check=true;
        } else{
            check =false;
            break;
        }
    }
    if(check==true){
        cout<<"YES\n";
    } else{
        cout<<"NO\n";
    }
    } else{
        cout<<"Length of strings are not equal.\n";
    }

    return 0;
}