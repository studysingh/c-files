#include<iostream>
#include<vector>
using namespace std;
// Print the sum of first n natural number
int sum(int n){
    if(n==0){
        return 0;
    }
    return n+sum(n-1);
}
// Tower of Hanoi  
// Time complexity -> pow(2, n)
// ORDER OF DISKS-> Increasing from top to bottom  --- i.e, topest is 1 , then 2 , then 3 , then 4, and so on and bottomest is n
// ALGORITHM  
// 1. First transfer n-1 disk from src to helper
// 2. Transfer nth disk from src to destination
// 3. Transfer n-1 disk from helper to destination
void tower(string src, string helper, string destination , int n){
    // base case
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<destination<<endl;
        return;
    }
    tower(src, destination, helper, n-1);  // step 1 of algorithm
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<destination<<endl;// step 2 of algorithm i.e, moved bottom disk n from src to dest
    tower(helper, src, destination, n-1); // step 3 of algorithm
}
// Print the string in reverse
void reverse(string str, int i=0){
    if(i==str.length()){
        return;
    }
    reverse(str, i+1);
    cout<<str[i];
}
// Print the first and last occurence of an element in the string
void occurence_element(string str, char ch, int &first , int &last,  int i=0){
    // Base case
    if(i==str.length()){
    cout<<first<<endl<<last;
        return;
    }
    // self work
    if(str[i]==ch && first==-1){  // if character is seen first time then we will update first from -1 to i
        first=i;
    }
     if(str[i]==ch){  // Every time we see the character, we will update value of last; and at last we will get last occurence
        last=i;
        occurence_element(str, ch, first, last, i+1);
    } else{
        occurence_element(str, ch, first, last, i+1);
    }
}
// Check if the given array is strictly sorted or not
bool check_sort(vector<int> v, int i=1){
    // Base case : we will reach to last index only if our array before last index is sorted so we returned true
    if(i==v.size()){
        return true;
    }
    if(v[i-1]<v[i]){
        // if condition is true we will check for next indexes
        return check_sort(v,i+1);
    } else{
        // if array is unsorted at any point we will return false
        return false;
    }
}
// Move all character ch to the end of the string str
string move_ch(string str, char ch, int &count, int i=0){ // count reads the no. of times the character ch came
  // Base Case when the recursion completes we append the character ch count times
    if(i==str.length()){
        str.append(count,ch);
        return str;
    }
    if(str[i]==ch){
        // after erase the index does not change because the character is erased
        str.erase(i,1);
        count+=1;
        return move_ch(str, ch, count,i);
    } else{
         return move_ch(str, ch, count,i+1);
    }
}
// Remove duplicates in the string
    vector<bool> v(26,false); // This is the map in which we have stored the value as false
string duplicate(string str, string &new_str, vector<bool> &v,  int i=0){
    // Base Case
    if(i==str.length()){
        return new_str;
    }
    // If v[str[i]-'a'] is false we will append the character and change it to true ELSE we will proceed further
    if(v[str[i]-'A']==false){
        new_str.append(1,str[i]);
        v[str[i]-'A']=true;
        return duplicate(str, new_str, v, i+1);
    } else{
        return duplicate(str, new_str, v, i+1);
    }
}
// Print all the subsequence of a string
// Time Complexity -> pow(2,n) where n is the length of string
void subsequence(string str, string new_str, int i=0){
    // base case
    if(i==str.length()){
        cout<<new_str<<endl;
        return;
    }
    // if str[i] is added
    subsequence(str, new_str+str[i], i+1);
    // if str[i] is not added
    subsequence(str, new_str, i+1);
}
// Keypad combination
vector<string> map={" ",".,","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string input, string combination="", int i=0, int k=0){
    // Base case
    if(i==input.length()){
        cout<<combination<<" ";
        return;
    }
    string map_value=map[input[i]-'0'];  // map string with associated keys 
    for(int j=0;j<map_value.length();j++){
        keypad(input,combination+map_value[j], i+1); // recursion
    }
}
int main(){
    string str;
    getline(cin, str);
    keypad(str);
    return 0;
}