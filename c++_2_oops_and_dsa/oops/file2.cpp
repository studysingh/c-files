#include<iostream>
using namespace std;
class rectangle{
public: 
    int l;
    int b;
    rectangle(){ // default constructor
        l=5;
        b=6;
    }
    rectangle(int x, int y){ // parameterised constructor
        l=x;
        b=y;
    }
    rectangle(rectangle &r){ // copy constructor
        l=r.l;
        b=r.b;
    }
    ~rectangle(){ // destructor is called when objects are deleted 
        cout<<"object is deleted \n";
    }

};
int main(){
    // default constructor
    rectangle r1;
    cout<<r1.l<<" "<<r1.b<<endl;

    // parameterised constructor
    rectangle r2(25,1);
    cout<<r2.l<<" "<<r2.b<<endl;

    // copy constructor
    rectangle r3(r2);  // also you can write rectangle r3=r2 in place of rectangle r3(r2)
    cout<<r3.l<<" "<<r3.b<<endl;

    // making object using new keyword and then destructing 
    // To destruct the object made using new keyword we use delete keyword
    rectangle *r4=new rectangle();
    r4->l=65;
    r4->b=66;
    cout<<r4->l<<" "<<r4->b<<endl;
    delete r4; // if we do not use this line the object r4 is not
    return 0;
 }