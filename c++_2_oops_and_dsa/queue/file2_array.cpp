#include<iostream>
#include<vector>
using namespace std;


class Queue{
    vector<int> v;
    int front;
    int back;
public: 
    Queue(){
        front = -1;
        back = -1;
    }
    void enqueue(int data){
        if(front == -1){
            v.push_back(data);
            front = 0;
            back = 0;
        } else{
            v.push_back(data);
            back++;
        }
    }

    void dequeue(){
        if(front == back){
            front = -1;     // 5 550 dequeue 54  output 550 54
            back = -1;
            v.clear();
        } else{
            front++;
        }
    }

    int getFront(){
        if(front == -1){
            return INT32_MIN;
        } else{
            return v[front];
        }
    }

    int getSize(){
        if(front!=-1){
            return back - front ;
        } else{
            return 0;
        }
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        } else{
            return false;
        }
    }
};

int main(){
    Queue qu;
    qu.enqueue(5);
    qu.enqueue(50);
    qu.enqueue(45);
    qu.enqueue(58);
    while(!qu.isEmpty()){
        cout<<qu.getFront()<<" current size "<<qu.getSize()<<endl;
        qu.dequeue();
    }
    cout<<qu.getSize()<<endl;
    qu.enqueue(58);
    qu.enqueue(550);
    qu.dequeue();
    qu.enqueue(54);
    qu.enqueue(458);
    qu.dequeue();
    qu.enqueue(578);
    while(!qu.isEmpty()){
        cout<<qu.getFront()<<"  ";
        qu.dequeue();
    }
    return 0;
}