#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
    cin>>s;

	// Precompute
	// int hash[100001];  //If max ele is 10 power 5
	int hash[26] = {0};
	for(int i=0;i<s.size();i++){
		hash[s[i]-'a'] += 1;
	}

	int q;
	cin>>q;
	while(q--){
		char c;
		cin>>c;
		// fetch
		cout<<hash[c-'a']<<endl;
	}

	return 0;
}