#include<bits/stdc++.h>
using namespace std;
// WE are assuming the heap to be 1 indexed
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class heap{
public:
    int arr[10000];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }

    // inserting the node in the heap
    void insert(int data){
        // insert the value first
        size++;
        arr[size] = data;
        // send it to the right position
        int parentIdx = size/2;
        int childIdx = size;
        while(parentIdx > 0){
            if(arr[parentIdx] < arr[childIdx]) swap(arr[parentIdx] , arr[childIdx]);
            else return;
            parentIdx /= 2;
            childIdx /= 2;
        }
    }
    // printing the heap
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        } cout<<endl;
    }

    // deleting in the heap
    // it means deleting the node
    void deletion(){
        // heap is empty
        if(size == 0) return;

        // putting the element at first position
        arr[1] = arr[size];

        //deleting the node means size is not accessed
        size--;

        // moving it to the right position
        int index = 1;
        while(index <= size){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            if(leftChild <= size && arr[leftChild] > arr[index]){
                swap(arr[index] , arr[leftChild]);
                index = leftChild;
            } else if(rightChild <= size && arr[rightChild] > arr[index]){
                swap(arr[index] , arr[rightChild]);
                index = rightChild;
            } else{
                return;
            }
        }
    }
};
// heapify algorithm
void heapify(int arr[] , int n , int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    
    if(left <= n && arr[left] > arr[largest]) largest = left;
    if(right <= n && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr,n,largest);
    }
}
//heapSort
void heapSort(int arr[] , int n){
    // building the heap
    for(int i = n/2;i>0;i--){
        heapify(arr,n,i);
    }
    // sorting according to the heap
    int size = n;
    while(size > 1){
        // step 1 :-> swaping
        swap(arr[1] , arr[size]);
        size--;
        // step 2 :-> heapify the first node 
        heapify(arr,size,1);
    }
}
int main(){
    heap h;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        h.insert(x);
    }
    h.print();
    h.deletion();
    h.print();
    // int arr[] = {-1,45,2,6,4,5,9,7,42,100};
    // heapSort(arr,9);
    // for(int i=1;i<=9;i++){
    //     cout<<arr[i]<<" ";
    // } cout<<endl;
    // cout<<"👍"<<endl;
    // return 0;
}
//8
// 4 8 2 6 3 78 54 1