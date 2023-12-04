#include<iostream>
// #include<string>
using namespace std;
// Finding the length of the string 
int getlength(char str[]){
    int length = 0;
    for(int i=0;str[i]!='\0';i++){
        length++;
    }
    return length;
}
// reverse a string
void reverse_str(char str[]){
    int n=getlength(str);
    int end=n-1;
    int start=0;
    while(start<end){
        swap(str[start++],str[end--]);
    }
    return;
}
// Check palindrome a string
bool palindrome_str(char str[]){
    int n=getlength(str);
    int start=0;
    int end=n-1;
    bool check = true;
    while(start<end){
        if(str[start]!=str[end]){
            return false;
        } else{
            start++;
            end--;
        }
    }
    return true;
}
int main(){
    char str[20];
    cin>>str;
    cout<<str<<endl;
    cout<<palindrome_str(str);
    return 0;
}