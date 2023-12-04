#include<iostream> 
using namespace std;
void matrix_multiplication(){
    // array defining and taking input
    int r1,r2,c1,c2;
    cout<<"Enter the no. of rows of array 1: ";
    cin>>r1;
    cout<<"Enter the no. of columns of array 1: ";
    cin>>c1;
    int arr1[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"Enter the no. of rows of array 2: ";
    cin>>r2;
    cout<<"Enter the no. of columns of array 2: ";
    cin>>c2;
    int arr2[r2][c2];
    int ans[r1][c2];
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin>>arr2[i][j];
        }
    }
    // matrix multiplication
    if(c1!=r2){
        cout<<"Invalid Input";
    } else{
        //code for multiplication
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                int sum=0;
                for(int k=0;k<c1;k++){
                    sum+=arr1[i][k]*arr2[k][j];
                }
                ans[i][j]=sum;
            }
        }
         // printing ans array
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    cout<<endl;

}
int main(){
    matrix_multiplication();
    cout<<endl;
    int n;
    cin>>n;
    return 0;
}