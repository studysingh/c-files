#include<iostream>
#include<stack>
#include<math.h>
typedef long long ll;
using namespace std;

// Question 1
/*
we can find its solution on the leetcode
Design a stack that supports push, pop , top , and retrieving the minimum element in constant time.
Implement the MinStack class : 
1.MinStack() initialize the stack object
2. void push(int val) pushes the element val onto the stack.
3.int top() gets the top element of the stack.
4. int getMin() retrieves the minimum element in the stack.
5. void pop() pops the element from the stack
You must implement a solution with O(1) time complexity for each function.
Assumption : Methods pop , top and getMin operations will always be called on non-empty stacks .
*/

class MinStack{
public:
    stack<int> st;
    stack<int> min_num;
    int mini;
    MinStack(){
        mini = INT32_MAX;
    }
    void push(int val){
        st.push(val);
        mini = min(mini,val);
        min_num.push(mini);
    }
    void pop(){
        st.pop();
        min_num.pop();
        
    }
    int top(){
        return st.top();
    }
    int getMin(){
        return min_num.top();
    }
};


// Question 2
/*
Find the minimum number of brackets that we need to remove to make the given bracket sequence balanced .
for ex ., "[{(})]" 
output = 2
explanation : [{}] or [()]
*/
// this code is not working . it is wrong
int makeBalancedSequence(string str){
    stack<char> openings;
    int count = 0;
    for(int i=0; i<str.length() ; i++){
        if(str[i] == '(' || str[i] == '['  || str[i] == '{'){
            openings.push(str[i]);
        } else{
            if(!openings.empty()){
                if(str[i] == '}' && openings.top() == '{'){
                    openings.pop();
                } else if(str[i] == ']' && openings.top() == '['){
                    openings.pop();
                } else if(str[i] == ')' && openings.top() == '('){
                    openings.pop();
                } else{
                    stack<char> temp = openings;
                    while(!temp.empty()){
                        char ch = temp.top();
                        temp.pop();
                        count++;
                        if(ch == str[i]){
                            openings = temp;
                            break;
                        }
                    }
                }
            } else{
                count++;
            }
        }
        
    }
    cout<<openings.size()<<endl;
    count += openings.size();
    return count;
}


int main(){
    // cout<<"Hello Interview Questions \n";
    // string str = "[{(})]";
    // cout<<makeBalancedSequence(str);
    cout<<INT32_MIN;
    return 0;
}