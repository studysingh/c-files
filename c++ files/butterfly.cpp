#include<iostream>
using namespace std;
int main(){
    // Time 12: 51
    int n;
    cout<<"Enter the length of butterfly pattern: ";
    cin>>n;
    if(n%2==0){ // Even number
    cout<<n<<endl;
    // Upper Part
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=i+1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=n-i+1;j<=n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    // Lower Part
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=n/2+1-i;j++){
            cout<<"*";
        }
        for(int k=0;k<2;k++){
            for(int j=n/2+1-i;j<n/2;j++){
            cout<<" ";
        }
        }
        for(int j=n/2+i;j<=n;j++){
            cout<<"*";
        }
        cout<<endl;
        }
        cout<<endl;
    } else{ // Odd Condition
        cout<<n<<endl;
        // Upper Half
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=i;j++){
                cout<<"*";
            } 
            for(int j=i+1;j<=n-i;j++){
                cout<<" ";
            }
            for(int j=n-i+1;j<=n;j++){
                cout<<"*";
            } cout<<endl;
        }
        // Middle line
        for(int i=1;i<=n;i++){
            cout<<"*";
        } cout<<endl;
        // Lower Half
        for(int i=n/2;i>=1;i--){
            for(int j=1;j<=i;j++){
                cout<<"*";
            }
            for(int j=i+1;j<=n-i;j++){
                cout<<" ";
            }
            for(int j=n-i+1;j<=n;j++){
                cout<<"*";
            } cout<<endl;
        }
    }

}