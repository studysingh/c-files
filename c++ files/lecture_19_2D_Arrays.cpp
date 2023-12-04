#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//                                             Question 1
// Given a boolean 2D Array (i.e., values are 0 or 1) , where each row is sorted . Find the row with the maximum number of 1s.
// Approach 1
int ques1(vector<vector<int>> v){
    // finding and storing the no of 1s in the vector v
    vector<int> no_of_1s;
    for(int i=0;i<v.size();i++){
        int count=0;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1){
                break;
            } else{
                count++;
            }
        }
        no_of_1s.push_back(v[i].size()-count);
    }
    // finding the maximum value and index in the vector v
    int ans=INT32_MIN;
    int idx;
    for(int i=0;i<no_of_1s.size();i++){
        if(ans<no_of_1s[i]){
            ans=no_of_1s[i];
            idx=i;
        }
    }
    return idx;
}
// Approach 2 optimized (finding the leftmost 1)
int ques1Approach2(vector<vector<int>> v){
    int j=v[0].size()-1;
    int ans=-1;
    for(int i=0;i<v.size();i++){ // i traverse the row
        while(v[i][j]==1){ // j update the column and traverse from right side. j is updated and start traversing column from updated position so time is reduced
            ans=i;
            j--;
        }
    }
    return ans;
}
//                                        Question 2
//Given a sqaure matrix , turn it by 90 degrees in a clockwise direction without using any extra space
void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
    return;
}
void ques2(vector<vector<int>> &v){
    // finding transpose in place
    for(int i=0;i<(v.size());i++){
        for(int j=i+1;j<(v[i].size());j++){
            swap(v[i][j],v[j][i]);
        }
    }
    // reversing each row element
        for(int i=0;i<v.size();i++){
                int left_col=0;
                int right_col=v[0].size()-1;
            while(left_col<right_col){
            swap(v[i][left_col],v[i][right_col]);
            left_col++;
            right_col--;
        }
    }
    // printing new vector
        for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"    ";
        }
        cout<<endl;
    }
    return;
}
int main(){
    int m;
    cin>>m;
    vector<vector<int>> v(m,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    ques2(v);
    return 0;
}
