#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// combination of many vectors in a single vector
void combination_vector(){
     vector<vector<int>> v;
    vector<int> v1={1,2,3};
    vector<int> v2={5,2};
    vector<int> v3={4,6,8,2,6};
    v={v1,v2,v3};
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        } 
        cout<<endl;
    }
    return;
}
// giving single value to the whole vector
void single_value(){
    vector<vector<int>> v(3,vector<int>(5,4));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"    ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}
// defining a vector in the code
void define_vector(){
    vector<vector<int>> v;
    v={{1,2,3},{5,6},{8,5,6,9,5,2,}};
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"    ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}
                                                // pascal triangle
                        // method 1
void pascal_triangle(int no_Of_Lines){
    int n=no_Of_Lines;
    vector<vector<int>> pascal(n); // defining vector of row n
    for(int i=0;i<pascal.size();i++){
        pascal[i].resize(i+1);  // giving size to the ith row of pascal vector as -> pascal[i] is itself a vector
        for(int j=0;j<pascal[i].size();j++){
            if(j==0 || j==i){ // filling the element of pascal vector
                pascal[i][j]=1;
            } else{
                pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
            }
        }
    }
    // printing pascal triangle
    for(int i=0;i<pascal.size();i++){
        for(int j=0;j<pascal[i].size();j++){
            cout<<pascal[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}
         // method 2
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    int fact_nm1=factorial(n-1);
    return fact_nm1*n;

}
void pascalTriangle(int n){
    vector<vector<int>> pascal(n);
    for(int i=0;i<pascal.size();i++){
        pascal[i].resize(i+1);  // giving size to pascal[i] vector
        for(int j=0;j<pascal[i].size();j++){
            int iCj=factorial(i)/(factorial(j)*factorial(i-j)); // using formula of nCr to find the (n,r) element of the pascal triangle
            pascal[i][j]=iCj;
        }
    }
    // printing the pascal triangle
    for(int i=0;i<pascal.size();i++){
        for(int j=0;j<pascal[i].size();j++){
            cout<<pascal[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}
int main(){
    single_value();
    return 0;
}