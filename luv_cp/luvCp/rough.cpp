#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
vector<bool> isPrime(N,true);
vector<int> Primes;
vector<bool> primeProduct(N,false);
int main(){
    // calculating prime numbers
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<sqrt(N);i++){
		if(isPrime[i] == true){
			Primes.push_back(i);
			for(int j=2*i;j<sqrt(N);j+=i){
				isPrime[j] = false;
			}
		}
	}
    // calculating primeProduct
    for(int i=0;i<Primes.size();i++){
        for(int j = i;j<Primes.size();j++){
            if(Primes[i]*Primes[j]>N) break;
            else primeProduct[Primes[i]*Primes[j]] = true;
        }
    }

    // Input
	ll n,q;
	cin>>n>>q;
	ll x;
	vector<int> input;
	for(int i=0;i<n;i++){
		cin>>x;
		input.emplace_back(x);
	}

	// solution
    while(q--){
        int x;
        cin>>x;
        if(primeProduct[x] == true){
            cout<<"YES\n";
        } else{
            int i=0;
            for(i=0;i<n;){
                while(x%input[i] != 0){
                    x/=input[i];
                }
                if(primeProduct[x] == true) {
                    cout<<"YES\n";
                    break;
                } else{
                    i++;
                }
            }
            if(i==n) cout<<"NO\n";
        }
    }
}