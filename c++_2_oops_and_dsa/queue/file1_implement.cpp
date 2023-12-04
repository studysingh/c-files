/*
FIFO -> First In First Out
It is a linear data structure
// Operations
enqueue -> this operation will help us to add the new element in the queue
dequeue -> this operation will help us to remove new element in the queue
Front -> this operation will give us the element which comes first
*/

#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    int size = 0;
public:
    Queue(){
        head = NULL;
        tail = NULL;
    }

    void enqueue(int x){
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
            tail = new_node;
        } else{
            tail->next = new_node; // adding the element at the tail
            tail = new_node;
        }
        size++;
    }

    void dequeue(){
        // if there is no node
        if(head == NULL){
            return;
        }
        Node* to_remove = head;
        head = head -> next;
        // if there was a single node only
        if(head == NULL){ // updated head
            tail = NULL;
        }
        free(to_remove);
        size--;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        if(head == NULL){
            return true;
        } else{
            return false;
        }
    }

    int front(){
        if(head == NULL){
            return INT32_MIN;
        }
        return head->val;
    }

};

int main(){
    Queue qu;
    qu.enqueue(5);
    qu.enqueue(50);
    qu.enqueue(45);
    qu.enqueue(58);
    while(!qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.dequeue();
    }
    return 0;
}
//5 50 45 58