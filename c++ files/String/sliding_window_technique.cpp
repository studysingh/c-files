// Given a binary string and an integer k. Return the maximum no. of consecutive 1's after the fliping the 0's at most k times
// Input : String 101110001 and k=3
// Output : 7
#include<iostream>
#include<vector>
using namespace std;
// Time Complexity -> O(n) where n is the length of the string
// Space Complexity -> O(1)
int answer(string input, int k){
    int start=0;
    int end=0;
    int zero_count=0;
    int max_length=0;
    for(;end<input.size();end++){ // Extending the window
        if(input[end]=='0'){
            zero_count++;
        }
        while(zero_count>k){
            if(input[start]=='0'){
                zero_count--;
            }
            start++; // Contracting the window
        }
        max_length=max(max_length,end-start+1);
    }
    return max_length;
}
int main(){
    cout<<"Hello India\n";
    string input;
    cout<<"Enter the binary string ->";
    cin>>input;
    int k;
    cout<<"Enter k ->";
    cin>>k;
    cout<<answer(input,k);
    return 0;
}