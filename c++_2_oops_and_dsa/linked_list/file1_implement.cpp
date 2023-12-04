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
class ll{
public:
    Node* head;
    ll(){
        head = NULL;
    }
    // Insert at head
    void insertAtBegin(int x){
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
    }
    // Printing
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        } cout<<endl;
    }
    // Insert at tail
    void insertAtEnd(int x){
        Node* temp = new Node(x);
        Node* curr = head;
        if(curr == NULL){
            head = temp;
            return;
        }
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    // Deleting a node at kth position
    void deleting(int k){
        if(k<=0) return; 
        if(k==1){ // 1st position
            Node* toDelete = head;
            head = head->next;
            free(toDelete);
            return;
        }
        // other than 1st position
        Node* prev = head;
        for(int i=1;i<k-1;i++){
            if(prev->next == NULL) return;
            prev = prev->next;
        }
        if(prev->next == NULL) return;// invalid position
        Node* toDelete = prev->next;
        Node* toJoin = toDelete->next;
        prev->next = toJoin;
        free(toDelete);
    }
};
int main(){
    ll demo;
    demo.insertAtBegin(1);
    demo.insertAtBegin(2);
    demo.insertAtBegin(3);
    demo.insertAtBegin(4);
    demo.insertAtEnd(8);
    demo.insertAtEnd(9);
    demo.insertAtEnd(10);
    demo.insertAtEnd(11);
    demo.print();
    demo.deleting(-5);
    demo.print();
}