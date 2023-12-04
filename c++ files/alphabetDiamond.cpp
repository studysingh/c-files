#include<iostream>
using namespace std;
void diamond(int n){
     int half=n/2;
    // Upper Triangle
    for(int i=1;i<=half;i++){
        for(int j=i;j<=half;j++){
            cout<<" ";
        } 
        for(int j=1;j<=(2*i-1);j++){
            cout<<'*';
        }
        cout<<endl;
    }
    // Middle line
    for(int i=1;i<=n;i++){
        cout<<"*";
    } cout<<endl;
    // lower triangle
    for(int i=half;i>=1;i--){
        for(int j=i;j<=half;j++){
            cout<<" ";
        }
        for(int j=(2*i-1);j>=1;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    return;
}
void  alphabet_diamond(int n){
    if(n%2 == 0 || n>26 || n<0){
        cout<<"Invalid Input";
        return ;
    }
    // upper triangle
    int half=n/2;
    for(int i=1;i<=half;i++){
        for(int j=i;j<=half;j++){
            cout<<" ";
        }
        char ch='A';
        for(int j=1;j<=(2*i-1);j++){
            cout<<ch++;
        }
        cout<<endl;
    }
    // Middle line
    char ch='A';
    for(int i=1;i<=n;i++){
        cout<<ch++;
    } cout<<endl;
    // Lower Triangle
    for(int i=half;i>=1;i--){
        for(int j=i;j<=half;j++){
            cout<<" ";
        }
        char ch='A';
        for(int j=(2*i-1);j>=1;j--){
            cout<<ch++;
        } cout<<endl;
    }
    return;
}
int main(){
    int n;
    cout<<"Enter the length of the diamond: ";
    cin>>n;
    for(int i=0;i<68;i++){
        cout<<"__";
    } cout<<endl;
    alphabet_diamond(n);
    return 0;
}