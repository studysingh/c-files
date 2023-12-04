#include<iostream>
#include<vector>
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
// Checking if two linked lists are equal or not
bool equal(Node* head1 , Node* head2){
   Node* temp1 = head1;
   Node* temp2 = head2;
   while(temp1!=NULL && temp2!=NULL){
    if(temp1->val != temp2->val){
        return false;
    } else{
        temp1=temp1->next;
        temp2=temp2->next;
    }
   }
   if(temp1!=NULL){
    return false;
   }
   if(temp2!=NULL){
    return false;
   }
   return true;
}
// You are given head1 and head2 of two linked list . You have to find the intersection point of the two linked list .
//e.g., head1 = {1,2,3,5}
// head2 = {44 , 12 , 2 3 5}
// Here the intersection is at node where the value is 2
int find_length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
Node* find_intersection(Node* head1 , Node* head2){
    int l1 = find_length(head1);
    int l2 = find_length(head2);
    if(l1>l2){
        int k = l1 - l2;
        int i = 0;
        while(i<k){
            head1=head1->next;
            i++;
        }
    } else{
        int k = l2 - l1;
        int i = 0;
        while(i<k){
            head2 = head2->next;
            i++;
        }
    }
    while(head1!=NULL){
        if(head1 == head2){
            return head1;
        } else{
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return NULL;
}
void intersectedHeadInput(){
    LinkedList ll1,ll2;
    ll1.insertAtTail(1);
    ll1.insertAtTail(4);
    // ll1.insertAtTail(8);
    ll1.insertAtTail(10);
    ll1.insertAtTail(5);

    ll2.insertAtTail(100);
    ll2.insertAtTail(200);
    ll2.insertAtTail(158);
    ll2.head->next->next = ll1.head->next->next;
    cout<<"Linked List 1 \n";
    ll1.display();
    cout<<"Linked List 2 \n";
    ll2.display();
    Node*  ans = find_intersection(ll1.head , ll2.head);
    if(!ans){
        cout<<"There is no intersection \n";
    } else{
        cout<<"The intersection node is : "<<ans->val<<endl;
    }
}
// Given a head of the linked list . You have to delete the nth node fron the end of the linked list
Node* removeFromEnd(Node* head , int n){
    int length = find_length(head);
    if(n>length){
        return NULL;
    }
    if(length == n){
        Node* temp = head;
        head = head -> next ;
        free(temp);
        return head;
    }
    int k = length - n;
    int i = 0; 
    Node* prev = head;
    while(i<(k-1)){
        prev = prev -> next;
        i++;
    }
    Node* toRemove = prev -> next;
    Node* next_ptr = prev->next->next;
    prev->next = next_ptr;
    free(toRemove);
    return head;
}
//We are given two sorted linked list . We have to merge the two linked list such that the resulting linked list is also sorted.
//e.g., h1 = 1,2,5,6
// h2 = 3,4,6
//ans = 1,2,3,4,5,6,6
Node* merge(Node* head1 , Node* head2){
    LinkedList result;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=NULL && temp2!=NULL){
        int a = temp1->val;
        int b = temp2->val;
        if(a<b){
            result.insertAtTail(a);
            temp1=temp1->next;
        } else if(a==b){

        } else{
            result.insertAtTail(b);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        result.insertAtTail(temp1->val);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        result.insertAtTail(temp2->val);
        temp2=temp2->next;
    }
    return result.head;
}
//You are given an array of k linked list . Each linked list is sorted in ascending order . Merge all the linked-lists into one sorted linked-list and return it .
Node* mergeManyLL_recursive(vector<Node*> v , int length , Node* result = NULL){
    if(length == 0){
        return result;
    }
    result = merge(result , v[length-1]);
    length-=1;
    return mergeManyLL_recursive(v,length,result);
}
Node* mergeManyLL_iterative(vector<Node*> v , int length){
    Node* result  = v[0];
    for(int i = 1; i<length; i++){
    result = merge(result , v[i]);
    }
    return result;
}
int main(){
    // LinkedList l1 ,l2;
    // int n1,n2;
    // cout<<"Enter the number of element in l1: ";
    // cin>>n1;
    // for(int i = 0; i<n1;i++){
    //     int x;
    //     cin>>x;
    //     l1.insertAtTail(x);
    // }
    // l1.display();
    // cout<<"Enter the number of element in l2 : ";
    // cin>>n2;
    // for(int i = 0 ; i<n2; i++){
    //     int x ;
    //     cin>>x; 
    //     l2.insertAtTail(x);
    // }
    // l2.display();
    // LinkedList result;
    // result.head=merge(l1.head , l2.head);
    // result.display();
    LinkedList l1,l2,l3;
    l1.insertAtTail(1);
    l1.insertAtTail(5);
    l1.insertAtTail(10);
    l1.display();

    l2.insertAtTail(2);
    l2.insertAtTail(4);
    l2.insertAtTail(6);
    l2.insertAtTail(8);
    l2.insertAtTail(80);
    l2.insertAtTail(85);
    l2.display();

    l3.insertAtTail(12);
    l3.insertAtTail(14);
    l3.insertAtTail(16);
    l3.insertAtTail(18);
    l3.display();

    vector<Node*> v(3);
    v[0]=l1.head;
    v[1]=l2.head;
    v[2]=l3.head;

    LinkedList ans;
    ans.head = mergeManyLL_iterative(v,3);
    ans.display();

    return 0;
}