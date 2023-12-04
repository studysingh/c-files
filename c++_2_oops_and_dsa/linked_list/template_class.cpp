#include<iostream>
using namespace std;
template <typename T> // defining template
class Node{ // defining template class
public:
    T val;
    Node* next;
    Node(T data){
        val = data;
        next = NULL;
    }
};
int main(){
    Node<int>* node1 = new Node<int>(5); // defining the data type at the time of use
    cout<<node1->val<<endl;
    Node<string>* node2 = new Node<string>("sandeep"); // defining the data type  at the time of useff
    cout<<node2->val<<endl;
    return 0;
}