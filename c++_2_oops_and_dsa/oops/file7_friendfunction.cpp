#include<iostream>
using namespace std;
class a{
    int x;
public:
    a(int y){
        x=y;
    }
    friend void print(a &obj); // using friend keyword in front of the function which is not even belong to the class, it gives 
    // access of private element of the class to his friend function
};
void print(a &obj){
    cout<<obj.x;
    return;
}
int main(){
    a object(5);
    print(object);
    return 0;
}