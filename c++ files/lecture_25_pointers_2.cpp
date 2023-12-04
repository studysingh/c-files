#include<iostream>
using namespace std;
// call by reference
void swap(int *x, int *y){
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    return;
}
//pointer arithmetic
void arithmetic(){
    int arr[3]={11,25,39};
    int *ptr=&arr[0];
    cout<<*ptr<<endl; // 11
    cout<<ptr<<endl;
    cout<<*++ptr<<endl; // 25 here the pointer is increased and it points towards arr[1]
    cout<<ptr<<endl;;
    cout<<++*ptr<<endl; // 26
    cout<<ptr<<endl;
}
// array as a pointer
void arraypointer(){
    int arr[4]={24,65,76,25};
    int *ptr=&arr[0];
    cout<<arr<<" "<<ptr<<endl;
    cout<<*arr<<" "<<*ptr<<endl<<endl;
    // array printing using pointer
    for(int i=0;i<4;i++){
        cout<<*(arr+i)<<endl;
    }
}
// pointing the whole array using the pointer
void pointArray(){
    int arr[4]={34,65,76,26};
    int (*ptr)[4]=&arr;
    cout<<ptr<<" "<<arr<<"  "<<*ptr<<endl;
}
int main(){
    pointArray();
}