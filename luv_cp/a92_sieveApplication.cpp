#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
vector<bool> isPrime(N,true);
vector<int> lp(N,0),hp(N,0);
void highestLowestPrime(int num){
    cout<<num<<" "<<lp[num]<<" "<<hp[num]<<endl;
}
unordered_map<int,int> primeFactor(int num){
    unordered_map<int,int> ans;
    while(num>1){
        int high = hp[num];
        int frequency = 0;
        while(num%high == 0){
            frequency++;
            num/=high;
        }
        ans[high] = frequency;
    }
    return ans;
}
int main(){
    // Precomputing the highest and lowest primes of a number
    // lp[num] and hp[num] stores the lowest and highest prime of the number num respectively .
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<N;i++){
        if(isPrime[i] == true){
            lp[i]=hp[i]=i; // if the input number is prime
            for(int j=2*i;j<N;j+=i){
                isPrime[j] = false;
                hp[j] = i; // stores the highest prime
                if(lp[j] == 0) lp[j] = i; // stores the lowest prime 
            }
        }
    }
    int num;
    cin>>num;
    highestLowestPrime(num);
    // unordered_map<int,int> ans = primeFactor(num);
    // for(auto it = ans.begin();it!=ans.end();it++){
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }
}