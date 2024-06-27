#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	// for(auto it:arr) cin>>arr[it];

// Precompute
	// Using array
	// int hash[100001];  //If max ele is 10 power 5
	// int hash[13] = {0};   //Max 12 ele
	// for(int i=0;i<n;i++){
	// 	hash[arr[i]] += 1;
	// }

	// Using map
	map<int, int> mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}
	for(auto it:mpp) cout<<it.first<<":"<<it.second<<" ";
	cout<<endl;


	int num;
	cin>>num;
// fetch
	// Using array
	// cout<<hash[num]<<endl;

	// Using map
	cout<<mpp[num]<<endl;

	return 0;
}