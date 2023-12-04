//                            // Number Game . Ashishgup and FastestFinger
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// bool checkpowerof2(ll n){
//     int i=2;
//     while(pow(2,i)<=n){
//         if(pow(2,i)==n){
//             return true;
//         } else{
//             i++;
//         }
//     }
//     return false;
// }
// int main(){
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         ll n;
//         cin>>n;
//         // solution
//         if(n==1){
//             cout<<"FastestFinger\n";
//         } else if(n==2){
//             cout<<"Ashishgup\n";
//         } else if (n%2==1){
//             cout<<"Ashishgup\n";
//         } else if(checkpowerof2(n)==true){
//             cout<<"FastestFinger\n";
//         } else if((n/2)%2==1){ // after dividing with 2 we get the odd number
//             cout<<"FastestFinger\n";
//         } else{  // after dividing with powerof2 we get odd but with 2 we get even
//             cout<<"Ashishgup\n";
//         }
//     }
//     return 0;
// }
