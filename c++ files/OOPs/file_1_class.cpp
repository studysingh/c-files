#include<iostream>
using namespace std;
// defining class
// class class_name{

// };
class Fruit{
    public:
    string color;
    string name;
};
int main(){
    // Creating variable and giving parameters to objects of classes
    // Method ->1
    Fruit mango;
    mango.color="yellow";
    mango.name="Dasahari";
    cout<<mango.name<<"  "<<mango.color<<endl;

    // Method -> 2
    // In place of . operator we use arrow(->) operator
    Fruit *apple  = new Fruit();
    apple->color="Red";
    apple->name="Variety";
    cout<<apple->name<<"  "<<apple->color<<endl;
    return 0;
}