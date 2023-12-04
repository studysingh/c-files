#include<iostream>
#include<string.h>
using namespace std;
// remove 'a' from the string
void charRemoval(string &s, char ch, int i=0){
    // base condition
    if(i==s.length()){
        return;
    }
    // self work
    // charRemoval(s,ch,i) and charRemoval(s,ch,i+1) is the recursive work
    if(s[i]==ch){  //note that if we find the character and it is erased then the index of next character shift at the previous index
        s.erase(i,1);
        charRemoval(s,ch,i);
    } else{
        // if character is not found then the next character is on the next index wrt. the currrent index
    charRemoval(s,ch,i+1);
    }
}
// check if the number is palindrome or not
// approach 1 without recursion
bool palindrome(int n){
    int temp=n;
    int reverse=0;
    while(n>0){
        reverse=reverse*10+n%10;
        n/=10;
    }
    if(reverse==temp){
        return true;
    } else{
        return false;
    }
}
int main(){
    for(int i=0;i<10;i++){
        int n;
        cin>>n;
   cout<< palindrome(n)<<endl;
    }
    return 0;
}