#include<iostream>
using namespace std;
// Encapsulation
class abd{
    int x;
    public :
    void set(int y){
        x=y;
    }

    int get(){
        return x;
    }
};
int main(){
    abd obj;
    obj.set(5);
    int a=obj.get();
    cout<<a;
    return 0;
}