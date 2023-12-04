#include<iostream>
#include<stack>
using namespace std;
int main(){
    cout<<"Hello Stacks\n";
    stack<int> st; // defining the stack by including the stack header file
    st.push(5);
    cout<<st.top()<<endl; // to find the top of a stack
    st.push(54); // to insert the element in the stack
    cout<<st.top()<<endl;
    st.push(85);
    cout<<st.top()<<endl;
    st.push(50);
    cout<<st.top()<<endl;
    cout<<"Changes occur \n";
    cout<<st.size()<<endl; // to find the size of a stack
    cout<<st.empty()<<endl; // checks if the stack is empty or not
    st.pop(); // to delete the element from the stack
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
}