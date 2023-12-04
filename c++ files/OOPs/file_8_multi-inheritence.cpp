#include<iostream>
using namespace std;

class parent1{
    public : 
    parent1(){
        cout<<"Parent1 class\n";
    }
};

class parent2{
    public :
     parent2(){
        cout<<"Parent2 class\n";
     }
};

class child1 : public parent1, public parent2{
    public : 
    child1(){
        cout<<"Child1 class\n";
    }
};
class child2 : public parent2 , public parent1{
    public : 
    child2(){
        cout<<"Child2 class\n";
    }
};


int main(){
    child1 obj; // properties are inherited on the basis of inheritence order
    cout<<endl;
    child2 obj2;
    return 0;
}