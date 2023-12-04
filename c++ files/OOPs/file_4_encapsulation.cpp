#include<iostream>
using namespace std;
// Here we cannot directly access the values of x and y directly so we will call the function .
// Because the values of x and y are default private.
class mine{
    int x;
    int y;
    
    public: 
    void set(int n){
        x=n;
        y=n*2;
    }

    void get(){
        cout<<x<<" "<<y;
    }
};
int main(){
    mine obj;
    int a;
    cin>>a;
    obj.set(a);
    obj.get(); 

    return 0;
}