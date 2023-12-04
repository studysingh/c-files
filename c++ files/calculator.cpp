#include<iostream>
using namespace std;
int main(){
    double result;
    cin>>result;
    char operate;
    do{
    double n;
        cin>>operate;
        switch(operate){
            case '+' : cin>>n;
            result+=n;
            break;
            case '-' : cin>>n;
            result-=n;
            break;
            case '*': cin>>n;
            result*=n;
            break;
            case '/' : cin>>n;
            result/=n;
            break;
            case '=' : cout<<result<<endl;
            break;
        }
    }  while(operate!='=');
    return 0;
}