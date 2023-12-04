#include<iostream>
using namespace std;

class StackArr {
private:
    int *arr;
    int top = -1;
    int capacity;
public: 
    StackArr(int size){
        capacity = size;
        arr = new int[capacity];
    }
    void push(int data){
        if(top == capacity -1){
            cout<<"Stack Overflow \n";
            return;
        }
        top++;
        arr[top] = data;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack Underflow \n";
            return;
        }
        top--;
        return;
    }
    int getTop(){
        if(top == -1){
            cout<<"Stack Underflow \n";
            return INT32_MIN;
        }
        return arr[top];
    }
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return (top == capacity-1);
    }
};

class Node {
public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

class StackLL{
private:
    Node* head = NULL;
    int capacity;
    int top = -1;
public:
    StackLL(int size){
        capacity = size;
    }
    void push(int x){
        if(top == capacity-1){
            cout<<"Stack Overflow \n";
            return;
        }
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
        } else{
            new_node->next = head;
            head = new_node;
        }
        top++;
    }
    int getTop(){
        if(top == -1){
            cout<<"Stack Underflow\n";
            return INT32_MIN;
        }
        return head->val;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == capacity - 1;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
        } else{
            Node* to_delete = head;
            head = head->next;
            top--;
            free(to_delete);
        }
    }
};
int main(){
    StackLL sl(4);
    sl.push(5);
    sl.push(540);
    sl.push(75);
    sl.push(54);
    sl.pop();
    sl.pop();
    sl.pop();
    sl.pop();
    cout<<sl.getTop();
}