#include<iostream>
#include<queue>
using namespace std;

// Reverse the queue
queue<int> reverse(queue<int> &qu){
    if(qu.empty()){
        return qu;
    }
    int el = qu.front();
    qu.pop();
    reverse(qu);
    qu.push(el);
    return qu;
}

int main(){
    queue<int> qu;
    qu.push(10);  // enque operation
    qu.push(20);
    qu.pop();
    qu.push(78);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    // while(!qu.empty()){
    //     cout<<qu.front()<<" ";
    //     qu.pop(); // deque operation
    // }
    qu = reverse(qu);
    // reversed queue
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop(); // deque operation
    }
    return 0;
}