#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// Check if a bracket sequence is balanced or not
bool balanceSequence(string str){
    stack<int> storeOpening;
    int i =0;

    if(str.length()%2==1){
        return false;
    }
    
    while(str[i] != '\0'){
        if((str[i] == '(' || str[i] == '[' || str[i] == '{')){ // opening bracket
            storeOpening.push(str[i]);
            i++;
        } else{
            // closing bracket
            char ch = str[i];
            if(ch == ')' && !storeOpening.empty() && storeOpening.top() == '('){
                storeOpening.pop();
            } else if(ch == ']' && !storeOpening.empty() && storeOpening.top() == '['){
                storeOpening.pop();
            } else if (ch == '}' && !storeOpening.empty() && storeOpening.top() == '{'){
                storeOpening.pop();
            } else{
                return false;
            }
            i++;
        }
    }
        // if stack is not empty then some opening bracket is not neutralised means sequence is not balanced
        return storeOpening.empty();
}


// You are given an array of integers . You have to find the array of its next greater element . if no next greater element exist , give INTMIN value to it
// e.g., input array = [4,6,3,1,0,9,5,6,7,3,2]
// Output array = [6,9,9,9,9,Intmin,6,7,intmin,intmin,intmin]
vector<int> nextGreaterElement(vector<int> input){
    int size = input.size();
    vector<int> ans(size,INT32_MIN);
    stack<int> wait;
    wait.push(0);

    for(int i=1; i<size; i++){
        if(input[i]>input[wait.top()]){ // when we found the first greater element then we check it for the elements waiting in the stack if it is greater then it is the answer element
        while(!wait.empty() && input[i]>input[wait.top()]){
            ans[wait.top()] = input[i];
            wait.pop();
        }
        wait.push(i); // After checking for all the element we push the current index in the stack
        } else{ // if element is not greater then we push it in the stack
            wait.push(i);
        }
    }

    return ans;
}


// Given a series of N daily price quotes for a stock , we need to calculate the span of the sotck's price for all N days. The span of the stock's price in one day is the maximum number of the consecutive days ( starting from that day and going backward ) for which the stock price was less than or equal to the price of that day .
vector<int> stockSpan(vector<int> price){
    int size = price.size();
    vector<int> ans;
    stack<int> stockPrice;
    for(int i=0;i<size;i++){
        stockPrice.push(price[i]);
        int count=0;
        stack<int> temp = stockPrice;
        while(!temp.empty() && temp.top() <= price[i]){
            count++;
            temp.pop();
        }
        ans.push_back(count);
    }
    return ans;
}


int main(){
    vector<int> input;
    int n;
    cin>>n;
    cout<<"enter the element\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    cout<<"Result\n";
    vector<int> result = stockSpan(input);
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
}