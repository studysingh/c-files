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
class LinkedList{
public:
    Node* head = NULL;
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        } cout<<endl;
    }
    void insertAtTail(int x){
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
        } else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp -> next;
            }
            temp->next = new_node;
        }
    }
    void insertAtHead(int x){
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
        } else{
            new_node->next = head;
            head = new_node;
        }
    }
};
// Find the middle element of the linked list using slow ans fast pointer concept
int middleElement(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    int ans = slow->val;
    return ans;
}
// Find whether a cycle is present in a linked list or not
//1-2-3-4-5
//      /   \ 
//     10    6
//      \  /
//      9-8-7
// In this linked list there is a cycle which starts from 4 and go on and again meet at 4 after 10
bool detectCycle(Node* head){
    // We can solve the problem by using slow and fast pointer approach . 
    // Logic :-> Suppose two persons are moving with speed x and 2x respectively
    //if they are moving on a circular track then they will definitely meet.
    if(head==NULL){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}
void cycleToOpen(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* cycleMeet;
    // Finding the meeting point
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cycleMeet = slow;
            break;
        }
    }
    //Traversing from starting and the meeting point (Floyd's Cycle Finding Algorithm)
    Node* start = head;
    while(true){
        if(start->next == cycleMeet->next){
            cycleMeet->next = NULL;
            break;
        }
        start = start->next;
        cycleMeet = cycleMeet->next;
    }
    return;
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    Node* temp = ll.head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = ll.head;
    cycleToOpen(ll.head);
    ll.display();
    // cout<<detectCycle(ll.head);
    return 0;
}