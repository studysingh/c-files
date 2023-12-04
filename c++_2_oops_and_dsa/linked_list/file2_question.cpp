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
void display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    return;
}
void insert_at_head(Node* &head, int x){
    Node* new_node= new Node(x);
    new_node->next=head;
    head=new_node;
    return;
}
void deletion(Node* head, int pos){
    if(head==NULL){
        return;
    }
    if(pos==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    Node* prev;
    prev=head;
    for(int i=1;i<pos-1;i++){
        prev=prev->next;
    }
    Node* next;
    Node* temp=prev->next;
    next=prev->next->next;
    prev->next=next;
    free(temp);
    return;
}
void ques1(Node* &head){  // deleting the  alternating elements lying on the even node of linked list
    Node* current=head;
    while(current!=NULL && current->next!=NULL){
        Node* remov=current->next;
        current->next=current->next->next;
        free(remov);
        current=current->next;
    }
}
// You are given a sorted linked list. We have to remove the duplicate elements of the linked list
void removeduplicates(Node* &head){
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* remov=temp->next;
        int first=temp->val;
        int second=temp->next->val;
        if(first==second){
            temp->next=temp->next->next;
            delete remov;
        } else{
            temp=temp->next;
        }
    }
}
int main(){
    Node* head= new Node(5);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        insert_at_head(head,x);
    }
    display(head);
    removeduplicates(head);
    display(head);
    return 0;
}