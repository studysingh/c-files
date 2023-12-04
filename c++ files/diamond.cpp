#include<iostream>
using namespace std;
// Here, row is the length of the diamond
// solid diamond pattern
void solid(int row){
     for(int i=0;i<row;i++){
        char ch='*';
        // upper diamond spaces
        for(int j=0;j<row/2-i&&i<=row/2;j++){
            cout<<" ";
        }
        // upper diamond star
                for(int j=row/2-i;j<=row/2+i&&i<=row/2;j++){
            cout<<ch;
        }
        //lower diamond spaces
        for(int j=0;j<i-row/2&&i>row/2;j++){
            cout<<" ";
        }
        // lower diamond star
        for(int j=i-row/2;j<=3*(row/2)-i&&i>row/2;j++){
            cout<<ch;
        }
        cout<<endl;
    }
    cout<<endl;
}
void hollow(int row){
   char ch='*';
   for(int i=0;i<row;i++){
    // upper hollow diamond 
    for(int j=0;j<=row/2+i&&i<=row/2;j++){
        if(j==row/2-i||j==row/2+i){
            cout<<ch;
        } else{
            cout<<" ";
        }
    }
    // lower hollow diamond
    for(int j=0;j<=3*(row/2)-i&&i>row/2;j++){
        if(j==i-row/2||j==3*(row/2)-i){
            cout<<ch;
        } else{
            cout<<" ";
        }
    }
    cout<<endl;
   }
   cout<<endl;
}
void alphabet(int row){
    for(int i=0;i<row;i++){
    char ch='A';
    // upper Triangle
        if(i<=row/2){
            for(int j=0;j<row/2-i;j++){
                cout<<" ";
            }
            for(int j=row/2-i;j<=row/2+i;j++){
                cout<<ch++;
            }
        } 
        // lower Triangle
        else{
            for(int j=0;j<i-row/2;j++){
                cout<<" ";
            }
            for(int j=i-row/2;j<=3*(row/2)-i;j++){
                cout<<ch++;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    cout<<"Enter the length (odd number) of diamond: ";
    int row;
    cin>>row;
    solid(row);
    hollow(row);
    alphabet(row);

}