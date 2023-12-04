#include<iostream>
#include<stack>
#include<string.h>
#include<math.h>
using namespace std;

int operates(int a , char ch='+' , int b=0 ){
    if(ch == '+'){
        return a+b;
    }
    if(ch == '-'){
        return a-b;
    }
    if(ch == '*'){
        return a*b;
    }
    if(ch == '/'){
        return a/b;
    }
    if(ch == '^'){
        return pow(a,b);
    } else{
        return a;
    }
}

int simpleOperate(stack<int> &num , stack<char> &op){
    if(op.empty()){
        int ans = num.top();
        num.pop();
        return ans;
    }
    int b = num.top();
    num.pop();
    char sign = op.top();
    op.pop();
    int a = num.top();
    num.pop();
    if(!op.empty() && (sign == '+' || sign == '-') && (op.top() == '*' || op.top() == '/')){
        char insideOperate = op.top();
        op.pop();
        int a0 = num.top();
        num.pop();
        int twoValueAns = operates(a0,insideOperate,a);
        num.push(twoValueAns);
        num.push(b);
        op.push(sign);
    } else{
        int twoValueAns = operates(a,sign,b);
        num.push(twoValueAns);
    }
    return simpleOperate(num,op);
}

int storeNumAndOperator(string str){
    stack<int> num;
    stack<char> op;
    for(int i=0;i<str.length();){
        string storeNum = "";
        while(isdigit(str[i])){
            storeNum+=str[i];
            i++;
        }
        num.push(stoi(storeNum)); // integer pushed
        storeNum = "";
        if(i<str.length()){
        op.push(str[i]); // operator storage
        i++;
        }
    }
    return simpleOperate(num,op);
}

float eval(string str){
    stack<int> num;
    stack<char> op;
    stack<char> bracket;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch == '{' || ch == '(' || ch == '['){
            bracket.push(ch);
        }
    }
}

int main(){
    string str="39*75/8/8";
    cout<<"Printed"<<endl<<storeNumAndOperator(str)<<endl<<39*75/8/8;
}