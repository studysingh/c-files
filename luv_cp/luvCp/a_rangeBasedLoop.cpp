#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    syntax     ::::      for(data_type name : container_name){}
    */
    // In range based loop values are passed by value not by reference
    vector<int> v={34,56,64,63};
    for(int value : v){
        cout<<value<<" ";
    }
    cout<<endl<<endl;
    // Pass by reference in range based loop
    vector<pair<int,string>> a = {{54,"akd"} , {64,"ujsj44"} , {6,"ureikf"}};
    for(pair<int,string> &val : a){
        cout<<val.first<<" "<<val.second<<endl;
    }
}