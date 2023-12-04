// compile time polymorphism
#include<iostream>
using namespace std;
                                // function overloading  
class sum{
public:
    void add(int x){
        cout<<x<<endl;
    }
    void add(int x, int y){
        cout<<x+y<<endl;
    }
    void add(float x, float y){
        cout<<x+y<<endl;
    }
    void add(int x, int y, int z){
        cout<<x+y+z<<endl;
    }
};
int main(){
    sum s;
    s.add(5);
    s.add(5,6);
    s.add(5.6f,6.6f);
    s.add(5,6,3);
    return 0;
}