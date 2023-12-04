#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* prev;
    Node* next;
    Node(int x){
        val = x;
        prev = NULL;
        next = NULL;
    }
};
class DoublyLL{
public:
    Node* head;
    Node* tail;
    DoublyLL(){
        head = NULL;
        tail = NULL;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        } cout<<endl;
    }
    void insertAtHead(int x){
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
            tail = new_node;
        } else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    void insertAtTail(int x){
        Node* new_node = new Node(x);
        if(tail == NULL){
            head = new_node;
            tail = new_node;
        } else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    void insertAtK(int x , int k){
        Node* new_node = new Node(x);
        if(k==1){
            insertAtHead(x);
            return;
        } else{
            Node* prevptr = head;
            for(int i = 1; i<k-1 ; i++){
                prevptr = prevptr->next;
            }
            Node* nextptr = prevptr->next;
            prevptr->next = new_node;
            new_node->prev = prevptr;
            if(nextptr!=NULL){ // When position is given for the insertion of tail
            new_node->next = nextptr;
            nextptr->prev = new_node;
            }
        }
    }
    void deleteAtK(int k){
        if(head==NULL){
            return;
        }
        if(k==1){
            Node* toRemove = head;
            head = head -> next;
            free(toRemove);
            return;
        }
        Node* prevptr = head;
        for(int i = 1; i<k-1 ;i++){
            prevptr = prevptr->next;
        }
        if(prevptr->next->next == NULL){
            Node* toRemove = prevptr -> next;
            prevptr->next = NULL;
            free(toRemove);
            return;
        }
        Node* toRemove = prevptr->next;
        Node* nextLink = prevptr->next->next;
        prevptr->next = nextLink;
        nextLink->prev = prevptr;
        free(toRemove);
        return;
    }
    void reverse(){
        // changing the links of the links as prev to next and prev to next
        Node* current = head;
        while(current){
            Node* nextPtr = current -> next;
            current->next = current -> prev;
            current->prev = nextPtr;
            current = nextPtr;
        }
        // swaping the head and tail
        Node* new_head = tail;
        tail = head;
        head = new_head;
    }
    bool palindrome(){
        Node* start = head;
        Node* end = tail;
        while(start!=end && start->next != end){ // first condition for odd and second is for even no. of nodes
            if(start->val!=end->val){
                return false;
            }
            start = start->next;
            end = end->prev;
        }
        return true;
    }
};
// Given the head of a doubly linked list , delete the nodes whose neighbours have the same value. Traverse the list from right to left.
/*
For example , INPUT : 1 2 2 1 2
Output : 1 2 2
*/
Node* neighbour(Node* head){
    Node* current = head;
    while(current -> next != NULL){
        current = current -> next;
    }
    Node* tail = current;
    Node* traversing = tail->prev; // traversing starts from the second last element of the linked list to avoid segmentation fault as the tail->next has not assigned any value. That is the null pointer
    while(traversing -> prev){
        Node* prevPtr = traversing -> prev;
        Node* nextPtr = traversing -> next;
        if(prevPtr->val == nextPtr->val){
            Node* toRemove = traversing;
            prevPtr->next = nextPtr;
            nextPtr->prev = prevPtr;
            free(toRemove);
        }
        traversing = prevPtr;
    }
    return head;
}
int main(){
    DoublyLL ll;
    int n;
    cout<<"Enter the length of the linked list : ";
    cin>>n;
    for(int i = 0; i<n ; i++){
        int x;
        cin>>x;
        ll.insertAtTail(x);
    }
    ll.display();
    DoublyLL lll;
    lll.head = neighbour(ll.head);
    lll.display();
}