// Two string are said to be isomorph of each other if they are one to one mapped
// For Example,
// add and egg
// Here a -> e and d->g . These are isomorph
// add and geg
// Here a->g and d->e as well as d->g So it is not isomorphs
#include<iostream>
#include<vector>
using namespace std;
bool isIsomorph(string s1, string s2){
    // Logic-> We store the index in the two vectors of each string and then compare them if the index stored in them are not equal . 
    // Then they are not isomorph
    if(s1.length()!=s2.length()){ // The length of the strings are not equal
        return false;
    }
    // The vectors are of size 128 because the capital and small alphabet ascii value goes till 128
    vector<int> v1(128,-1);
    vector<int> v2(128,-1);
    // Traversing the string
    for(int i=0;i<s1.size();i++){
        if(v1[s1[i]]!=v2[s2[i]]){ // If the value at ascii index are not equal i.e., they are not equally mapped
            return false;
        }
        v1[s1[i]]=v2[s2[i]]=i;  // Updating the index value in the vector 1 and 2
    }
    return true;
}
int main(){
    string s1,s2;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;
    if(isIsomorph(s1,s2)){
        cout<<"These are isomorph \n";
    } else{
        cout<<"These are not isomorph\n";
    } 
    return 0;
}