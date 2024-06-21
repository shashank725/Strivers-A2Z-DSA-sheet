#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if(x<0 ||  x>INT_MAX) return false;
    int rev = 0;
    int temp = x;
    while(temp) {
        if(rev>INT_MAX/10) return false;
        rev = (rev*10) + (temp%10);
        temp = temp/10;
    }
    if(rev==x) return true;
        return false;
}


int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
	    cout<<isPalindrome(n);
	}
	cout<<endl;

}