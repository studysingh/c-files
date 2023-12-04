#include<iostream>
using namespace std;

class parents{
    public :
    parents(){
        cout<<"parent class\n";
    }
};

class child: public parents{
    public: 
    child(){
        cout<<"child class\n";
    }
};

int main(){
    child obj; // first parent class properties are called and then child class properties
    return 0;
 }