#include<iostream>
#include<stack>
using namespace std;


// copy stack
stack<int> copy_stack(stack<int> input){
    stack<int> temp;
    while(!input.empty()){
        int x = input.top();
        input.pop();
        temp.push(x);
    }
    stack<int> ans;
    while(!temp.empty()){
        int x = temp.top();
        temp.pop();
        ans.push(x);
    }
    return ans;
}


// Inserting element at the bottom
stack<int> insertAtBottom(stack<int> &st , int x){
    // Base condition
    if(st.empty()){
        st.push(x);
        return st;
    }
    // Recursive Work and self work
    int storedEl = st.top();
    st.pop();
    insertAtBottom(st , x);
    st.push(storedEl);
    return st;
}


// Reversing stack in same place
stack<int> reverseInPlace(stack<int> &input){
    if(input.empty()){
        return input;
    }
    int el = input.top();
    input.pop();
    reverseInPlace(input);
    insertAtBottom(input , el);
    return input;
}


int main(){
    // Making stack
    int n ;
    cout<<"Enter the length of the stack : \n";
    cin>>n;
    stack<int> st;
    for(int i=0; i<n ; i++){
        int x;
        cin>>x;
        st.push(x);
    }

    stack<int> temp = st;
    for(int i=0; i<n ; i++){
        cout<<temp.top()<<" ";
        temp.pop();
    }

    stack<int> ans = reverseInPlace(st);
    cout<<"\n Reversed Stack \n";
    for(int i =0;i<n;i++){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}
/*
4
3
2
1
*/