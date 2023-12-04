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
};class LinkedList{
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
// Checking the linked list to be palindrome or not
bool checkPalindrome(Node* head){
    if(head == NULL){
        return false;
    }
//Approach :->
//1. Find the middle element of the linked list .
//2. Reverse the 2nd half of the linked list by separatin it.
//3. Traverse the two linked list and check the linked list to be palindrome or not
// Step 1
Node* fast = head;
Node* slow = head;
Node* mid;
while(true){
    if(fast->next==NULL || fast->next->next==NULL){ // 1st condition for odd length and 2nd is for even length
        mid = slow->next;
        break;
    }
    slow = slow->next;
    fast = fast->next->next;
}
//Step 2
Node* prev = NULL;
Node* current = mid;
while(mid!=NULL){
    Node* temp = mid->next;
    mid->next = prev;
    prev = mid;
    mid = temp;
}
Node* reversed = prev;
//step 3
Node* start = head;
while(reversed!=NULL){
    if(reversed->val != start->val){
        return false;
    }
    reversed = reversed->next;
    start = start->next;
}
return true;
}
// Given the head of the linked list . Rotate the linked list by k steps
/*
e.g., 1 2 3 4 5 6 and k is 2
answer is 5 6 1 2 3 4
*/
Node* rotateByK(Node* head , int k){
    if(head == NULL){
        return NULL;
    }
    // Finding the length of the linked list and making the loop
    Node* temp = head;
    int length = 0;
    while(temp->next!=NULL){
        temp = temp->next;
        length+=1;
    }
    length+=1;
    temp->next = head;
    // Breaking the loop at length-k step
    k = (k % length);
    Node* breaking = head;
    int i = 1;
    while(i<(length-k)){
        breaking = breaking -> next;
        i++;
    }
    Node* ans = breaking -> next;
    breaking -> next = NULL;
    return ans;
}
// You are given the head of a singly linked-list . The list can be represented as : 
//L0 L1 L2 ........ Ln
//Reorder the list to be on the following form :
// L0 Ln L1 Ln-1 L2 Ln-2 .........
Node* reorder(Node* &head){
    if(head == NULL){
        return NULL;
    }
    // Finding the middle element
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    // Making the middle element to be common
    Node* prev = NULL;
    Node* current = slow->next;
    slow -> next = prev;
    prev = slow;
    // Reversing the linked list after the mid element
    while(current!=NULL){
        Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    // Linking the nodes of the linked list in the required order
    Node* temp1 = head;
    Node* temp2 = prev;
    while(temp1!=temp2){
        Node* store = temp1->next;
        temp1->next = temp2;
        temp1 = temp2;
        temp2 = store;
    }
    return head;
}
int main(){
    LinkedList ll;
    int n;
    cout<<"Enter the length of the linked list : ";
    cin>>n;
    for(int i = 0; i<n ; i++){
        int x;
        cin>>x;
        ll.insertAtTail(x);
    }
    ll.display();
    swapAdjacent(ll.head);
    ll.display();

}