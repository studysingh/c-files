#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> deq;
    deq.push_back(5);
    deq.push_back(50);
    deq.push_back(500);
    deq.push_front(4);
    deq.push_front(40);
    deq.push_front(400);
    deq.push_front(4000);
    while(!deq.empty()){
        cout<<deq.front()<<" ";
        deq.pop_front();
    }
    return 0;
}