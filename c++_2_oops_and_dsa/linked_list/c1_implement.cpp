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
class Circular{
public:
    Node* head;
    Circular(){
        head = NULL;
    }
    void display(){
        Node* temp = head;
        do{
            cout<<temp->val<<" ";
            temp = temp -> next;
        } while(temp!=head);
        cout<<endl;
    }
    void insertAtStart(int x){
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
            new_node->next = head;
        } else{
            Node* temp = head;
            do{
                temp = temp->next;
            }while(temp->next!=head);
            temp->next = new_node;
            new_node->next = head;
            head = new_node;
        }
    }
    void insertAtEnd(int x){
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
            new_node->next = head;
        } else{
            Node* temp = head;
            do{
                temp = temp -> next;
            }while(temp->next!=head);
            temp->next = new_node;
            new_node->next = head;
        }
    }
};
int main(){
    Circular ll;
    cout<<"Enter the length of the linked list : ";
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        int x;
        cin>>x;
        ll.insertAtEnd(x);
    }
    ll.display();
    return 0;
}