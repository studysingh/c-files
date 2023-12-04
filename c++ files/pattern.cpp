#include<iostream>
using namespace std;
// Solid Rectangle
void solidRect(int length, int breadth){
  for(int i=0;i<length;i++){
        for(int j=0;j<breadth;j++){
            cout<<'*';
        }
        cout<<endl;
    }
    cout<<endl;
}
// Hollow Rectangle
void hollowRect(int length, int breadth){
    for(int i=0;i<length;i++){
        for(int j=0;j<breadth;j++){
            if(i==0||j==0||i==length-1||j==breadth-1){
                cout<<'*';
            } else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
// Right Triangle
void rightTri(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<'*';
        }
        cout<<endl;
    }
    cout<<endl;
}
// Inverted Right Triangle
void invRightTri(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=i;j<n;j++){
            cout<<'*';
        }
        cout<<endl;
    }
    cout<<endl;
}
// real triangle
void triangle(int row){
    int column=2*row-1;
    for(int i=0;i<row;i++){
        for(int j=0;j<row-i-1;j++){
            cout<<" ";
        }
        for(int j=row-i-1;j<i+row;j++){
            cout<<'*';
        }
        cout<<endl;
    }
    cout<<endl;
}
// Numerical Square
void numSquare(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cout<<j<<" ";
        }
        for(int j=1;j<i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
// 1 and 2 square pattern printing
void _1and2(int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if((i+j)%2==1){
                cout<<2;
            } else {
                cout<<1;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
// Printing numerical pyramid
void numPyramid(int row){
    int column=2*row+1;
    for(int i=0;i<row;i++){
        // space printing
        for(int j=0;j<row-1-i;j++){ 
            cout<<" ";
        }
        // printing number til middle column
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        // printing after middle column
        for(int j=i+1;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
    cout<<endl;
}
// checking prime number
bool prime(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2){
        return true;
    } else{
        return false;
    }
}
// Printing triangle of prime numbers
void primeTriangle(int row){
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<row-1-i;j++){
            cout<<" ";
        }
        for(int j=row-1-i;j<i+row;j++){
            for(int i=0;;i++){
                if(prime(k)==true){
                    cout<<k;
                    k++;
                    break;
                } else{
                    k++;
                }
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    primeTriangle(2);
}