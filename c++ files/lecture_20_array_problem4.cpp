#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Given a 2D array, print its element  in  the spiral order.
void spiral_order_printing(vector<vector<int>> v){
    // defining variabele
    int up_row=0;
    int bottom_row=v.size()-1;
    int left_col=0;
    int right_col=v[0].size()-1;
    int total_element=(v[0].size()*v.size());
    int element=0;
    while(element<total_element){ // loop till element is less than total element
        for(int j=left_col;j<=right_col && element<total_element;j++){
            cout<<v[up_row][j]<<"  ";
            element++;
        } up_row++;
        for(int i=up_row;i<=bottom_row && element<total_element;i++){
            cout<<v[i][right_col]<<"  ";
            element++;
        } right_col--;
        for(int j=right_col;j>=left_col && element<total_element;j--){
            cout<<v[bottom_row][j]<<"  ";
            element++;
        } bottom_row--;
        for(int i=bottom_row;i>=up_row && element<total_element;i--){
            cout<<v[i][left_col]<<"  ";
            element++;
        } left_col++;
    }
    cout<<endl;
    return;
}
// Make a 2D array of row and column as n.
void makeArray(int n){
    vector<vector<int>> v(n,vector<int>(n));
    int up_row=0;
    int bottom_row=n-1;
    int left_col=0;
    int right_col=n-1;
    int fill=1;
    int total_element=n*n;
    while(fill<=total_element){
        for(int j=left_col;j<=right_col && fill<=total_element;j++){
            v[up_row][j]=fill;
            fill++;
        } up_row++;
        for(int i=up_row;i<=bottom_row && fill<=total_element;i++){
            v[i][right_col]=fill;
            fill++;
        } right_col--;
        for(int j=right_col;j>=left_col && fill<= total_element;j--){
            v[bottom_row][j]=fill;
            fill++;
        } bottom_row--;
        for(int i=bottom_row;i>=up_row && fill<=total_element;i--){
            v[i][left_col]=fill;
            fill++;
        } left_col++;
    }
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    return;
}
void makeSpiralRectangle(int n, int m){
    vector<vector<int>> v(n,vector<int>(m));
    int up_row=0;
    int bottom_row=n-1;
    int left_col=0;
    int right_col=m-1;
    int fill=1;
    int total_element=m*n;
    while(fill<=total_element){
        for(int j=left_col;j<=right_col && fill<=total_element;j++){
            v[up_row][j]=fill;
            fill++;
        } up_row++;
        for(int i=up_row;i<=bottom_row && fill<=total_element;i++){
            v[i][right_col]=fill;
            fill++;
        } right_col--;
        for(int j=right_col;j>=left_col && fill<= total_element;j--){
            v[bottom_row][j]=fill;
            fill++;
        } bottom_row--;
        for(int i=bottom_row;i>=up_row && fill<=total_element;i--){
            v[i][left_col]=fill;
            fill++;
        } left_col++;
    }
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    // vector<vector<int>> v(n,vector<int>(n));
    // v=makeArray(n);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<v[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }
    makeSpiralRectangle(n,m);
    return 0;
}