#include<iostream>
using namespace std;
class Rectangle{
    public: 
    int length;
    int breadth;
    // Default constructor-> No argument is passed
    Rectangle(){
        length=4;
        breadth=12;

    }
    // Parameterised Constructor -> Argument is passed
    Rectangle(int x,int y){
        length =x;
        breadth = y;
    }
    // Copy Constructor -> It is used when we want to use the data of the existing object . So, we copy the data from other object
    Rectangle(Rectangle &r){
        length=r.length;
        breadth=r.breadth;
    }
};
 int main(){
    cout<<" Default Constructor \n";
    Rectangle r1;
    cout<<r1.length<<"  "<<r1.breadth<<endl;

    cout<<"Parameterised Constructor\n";
    Rectangle r2(3,5);
    cout<<r2.length<<" "<<r2.breadth<<endl;
    
    cout<<"Copy Constructor \n";
    Rectangle r=r2;
    cout<<r.length<<" "<<r.breadth<<endl;

    return 0;
 }