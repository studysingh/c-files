#include<iostream>
using namespace std;

class parent{
    public : 
    parent(){
        cout<<"Parent class\n";
    }
};

class child1: public parent{
    public :
    child1(){
    cout<<"Child1 class\n";
    }
};

class child2: public parent{
    public :
    child2(){
    cout<<"Child2 class\n";
    }
};

int main(){
    child1 obj1;
    cout<<endl;
    child2 obj2;
    return 0;
 }