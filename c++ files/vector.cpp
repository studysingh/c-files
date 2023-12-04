#include<iostream>
#include<vector>
using namespace std;
int main(){
    int element;
    vector<int> vec; // vector is initialised
    // taking vector as input
    for(int i=0;i<6;i++){
        cin>>element;
        vec.push_back(element);
    }
    // printing a vector
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"  ";
    }
    cout<<endl;
    // erasing and inserting operations 
    vec.insert(vec.begin()+2,188);
    vec.erase(vec.end()-3);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"  ";
    }
    cout<<endl;
    return 0;
    
}