#include<iostream>
using namespace std;
// Print all the permutations of the string
void permutation(string input, string permutate="", int i=0){
    if(i==input.length()){
        cout<<permutate<<endl;
        permutate.clear();
        return;
    }
    for(int j=0;j<input.length();j++){
        permutate.insert(j,1,input[i]);
        permutation(input, permutate, i+1);
    }
}
int main(){
    string s="as";
    permutation(s);
    return 0;
}