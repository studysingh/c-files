#include<iostream>
using namespace std;

class parent{
    public:
    parent(){
        cout<<"Parent class\n";
    }
};

class child: public parent{
    public: 
    child(){
        cout<<"Child class\n";
    }
};

class grandchild: public child{
    public: 
    grandchild(){
        cout<<"Grand-child(3rd level) class\n";
    }
};


int main(){
    grandchild funct; // first invoke the properties of parent class then child class then grandchild class
    return 0;
 }