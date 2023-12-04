#include<iostream>
#include<vector>
using namespace std;
int main(){
    // finding last occurence of an element
    vector<int> v(5);
    cout<<"Enter the "<<v.size()<<" elements: "<<endl;
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
   /* cout<<"Enter the number whose last occurence is to be found: ";
    int x;
    cin>>x;
    int occurence=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            occurence=i;
        }
    }
    cout<<occurence; */

    // counting number of occurences of an element
    /*cout<<"Enter the element: ";
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==n){
            count++;
        }
    }
    cout<<count;*/
    

}