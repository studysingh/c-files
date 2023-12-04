#include<iostream>
using namespace std;
class parent{
public:
   virtual void show(){ // virtual keyword is used to when we want to override the function of parent class over child class
        cout<<"parent class"<<endl;
    }
    void print(){
        cout<<"parent class"<<endl;
    }
};
class child: public parent{
public:
    void show(){
        cout<<"child class\n";
    }
    void print(){
        cout<<"child class\n";
    }
};
int main(){
    parent *p;
    child c;
    p=&c;
    p->show();
    p->print();
    return 0;
}