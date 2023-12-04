#include<iostream>
using namespace std;
void push(int *stack, int x, int *top);
void pop(int *stack, int *top);
void peek(int *stack);
int main(){
    int stack[100];
    int c;
    int x;
    int top=-1;
    cout<<"Enter 1 for push 2 for pop and 3 for peek the element of the stack: ";
    cin>>c;
    switch(c){
        case 1 : 
        cout<<"Enter the element to be pushed back : ";
        cin>>x;
        push(stack,x,&top);
        break;
        case 2 :
        pop(stack,&top);
        case 3 : 
        peek(stack);
    }
    return 0;
}
void push(int *stack, int x, int &top){
    top++;
    stack[top]=x;
}
