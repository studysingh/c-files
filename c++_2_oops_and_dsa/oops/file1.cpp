#include<iostream>
using namespace std;
class fruit{
public:    
    string color;
    string name;
};
int main(){
    fruit fruits;
    fruits.color="red";
    fruits.name="mango";
    cout<<fruits.color<<endl<<fruits.name<<endl;

    fruit *fruited=new fruit();
    fruited->color="yellow";
    fruited->name="banana";
    cout<<fruited->color<<endl<<fruited->name;
    return 0;
}