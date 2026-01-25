#include <bits/stdc++.h>
using namespace std;

int countDigit(int &n) {
        int count = 0;
        while(n!=0){
            count += 1;
            n = n/10;
        }
        return count;

        // // Another way of extracting digits
        // int count = (int)(log10(n)+1);      //log10(n) beacuse of 'n/10';
        // return count;
    }

int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
	    cout<<countDigit(n);
	}
	cout<<endl;

}
