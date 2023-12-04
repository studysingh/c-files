#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// determining the no. of days taken to delete the elements till mid
// ll totalDay(ll mid , ll lo , ll arrSize , vector<ll> arr,ll k){
// 	ll elements = mid - lo+1; // total element
// 	ll day = 0;
// 	while(elements>0){
// 		ll j = arrSize;
// 		while(j>0 && arr[j-1]>elements) j--;
// 		elements -= j;
// 		day++;
// 		if(day>k) break; // if days become greater then the given no. of days , then we will break
// 	}
// 	return day;
// }
ll totalDay(ll mid , ll lo , ll arrSize , vector<ll> &arr,ll k){
	ll elements = mid - lo+1; // total element
	ll day = 0;
	while(elements>0){
		ll j = arrSize;
		ll s = 0;
		ll e = j;
		while(s<=e){
			ll midIn = (s+e)/2;
			if(arr[midIn]>elements){
				j = midIn;
				e = midIn - 1;
			} else{
				s = midIn + 1;
			}
		}
		elements -= j;
		day++;
		if(day>k) break; // if days become greater then the given no. of days , then we will break
	}
	return day;
}
// binary search
void solve(vector<ll> &v , ll n, ll &k){
	// in case first element is not equal to q
	if(v[0] != 1){
		cout<<1<<endl;
		return;
	}
	ll lo = 1;
	ll hi = k*n + 1; // highest element 
	ll ans = 1;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		ll dayTaken = totalDay(mid,1,v.size(),v,k);
		if(dayTaken>k){ // if days are greater then the given days the potential candidate is mid and we will search in the left portion
			ans = mid;
			hi = mid-1;
		} else{
			lo = mid + 1;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v;
		for(ll i=0;i<n;i++){
			ll x;
			cin>>x;
			v.emplace_back(x);
		}
		solve(v,v.size(),k);
	}
}