#include<iostream>
using namespace std;
class student{
    public: 
    string roll;
    string name;
    int marks;
    student(){
        roll="3435";
        name="Sandeep Singh";
        marks=100;
    }
    ~student(){ // it is used to destroyed the made object 
        cout<<"Object is destroyed\n";
    }
};
int main(){
    student s1;
    cout<<s1.roll<<"     "<<s1.name<<"     "<<s1.marks<<endl;

// If an object is used using arrow operator we can delete the object by using delete and destructor operator is used . For example,
   student *s=new student();
   s->roll="35443";
   s->name="Karthik";
   s->marks=98;
   cout<<s->roll<<"     "<<s->name<<"   "<<s->roll<<endl;
   delete s; // here the destructor is called for the object s

    student s2;
    s2.roll="54535";
    s2.name="Aman";
    s2.marks=93;
    cout<<s2.roll<<"    "<<s2.name<<"   "<<s2.marks<<endl;

    student s3;
    s3.roll="5453467";
    s3.name="naman";
    s3.marks=86;
    cout<<s3.roll<<"    "<<s3.name<<"   "<<s3.marks<<endl;

    return 0;
}