#include<iostream>
#include<vector>
using namespace std;
// Given a string , we have to find out all its subsequences of it.
// For example, Input: abc
// Output: a b c ab ac abc bc
// Method 1 using deletion
void string_part(string str,int n){  // here n denotes the length of the string
    // base case when n==0 we will return the str in which element are deleted
    if(n==0){
        cout<<str<<endl;
        return;
    }
    string_part(str, n-1); // once element did not delete
    str.erase(n-1,1);
    string_part(str, n-1);  // once element is deleted

}
//Method 2 using appending
void string_subsequence(string str, string new_string, int i=0){
    // base case when new string is formed we will print it
    if(i==str.length()){
        cout<<new_string<<endl;
        return;
    }
    string_subsequence(str,new_string+str[i] , i+1);  // once element is appended in the new string
    string_subsequence(str, new_string, i+1);  // once element is not appended in the new string
}
// keypad problem
string switches(char ch){
    string s;
    switch(ch){
        case '0': s=" ";
        break;
        case '1': s=".";
        break;
        case '2': s="abc";
        break;
        case '3': s="def";
        break;
        case '4': s="ghi";
        break;
        case '5': s="jkl";
        break;
        case '6': s="mno";
        break;
        case '7': s="pqrs";
        break;
        case '8': s="tuv";
        break;
        case '9': s="wxyz";
        break;
        default: s="";
    }
    return s;
}
void keypad(string str, string combination="", int i=0){
    // Base Case
    if(i==str.length()){
        cout<<combination<<endl;
        return;
    }
    string map_value=switches(str[i]); // mapped string
    for(int j=0;j<map_value.length();j++){
        keypad(str,combination+map_value[j],i+1); // recursion
    }
}
int main(){
    keypad("0213");
    return 0;
}