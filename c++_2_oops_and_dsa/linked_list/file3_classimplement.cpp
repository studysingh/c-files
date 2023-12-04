#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};
class LinkedList{
public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    void insertAtTail(int x){
        Node* new_node= new Node(x);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        return;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};
// Printing element of a linked list in reverse order
void reverseDisplay(Node* head){
    if(head==NULL){
        cout<<"NULL";
        return;
    }
    reverseDisplay(head->next);
    cout<<"<-"<<head->val;
}
// Reversing the linked list iteratively 
void reverseLL(Node* &head) {
    Node* prev = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* temp = current->next;  // Store the next node before modifying current
        current->next = prev;  // Reverse the link to the previous node
        prev = current;  // Move prev and current pointers one step forward
        current = temp;
    }
    head = prev;  // Update the head of the reversed linked list
}
// Reversing the linked list using the recursion
Node* reverse(Node* &head, int k , Node* prev=NULL){
    if(head == NULL || k == 0){
        return prev;
    }
    Node* temp = head->next;
    head->next = prev;
    return reverse(temp , k-1 ,head);
}
// Given the head of a linked list. Reverse the nodes of the list k at a time, and return the modified list.
// Example, ll= 1->2->3->4->5->6->7->8
// k=2
// answer= 2->1->4->3->6->5->8->7
// k=4
// answer= 4->3->2->1->8->7->6->5
Node* reverseK(Node* &head , int k){
    /*Logic:->
    1. Firstly reverse the first k elements of the list
    2. Reverse the next k elements of the list using recursion
    3. Linking the sublist by connecting next element of the head to the first element of the next linked list  */

    // Reversing the linked list's first k elements
    Node* prev = NULL;
    Node* current = head;
    int count = 0;
    while(current!=NULL && count<k){
        Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        count++;
    }

    if(current!=NULL){
        // Recursively linking the sublinkedLists
        Node* new_head = reverseK(current , k);
        head->next = new_head;
    }
    
    return prev;
}
int main(){
    LinkedList ll;
    LinkedList lll;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ll.insertAtTail(x);
    }
    ll.display();
    lll.head = reverseK(ll.head , 3);
    lll.display();
    return 0;
}