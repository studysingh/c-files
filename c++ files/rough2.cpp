#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int max_ele(vector<int> v){
	int max_ele=v[0];
	int n=v.size();
	for(int i=0;i<n;i++){
		max_ele=max(max_ele,v[i]);
	}
	return max_ele;
}
void f(vector<int> v, int i=0){
	if(v.size()==2){
		int element=abs(v[0]-v[1]);
	}
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			v.push_back(i+1);
		}
		}
	return 0;
}