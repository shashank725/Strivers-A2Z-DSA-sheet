#include <bits/stdc++.h>
using namespace std;

bool stringPalindrome(int i, string  &s) {
	if(i>=s.size()) return true;
	if(s[i] != s[s.size()-1-i]) return false;
	return stringPalindrome(i+1, s);
}

int main() {
    int t;
	cin>>t;
	while(t--) {
        string n = "madam";
		// cin>>n;
		cout<<stringPalindrome(0, n);
	}
	cout<<endl;
}