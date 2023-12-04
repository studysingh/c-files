#include<iostream>
using namespace std;
// wap for add two numbers using pointer
int add(int a,int b){
    int *num1=&a;
    int *num2=&b;
    return *num1+ *num2;
}
int main(){
    int a=5;
    int *ptr=&a; // address of a is stored in ptr variable
    cout<<"Value stored at address of ptr is : "<<*ptr<<endl;
    cout<<"The address of the int a is : "<<ptr<<endl;
    // updation in a using pointer
    *ptr=244;
    cout<<"\n"<<"The changed value at the address of a i.e, at ptr is: "<<a<<endl;
    // storing value in another variable using pointer
    int z=*ptr;
    cout<<"The value of z is same as a or the value at the pointer ptr: "<<z<<endl;
    cout<<add(4,5)<<endl;
    return 0;
}